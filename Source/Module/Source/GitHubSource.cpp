GitHubUserSource::GitHubUserSource (const juce::String& usernameToScan,
                                    const SubresourceType subresourceType) :
    username (usernameToScan.trim()),
    type (subresourceType)
{
    jassert (username.isNotEmpty());
    jassert (type != numTypes);
}

juce::String GitHubUserSource::getWebsiteAddress() const
{
    if (username.isEmpty())
        return juce::String::empty;

    juce::String url ("https://api.github.com/users/" + username);

    switch (type)
    {
        case RepositoriesOwnerOnly:
        case RepositoriesMemberOnly:
        case AllRepositories:
            url << "/repos";
        break;

        default:
        break;
    };

    switch (type)
    {
        case RepositoriesOwnerOnly:     url << "?type=owner"; break;
        case RepositoriesMemberOnly:    url << "?type=member"; break;
        case AllRepositories:           url << "?type=all"; break;

        default:
        break;
    };

    return url;
}

//==============================================================================