#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
    {
        addAndMakeVisible(
            driveSlider);
    
        driveSlider.setSliderStyle(
            juce::Slider
                ::RotaryHorizontalVerticalDrag);
    
        driveSlider.setTextBoxStyle(
            juce::Slider
                ::TextBoxBelow,
            false,
            60,
            20);
    
        driveAttachment =
            std::make_unique<
                SliderAttachment>(
                processorRef.apvts,
                "drive",
                driveSlider);
    
        setSize(500, 500);
    }
AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    // g.setSize(700,700);
    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void AudioPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    driveSlider.setBounds(
            100,
            40,
            100,
            100);
}
