SoundCloudArtistSource::SoundCloudArtistSource (const juce::String& artistName,
                                                const SubresourceType subresourceType) :
        artist (artistName.trim()),
        type (subresourceType)
{
    jassert (artist.isNotEmpty());
}

//==============================================================================
juce::String SoundCloudArtistSource::getWebsiteAddress() const
{
    if (artist.isEmpty())
        return juce::String::empty;

    juce::String url ("http://api.soundcloud.com/users/" + artist);

    switch (type)
    {
        case Artist:        return url + ".json";
        case Tracks:        return url + "/tracks.json";
        case Playlist:      return url + "/playlists.json";
        case Followings:    return url + "/followings.json";
        case Followers:     return url + "/followers.json";
        case Comments:      return url + "/comments.json";
        case Favourites:    return url + "/favorites.json"; //URL must use EN-US spelling
        case Groups:        return url + "/groups.json";
        case WebProfiles:   return url + "/web-profiles.json";

        default:
        break;
    };

    jassertfalse; //New or incorrect type?
    return url + ".json";
}