/*
  ==============================================================================

	This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
UtilAudioProcessorEditor::UtilAudioProcessorEditor(UtilAudioProcessor& p)
	: AudioProcessorEditor(&p), audioProcessor(p)
{
	// Make sure that before the constructor has finished, you've set the
	// editor's size to whatever you need it to be.
	setSize(400, 600);

	// gain slider style
	gainSlider.setSliderStyle(juce::Slider::LinearBarVertical);
	gainSlider.setRange(-60.0, 0.0, 0.10);
	//gainSlider.setRange(0.0, 100.0, 1.0);
	gainSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
	gainSlider.setPopupDisplayEnabled(true, false, this);
	gainSlider.setTextValueSuffix(" Volume");
	gainSlider.setValue(-15.0);
	gainSlider.setSkewFactorFromMidPoint(-15.0);

	addAndMakeVisible(&gainSlider); // attach slider to editor
	gainSlider.addListener(this);
}

UtilAudioProcessorEditor::~UtilAudioProcessorEditor()
{
}

//==============================================================================
void UtilAudioProcessorEditor::paint(juce::Graphics& g)
{
	// (Our component is opaque, so we must completely fill the background with a solid colour)
	g.fillAll(juce::Colours::white);

	g.setColour(juce::Colours::black);
	g.setFont(15.0f);
	g.drawFittedText("Util0.0", getLocalBounds(), juce::Justification::centred, 1);
}

void UtilAudioProcessorEditor::resized()
{
	gainSlider.setBounds(40, 30, 20, getHeight() - 60);
	// This is generally where you'll want to lay out the positions of any
	// subcomponents in your editor..
}

void UtilAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
	audioProcessor.gain = gainSlider.getValue();
	//audioProcessor.gain = audioProcessor.gain / 100.0;
	audioProcessor.gain = pow(10.0, (audioProcessor.gain / 20.0));
}