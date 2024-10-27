#include "ReactJuceGUIApplication/AudioLevelProcessor.h"

namespace juce_gui_application_processor
{

AudioLevelProcessor::AudioLevelProcessor ()
{
    multiChannelBuffer.setSize (4, 512); // Default buffer size for four channels
}

void AudioLevelProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    multiChannelBuffer.setSize (4, samplesPerBlock);
    juce::AudioProcessor::setRateAndBufferSizeDetails (sampleRate, samplesPerBlock);
}

void AudioLevelProcessor::processBlock (juce::AudioBuffer<float> & buffer, juce::MidiBuffer &)
{
    // Generate random samples for each channel
    for (int channel = 0; channel < buffer.getNumChannels (); ++channel)
    {
        auto * channelData = buffer.getWritePointer (channel);
        for (int sample = 0; sample < buffer.getNumSamples (); ++sample)
        {
            channelData [sample] = juce::Random::getSystemRandom ().nextFloat () * 2.0f - 1.0f;
        }
    }

    // Copy buffer into multiChannelBuffer for level calculation
    multiChannelBuffer.makeCopyOf (buffer);
}

std::vector<float> AudioLevelProcessor::getChannelLevels ()
{
    std::vector<float> levels (4, 0.0f);

    for (int channel = 0; channel < 4; ++channel)
    {
        levels [channel] = juce::Decibels::gainToDecibels (
            multiChannelBuffer.getRMSLevel (channel, 0, multiChannelBuffer.getNumSamples ()));
    }
    return levels;
}
}