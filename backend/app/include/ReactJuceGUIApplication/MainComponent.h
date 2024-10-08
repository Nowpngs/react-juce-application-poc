#pragma once

// CMake builds don't use an AppConfig.h, so it's safe to include juce module headers
// directly. If you need to remain compatible with Projucer-generated builds, and
// have called `juce_generate_juce_header(<thisTarget>)` in your CMakeLists.txt,
// you could `#include <JuceHeader.h>` here instead, to make all your module headers visible.
#include <JuceHeader.h>
#include <juce_gui_extra/juce_gui_extra.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
namespace juce_gui_application
{
class MainComponent final : public juce::Component
{
public:
    //==============================================================================
    MainComponent ();

    //==============================================================================
    void resized () override;

private:
    //==============================================================================
    // Your private member variables go here...
    std::optional<juce::WebBrowserComponent::Resource> getResource (const juce::String & url);
    std::optional<juce::WebBrowserComponent::Resource> createExampleResource ();

    juce::WebBrowserComponent webView;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
}