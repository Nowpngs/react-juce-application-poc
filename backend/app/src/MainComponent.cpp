#include "ReactJuceGUIApplication/MainComponent.h"

//==============================================================================
MainComponent::MainComponent ()
    : webView (juce::WebBrowserComponent::Options ())
{
    addAndMakeVisible (webView);
    webView.goToURL ("https://www.juce.com");

    setSize (600, 400);
}

//==============================================================================

void MainComponent::resized ()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    webView.setBounds (getLocalBounds ());
}
