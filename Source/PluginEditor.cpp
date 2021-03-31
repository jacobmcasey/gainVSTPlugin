/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainTutorialAudioProcessorEditor::GainTutorialAudioProcessorEditor (GainTutorialAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    mSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    mSlider.setRange(0.0f, 1.0f, 0.01f);
    mSlider.setValue(0.5f);
    addAndMakeVisible(mSlider);

    mSlider.addListener(this);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

GainTutorialAudioProcessorEditor::~GainTutorialAudioProcessorEditor()
{
}

//==============================================================================
void GainTutorialAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::black);
}

void GainTutorialAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    mSlider.setBounds (0, 0, 100, 150);
}

//Implement the gain slider- listening for user to make changed in the slider(mGain)
void GainTutorialAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &mSlider)
    {
        audioProcessor.mGain = mSlider.getValue();
    }

}