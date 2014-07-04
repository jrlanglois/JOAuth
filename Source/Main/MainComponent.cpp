#include "MainComponent.h"

MainContentComponent::MainContentComponent()
{
    setSize (500, 400);

    joauth::OAuth1Client v1Client;
    joauth::OAuth1aClient v1aClient;
    joauth::OAuth2Client v2Client;
}

//==============================================================================
void MainContentComponent::paint (juce::Graphics&)
{
}

void MainContentComponent::resized()
{
}