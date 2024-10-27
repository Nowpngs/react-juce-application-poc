#pragma once

#include <JuceHeader.h>

namespace juce_gui_application_processor
{

class AudioLevelProcessor : public juce::AudioProcessor
{
public:
    AudioLevelProcessor ();

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void processBlock (juce::AudioBuffer<float> & buffer, juce::MidiBuffer & midiMessages) override;

    std::vector<float> getChannelLevels ();

private:
    juce::AudioBuffer<float> multiChannelBuffer;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioLevelProcessor)
};
}