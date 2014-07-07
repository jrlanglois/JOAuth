#include "OAuth2Client.h"

//==============================================================================
OAuth2Client::AccessToken::AccessToken (const juce::String& clientId,
                                        const juce::String& clientSecret) :
    id (clientId.trim()),
    secret (clientSecret.trim())
{
    jassert (id.isNotEmpty()); //RTFM!
}

OAuth2Client::AccessToken::AccessToken (const juce::String& clientId,
                                        const juce::String& clientSecret,
                                        const juce::String& clientUsername,
                                        const juce::String& clientPassword) :
    id (clientId.trim()),
    secret (clientSecret.trim()),
    username (clientUsername.trim()),
    password (clientPassword.trim())
{
    jassert (id.isNotEmpty()); //RTFM!
    jassert (username.isEmpty() == password.isEmpty()); //Usernames usually have passwords associated to them, right?
}

//==============================================================================
OAuth2Client::OAuth2Client (const AccessToken& newAccessToken) :
    accessToken (newAccessToken)
{
    jassert (accessToken.id.isNotEmpty());
}

//==============================================================================
juce::var OAuth2Client::parse (const OAuthSource& source)
{
    if (accessToken.id.isEmpty())
        return juce::var::null;

    juce::String address (source.getWebsiteAddress().trim());

    if (address.isEmpty())
    {
        jassertfalse;
        return juce::var::null;
    }

    address << "?client_id=" << accessToken.id;
    address << "&client_secret=" << accessToken.secret;

/*
    if ()
        address << "&client_secret=" << accessToken->username;
*/

    const juce::URL url (address);

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