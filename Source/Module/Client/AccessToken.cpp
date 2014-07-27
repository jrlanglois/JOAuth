AccessToken::AccessToken (const juce::String& clientId,
                          const juce::String& clientSecret) :
    id (clientId.trim()),
    secret (clientSecret.trim())
{
    jassert (id.isNotEmpty()); //RTFM!
}

AccessToken::AccessToken (const juce::String& clientId,
                          const juce::String& clientSecret,
                          const juce::String& clientUsername,
                          const juce::String& clientPassword) :
    id (clientId.trim()),
    secret (clientSecret.trim()),
    username (clientUsername.trim()),
    password (clientPassword.trim())
{
    jassert (id.isNotEmpty()); //RTFM!
    jassert (username.isEmpty() == password.isEmpty()); //Who the hell would have no password with their username?
}