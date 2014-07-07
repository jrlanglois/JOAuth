#ifndef JOAUTH_SOUNDCLOUD_SOURCE_H
#define JOAUTH_SOUNDCLOUD_SOURCE_H

class SoundCloudArtistSource : public OAuthSource
{
public:
    /** */
    enum SubresourceType
    {
        Artist = 0,
        Tracks,
        Playlist,
        Followings,
        Followers,
        Comments,
        Favourites,
        Groups,
        WebProfiles,

        numTypes
    };

    /** Constructor

        @param[in] artistName
        @param[in] subresourceType
    */
    SoundCloudArtistSource (const juce::String& artistName,
                            SubresourceType subresourceType);

    //==============================================================================
    /** @internal */
    juce::String getWebsiteAddress() const override;

private:
    //==============================================================================
    const juce::String artist;
    const SubresourceType type;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SoundCloudArtistSource)
};

#endif //JOAUTH_SOUNDCLOUD_SOURCE_H