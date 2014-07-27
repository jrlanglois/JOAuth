#ifndef JOAUTH_ACCESS_TOKEN_H
#define JOAUTH_ACCESS_TOKEN_H

/** @file AccessToken.h

    A class representing the criterion of hand-shaking via OAuth

    @see https://tools.ietf.org/html/rfc6749
*/
class AccessToken
{
public:
    /** Constructor

        @param[in] id       The client identification tag. This is a mandatory field.
        @param[in] secret   The client secret. This is a mandatory field, but may be empty.
    */
    AccessToken (const juce::String& id,
                 const juce::String& secret);

    /** Constructor

        @param[in] id       The client identification tag. This is a mandatory field.
        @param[in] secret   The client secret. This is a mandatory field, but may be empty.
        @param[in] username A username.
        @param[in] password The password associated to the username.
    */
    AccessToken (const juce::String& id,
                 const juce::String& secret,
                 const juce::String& username,
                 const juce::String& password);

    //==============================================================================
    /** The client identification tag, as issued by the authorisation server.

        This is a unique string to the authorisation server,
        representing the registration information provided by the client.

        The client identifier is not a secret; it is exposed to the
        resource owner, and MUST NOT be used alone for client authentication.

        The client identifier string size is left undefined by this
        specification. The client should avoid making assumptions about the
        identifier size. The authorisation server should have documented the size
        of any identifier it issues.

        @warning This is a mandatory field. If made empty, the access token is rendered invalid!
    */
    const juce::String id;

    /** The client secret.

        You may omit the parameter if the client secret is an empty string.
    */
    const juce::String secret;

    /**

    */
    const juce::String username;

    /**

    */
    const juce::String password;

private:
    AccessToken() JUCE_DELETED_FUNCTION;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AccessToken)
};

#endif //JOAUTH_ACCESS_TOKEN_H