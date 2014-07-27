#ifndef JOAUTH_OAUTH_2_CLIENT_H
#define JOAUTH_OAUTH_2_CLIENT_H

/** An OAuth 2.0 client implementation.

    @see OAuth1Client, OAuth1aClient
*/
class OAuth2Client
{
public:
    /** Constructor

        @param[in] accessToken
    */
    OAuth2Client (const AccessToken& accessToken);

    //==============================================================================
    /** Performs an HTML GET command with the OAuthSource's
        specified website address, and the AccessToken's information.

        @param[in] source
    */
    juce::var getJSON (const OAuthSource& source);

private:
    //==============================================================================
    const AccessToken& accessToken;

    //==============================================================================
    OAuth2Client() JUCE_DELETED_FUNCTION;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OAuth2Client)
};

#endif //JOAUTH_OAUTH_2_CLIENT_H