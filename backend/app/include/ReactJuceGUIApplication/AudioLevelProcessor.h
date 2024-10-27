#pragma once

#include <JuceHeader.h>

namespace juce_gui_application_processor
{

class AudioLevelProcessor : public juce::AudioProcessor
{
public:
    AudioLevelProcessor ();

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources () override;
    void processBlock (juce::AudioBuffer<float> & buffer, juce::MidiBuffer & midiMessages) override;

    std::vector<float> getChannelLevels ();

    //==============================================================================
    const juce::String getName () const override
    {
        return "AudioLevelProcessor";
    }
    bool acceptsMidi () const override
    {
        return false;
    }
    bool producesMidi () const override
    {
        return false;
    }
    double getTailLengthSeconds () const override
    {
        return 0.0;
    }

    int getNumPrograms () override
    {
        return 1;
    } // You can adjust the number of programs as needed
    int getCurrentProgram () override
    {
        return 0;
    }
    void setCurrentProgram (int index) override
    {
        (void) index;
    }
    const juce::String getProgramName (int index) override
    {
        (void) index;
        return {};
    }
    void changeProgramName (int index, const juce::String & newName) override
    {
        (void) index;
        (void) newName;
    }
    void getStateInformation (juce::MemoryBlock & destData) override
    {
        (void) destData;
    }
    void setStateInformation (const void * data, int sizeInBytes) override
    {
        (void) data;
        (void) sizeInBytes;
    }

    AudioProcessorEditor * createEditor () override
    {
        return nullptr;
    }
    bool hasEditor () const override
    {
        return false;
    }

private:
    juce::AudioBuffer<float> multiChannelBuffer;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioLevelProcessor)
};
}