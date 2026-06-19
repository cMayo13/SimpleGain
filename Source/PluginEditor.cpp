/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SimpleGainAudioProcessorEditor::SimpleGainAudioProcessorEditor (SimpleGainAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), gainAttachment (audioProcessor.apvts, "GAIN", gainSlider),
      bypassAttachment(audioProcessor.apvts, "BYPASS", bypassButton)
{
    addAndMakeVisible(gainSlider);
    addAndMakeVisible(bypassButton);
    bypassButton.setButtonText("Bypass");
    setSize (400, 300);
    
}

SimpleGainAudioProcessorEditor::~SimpleGainAudioProcessorEditor()
{
}

//==============================================================================
void SimpleGainAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (15.0f));
    g.drawFittedText ("GAIN (dB):", getLocalBounds(), juce::Justification::centred, 1);
}

void SimpleGainAudioProcessorEditor::resized()
{
    gainSlider.setBounds(100, 100, 200, 150);
    bypassButton.setBounds(160, 225, 120, 24);
}
