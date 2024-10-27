#include "ReactJuceGUIApplication/MainComponent.h"

#include "ReactJuceGUIApplication/Util.h"

using namespace juce_gui_application_util;

namespace juce_gui_application
{
//==============================================================================
MainComponent::MainComponent ()
    : webView (juce::WebBrowserComponent::Options ().withResourceProvider (
          [this] (const auto & url) { return getResource (url); }))
    , audioProcessor ()
{
    addAndMakeVisible (webView);
    webView.goToURL (webView.getResourceProviderRoot ());

    setSize (600, 400);

    startTimer (60);
}

//==============================================================================

void MainComponent::resized ()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    webView.setBounds (getLocalBounds ());
}

void MainComponent::timerCallback ()
{
    // This is called by the timer.
    // You can use this to update the UI and perform other tasks.
    auto levels = audioProcessor.getChannelLevels ();

    // Convert std::vector<float> to juce::Array<juce::var>
    juce::Array<juce::var> levelVars;
    for (const auto & level : levels)
    {
        levelVars.add (level);
    }

    // Emit the event with the converted array
    webView.emitEventIfBrowserIsVisible ("audioLevels", levelVars);
}

std::optional<juce::WebBrowserComponent::Resource>
MainComponent::getResource (const juce::String & url)
{
    // This is called when the WebBrowserComponent needs to load a URL.
    // You can return a Resource object to load the URL, or an empty
    // optional to let the WebBrowserComponent handle the request.
    const auto urlToRetrive =
        url == "/" ? juce::String {"index.html"} : url.fromFirstOccurrenceOf ("/", false, false);

    if (urlToRetrive == "exampleResource")
    {
        return createExampleResource ();
    }

    if (auto * archive = juce_gui_application_util::getBuildZipFile ())
    {
        if (auto * entry = archive->getEntry (urlToRetrive))
        {
            auto stream = rawToUniquePtr (archive->createStreamForEntry (*entry));
            auto vector = streamToVector (*stream);
            auto mime = getMimeForExtension (getExtension (entry->filename).toLowerCase ());
            return juce::WebBrowserComponent::Resource {std::move (vector), std::move (mime)};
        }
    }

    return std::nullopt;
}

std::optional<juce::WebBrowserComponent::Resource> MainComponent::createExampleResource ()
{
    juce::DynamicObject::Ptr data (new juce::DynamicObject ());
    data->setProperty ("exampleProperty", 42);
    const juce::String json = juce::JSON::toString (data.get ());

    juce::MemoryInputStream stream (json.getCharPointer (), json.getNumBytesAsUTF8 (), false);
    return juce::WebBrowserComponent::Resource {streamToVector (stream), "application/json"};
}
}