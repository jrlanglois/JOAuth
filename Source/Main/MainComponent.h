#ifndef MAIN_COMPONENT_H
#define MAIN_COMPONENT_H

#include "../Module/JOAuth.h"

class MainComponent : public juce::Component
{
public:
    /** Constructor */
    MainComponent();

    //==============================================================================
    /** @internal */
    void paint (juce::Graphics& g) override;
    /** @internal */
    void resized() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

#endif //MAIN_COMPONENT_H