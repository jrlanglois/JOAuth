#include "OAuth2Client.h"

OAuth2Client::OAuth2Client (const AccessToken& newAccessToken) :
    accessToken (newAccessToken)
{
    jassert (accessToken.id.isNotEmpty());
}

//==============================================================================
juce::var OAuth2Client::getJSON (const OAuthSource& source)
{
    if (accessToken.id.isEmpty())
        return juce::var::null;

    juce::URL url (source.getWebsiteAddress().trim());

    if (! url.isWellFormed())
    {
        jassertfalse;
        return juce::var::null;
    }

    url = url.withParameter ("client_id", accessToken.id)
             .withParameter ("client_secret", accessToken.secret);

    if (accessToken.username.isNotEmpty()
        && accessToken.password.isNotEmpty())
    {
        url = url.withParameter ("username", accessToken.username)
                 .withParameter ("password", accessToken.password);
    }

    if (! url.isWellFormed())
    {
        jassertfalse;
        return juce::var::null;
    }

    const juce::String textStream (url.readEntireTextStream().trim());

    if (textStream.isEmpty()
        || (textStream.containsIgnoreCase ("errors")
            && textStream.containsIgnoreCase ("error_message")))
    {
        jassertfalse;
        return juce::var::null;
    }

    juce::var result (juce::JSON::parse (textStream));

    jassert (result != juce::var::null);
    jassert (! result.isUndefined() && ! result.isVoid());

    return result;
}