#ifndef JOAUTH_OAUTH_2_CLIENT_H
#define JOAUTH_OAUTH_2_CLIENT_H

/**
    An OAuth 2.0 client implementation.

    @see OAuth1Client, OAuth1aClient
*/
class OAuth2Client
{
public:
    /** Constructor */
    OAuth2Client();

    /** Destructor */
    ~OAuth2Client();

    //==============================================================================
    class AccessToken
    {
        AccessToken (const juce::String& id,
                     const juce::String& secret) :
            clientId (id),
            clientSecret (secret)
        {
        }

        juce::String clientId;
        juce::String clientSecret;

    private:
        AccessToken() JUCE_DELETED_FUNCTION;
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AccessToken)
    };

    //==============================================================================
    juce::var parse (AccessToken* accessToken);

private:
    //==============================================================================
    juce::ScopedPointer<AccessToken> accessToken;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OAuth2Client)
};

#endif //JOAUTH_OAUTH_2_CLIENT_H