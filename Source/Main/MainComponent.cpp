#include "MainComponent.h"

MainContentComponent::MainContentComponent()
{
    setSize (500, 400);

    joauth::OAuth2Client client;
}

//==============================================================================
void MainContentComponent::paint (juce::Graphics&)
{
}

void MainContentComponent::resized()
{
}