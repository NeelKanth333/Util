/*
  ==============================================================================

	This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class UtilAudioProcessorEditor : public juce::AudioProcessorEditor,
	private juce::Slider::Listener
{
public:
	UtilAudioProcessorEditor(UtilAudioProcessor&);
	~UtilAudioProcessorEditor() override;

	//==============================================================================
	void paint(juce::Graphics&) override;
	void resized() override;

private:

	void sliderValueChanged(juce::Slider* slider) override;

	// This reference is provided as a quick way for your editor to
	// access the processor object that created it.
	UtilAudioProcessor& audioProcessor;
	juce::Slider gainSlider;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UtilAudioProcessorEditor)
};
