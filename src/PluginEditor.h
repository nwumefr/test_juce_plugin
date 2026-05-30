#pragma once

#include "PluginProcessor.h"
#include "DistSliderComponent.h"
//==============================================================================
class AudioPluginAudioProcessorEditor final : public juce::AudioProcessorEditor
{
public:
    explicit AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor&);
    ~AudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    AudioPluginAudioProcessor&
        processorRef;

    juce::Slider driveSlider;

    using SliderAttachment =
        juce::AudioProcessorValueTreeState
            ::SliderAttachment;

    std::unique_ptr<
        SliderAttachment>
            driveAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(
        AudioPluginAudioProcessorEditor)
};
