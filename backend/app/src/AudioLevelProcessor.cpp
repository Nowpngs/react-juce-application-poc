#include "ReactJuceGUIApplication/AudioLevelProcessor.h"

namespace juce_gui_application_processor
{

AudioLevelProcessor::AudioLevelProcessor ()
{
    multiChannelBuffer.setSize (4, 512); // Default buffer size for four channels
}

void AudioLevelProcessor::releaseResources ()
{
    // Release any resources allocated in prepareToPlay
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
        float smoothingFactor = 0.9f;

        for (int sample = 0; sample < buffer.getNumSamples (); ++sample)
        {
            float randomValue = (juce::Random::getSystemRandom().nextFloat() * 0.4f - 0.2f);
            channelData[sample] = smoothingFactor * channelData[sample] + (1.0f - smoothingFactor) * randomValue;
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