#ifndef JOAUTH_OAUTH_SOURCE_H
#define JOAUTH_OAUTH_SOURCE_H

/**
    @file OAuthSource.h

    A base class for online sources of OAuth implementations.

    @see DropboxSource, GitHubSource, SoundCloudSource, TwitterSource
*/
class OAuthSource
{
public:
    /** Constructor */
    OAuthSource() { }

    /** Destructor */
    virtual ~OAuthSource() { }

    //==============================================================================
    /** */
    virtual juce::String getWebsiteAddress() const = 0;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OAuthSource)
};

#endif //JOAUTH_OAUTH_SOURCE_H