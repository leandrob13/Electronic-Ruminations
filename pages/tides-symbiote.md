<!--
.. title: Tides Symbiote
.. slug: tides-symbiote
.. date: 2024-07-20 15:34:34 UTC-05:00
.. tags: 
.. category: 
.. link: 
.. description: 
.. type: text
-->

Tides Symbiote firmware includes a new mode that has four modulation options:

- Lorenz and Rossler chaotic attractors.
- Thomas and Chua chaotic attractors.
- Poly LFO ported from [Mutable Instruments Frames](https://pichenettes.github.io/mutable-instruments-documentation/modules/frames/secrets/) easter egg mode.
- Wavetable Oscillator ported from [Mutable Instruments Plaits](https://pichenettes.github.io/mutable-instruments-documentation/modules/plaits/manual/).

The attractors in audio rate modulation can be used as noise oscillators while the other two modes can be used as regular oscillators with 1V/oct tracking.

Here is a demo overview of the new modulators:

&nbsp;

<p align="center"><iframe width="560" height="315" src="https://www.youtube.com/embed/FZFHOwKZnD8" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe></p>

## Contents

- [Installation](#installation)
- [Interface](#interface)
- [Attractors](#attractors)
- [Poly LFO](#poly-lfo)
- [Wavetable Oscillator](#wavetable-oscillator)
- [Parameters](#parameters)
- [Change Log](#change-log)

## Installation

Download the firmware `.wav` file [version 0.1.0](https://github.com/leandrob13/eurorack/releases/tag/v0.2.0) and follow the usual update procedure stated in the [Mutable Instruments Tides manual](https://pichenettes.github.io/mutable-instruments-documentation/modules/tides_2018/manual/).

## Interface

To get to the new mode, press the `Ramp Mode` button until is unlit. Once in that mode, the `Output Mode` button selects the new modulators:

- Unlit mode: Lorenz and Rossler attractors.
- Green mode: Thomas and Chua chaotic attractors.
- Yellow mode: Poly LFO.
- Red Mode: Wavetable Oscillator.

The `Frequency Range` button works the same as the frequency range selection from the other modes, being red the audio rate option.

The rest of the interface knobs and cv inputs functions will depend on the specific modes.

### Attractors

Implements the chaotic attractors found in other alternative firmwares (streams, stages qiemem).

### Poly LFO

A ported version from Mutable Instruments Frames that can track 1V/oct, has oscillator sync, fm and can be clocked. Giving you 4 lfo/oscillator outputs that can be phase shifted, morphed and even frequency modulated between each other.

### Wavetable Oscillator

Ported from Mutable Instruments Plaits, the wavetable oscillator has oscillator sync, fm and can be clocked. It can also be used as a wavetable LFO and smoothly morphs between each bank.

## Parameters

| Output Mode | Frequency Knob/CV             |         Shape Knob/CV          |      Slope Knob/CV      |             Smoothness Knob/CV              |         Shift/Level Knob/CV          |                    Trigger Input                    |             Clock Input             |                            Outputs                             |
|:-----------:|-------------------------------|:------------------------------:|:-----------------------:|:-------------------------------------------:|:------------------------------------:|:---------------------------------------------------:|:-----------------------------------:|:--------------------------------------------------------------:|
|    Unlit    | Frequency of Lorenz attractor | Frequency of Rossler attractor | Lorenz parameter change |          Rossler parameter change           |      Output level of attractors      |              Reset of Lorenz attractor              |     Reset of Rossler attractor      |                  1 & 2 Lorenz, 3 & 4 Rossler                   |
|    Green    | Frequency of Thomas attractor |  Frequency of Chua attractor   | Thomas parameter change |            Chua parameter change            |      Output level of attractors      |              Reset of Thomas attractor              |       Reset of Chua attractor       |                    1 & 2 Thomas, 3 & 4 Chua                    |
|   Yellow    | Main frequency/clocked ratio  |      Main waveform shape       |      Shape spread       | Frequency/Phase spread relative to output 1 | Phase modulation between each output | Resets the phase of all the outputs/oscillator sync | Clocks the frequency of the outputs |                  1 main output, 2-4 followers                  |
|     Red     | Main frequency/clocked ratio  |         Wavetable bank         |   Wavetable x column    |              Filter/Wavefoder               |          Wavetable y column          | Resets the phase of all the outputs/oscillator sync | Clocks the frequency of the outputs | 1: bipolar, 2: unipolar, 3: wavefolded sine, 4: bipolar square |

## Change Log

### Symbiote 0.1.0

New features:

- Lorenz and Rossler chaotic attractors with reset inputs and amplitude control.
- Thomas and Chua chaotic attractors with reset inputs and amplitude control.
- Poly LFO ported with 1V/oct tracking, fm, sync and clock.
- Wavetable LFO/Oscillator with 1V/oct tracking, fm, sync and clock.

