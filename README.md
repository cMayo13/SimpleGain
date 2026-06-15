# SimpleGain

A simple gain plugin, made by Charlie Mayo as a introduction to plugin-making with the JUCE framework.

## Features

- Gain control (uses an atomic `ThreadSafeParam` class to hold the gain parameter)
- Parameter smoothing to kill zipper noise (using `juce::SmoothedValue`)
- Gain slider has db-accurate gain scaling 

## Build

- Built with Projucer + Xcode

## Status

- Currently a work in progress. `gainSlider`'s skew factor and `SmoothedValue`'s ramp time will be tweaked further. APVTs will also be added later. 
