#include "MainComponent.h"

MainContentComponent::MainContentComponent()
{
    setSize (500, 400);

    OAuth1Client v1Client;
    OAuth1aClient v1aClient;

    const OAuth2Client::AccessToken accessToken ("207c0e8614fddf3878b849631b7156ba",
                                                 "48dee940c3063fc879358b113cbc8242");

    OAuth2Client v2Client (accessToken);
    const SoundCloudArtistSource scas ("jrlanglois", SoundCloudArtistSource::Artist);

    juce::var result (v2Client.parse (scas)); 
}

//==============================================================================
void MainContentComponent::paint (juce::Graphics&)
{
}

void MainContentComponent::resized()
{
}