#include <JuceHeader.h>

namespace juce_gui_application_util
{
enum class AssertAssetExists
{
    no,
    yes
};

static std::unique_ptr<juce::InputStream>
createResourceInputStream (const char * resourcePath,
                           [[maybe_unused]] AssertAssetExists assertExists = AssertAssetExists::yes)
{
    auto resourceDir = juce::File::getSpecialLocation (juce::File::currentExecutableFile)
                           .getParentDirectory ()
                           .getParentDirectory ()
                           .getChildFile ("Resources");

    auto resourceFile = resourceDir.getChildFile (resourcePath);

    if (! resourceFile.existsAsFile ())
    {
        jassert (assertExists == AssertAssetExists::no);
        return {};
    }
    return resourceFile.createInputStream ();
}

static juce::ZipFile * getBuildZipFile ()
{
    static auto stream = createResourceInputStream ("frontend_0.1.0.zip", AssertAssetExists::no);

    if (stream == nullptr)
        return nullptr;

    static juce::ZipFile buildZipFile {stream.get (), false};
    return &buildZipFile;
}

static auto streamToVector (juce::InputStream & stream)
{
    std::vector<std::byte> result (static_cast<size_t> (stream.getTotalLength ()));
    stream.setPosition (0);
    [[maybe_unused]] const auto bytesRead = stream.read (result.data (), result.size ());
    jassert (bytesRead == static_cast<ssize_t> (result.size ()));
    return result;
}

static juce::String getExtension (juce::String filename)
{
    return filename.fromLastOccurrenceOf (".", false, false);
}

static const char * getMimeForExtension (const juce::String & extension)
{
    static const std::unordered_map<juce::String, const char *> mimeMap = {
        {{"htm"}, "text/html"},
        {{"html"}, "text/html"},
        {{"txt"}, "text/plain"},
        {{"jpg"}, "image/jpeg"},
        {{"jpeg"}, "image/jpeg"},
        {{"svg"}, "image/svg+xml"},
        {{"ico"}, "image/vnd.microsoft.icon"},
        {{"json"}, "application/json"},
        {{"png"}, "image/png"},
        {{"css"}, "text/css"},
        {{"map"}, "application/json"},
        {{"js"}, "text/javascript"},
        {{"woff2"}, "font/woff2"}};

    if (const auto it = mimeMap.find (extension.toLowerCase ()); it != mimeMap.end ())
        return it->second;

    jassertfalse;
    return "";
}
}
