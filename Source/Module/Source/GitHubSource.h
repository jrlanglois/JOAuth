#ifndef JOAUTH_GITHUB_SOURCE_H
#define JOAUTH_GITHUB_SOURCE_H

/**

    @see https://developer.github.com/v3/oauth/
    @see https://developer.github.com/v3/oauth_authorizations/#create-a-new-authorization
*/
class GitHubUserSource : public OAuthSource
{
public:
    /** */
    enum SubresourceType
    {
        UserInformation = 0,
        RepositoriesOwnerOnly,
        RepositoriesMemberOnly,
        AllRepositories,

        numTypes
    };

    /** Constructor

        @param[in] username
        @param[in] subresourceType
    */
    GitHubUserSource (const juce::String& username,
                      SubresourceType subresourceType);

    //==============================================================================
    /** @internal */
    juce::String getWebsiteAddress() const override;

private:
    //==============================================================================
    const juce::String username;
    const SubresourceType type;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GitHubUserSource)
};


#endif //JOAUTH_GITHUB_SOURCE_H