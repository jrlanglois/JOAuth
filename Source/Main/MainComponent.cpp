#include "MainComponent.h"

MainComponent::MainComponent()
{
    setSize (500, 400);

    {
        OAuth1Client v1Client;
    }

    {
        OAuth1aClient v1aClient;
    }

    {
       #if 1
        const AccessToken accessToken ("d1b5786b189e458ca744",
                                       "a1148a114bf48ac984c4bc62839b1174a0e83fac");

        const GitHubUserSource source ("jrlanglois", GitHubUserSource::RepositoriesMemberOnly);
       #else
        const AccessToken accessToken ("207c0e8614fddf3878b849631b7156ba",
                                       "48dee940c3063fc879358b113cbc8242");

        const SoundCloudArtistSource source ("jrlanglois", SoundCloudArtistSource::Artist);
       #endif

        juce::var result (OAuth2Client (accessToken).getJSON (source));
    }
}

//==============================================================================
void MainComponent::paint (juce::Graphics&)
{
}

void MainComponent::resized()
{
}