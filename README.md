# SimpleGain

A simple gain plugin, made by Charlie Mayo as a introduction to plugin-making with the JUCE framework.

## Features

- Gain control (-60 dB to +6 dB) with dB-accurate scaling
- Parameters managed by `juce::AudioProcessorValueTreeState` (APVTS)
- Gain slider bound to the parameter via a two-way `SliderAttachment`
- Parameter smoothing to kill zipper noise (`juce::SmoothedValue`, 0.10s ramp)
- Skewed gain slider (skew 4.0, quite heavy) so most of the travel covers
  near-unity range, tuned to my liking for adjusting gain on guitar/bass tracks
- Bypass parameter
- State save/load: plugin remembers its settings when you save and reopen
  a project (APVTS state serialized to XML) 

## Build

- Built with Projucer + Xcode
- Formats: VST3, AU, Standalone

## Status

Works well. Tested in Ableton Live 11 with a guitar through an audio interface. I still need to add a GUI knob for the bypass parameter.

## Ship-retro

- The bypass is a **hard bypass** — `processBlock` early-returns when bypass is
  on. This means toggling it clicks (the gain jumps discontinuously). The proper
  fix is a ramped/crossfaded bypass that fades over a few milliseconds; deferred
  as a future improvement.
- A long-term `jassert` in `processBlock` verifies my hand-derived
  `10^(dB/20)` gain formula against JUCE's `Decibels::decibelsToGain`. It's
  stripped from release builds, so it stays in as a permanent invariant
  documenting that the two agree. Clutters the code a bit but I liked having it there. 
