<!--
.. title: Warps Symbiote
.. slug: warps-symbiote
.. date: 2023-07-02 19:09:09 UTC-05:00
.. tags: mutable instruments, eurorack
.. category: music programming
.. link: 
.. description: 
.. type: text
-->

# Warps Symbiote

Warps Symbiote firmware is built on top of the [Warps Parasites firmware](https://mqtthiqs.github.io/parasites/warps.html) and is my attempt to bring new life to the Mutable Instruments clones available from other manufacturers, let's try to preserve such an important legacy. It adds three new algorithms:

- Ladder Filter: ported from an implementation of the [improved Moog Ladder Filter](https://github.com/ddiakopoulos/MoogLadders/blob/master/src/ImprovedModel.h)
- Dual State Variable Filter: implemented a dual filter based on Emillie's [State Variable Filter](https://github.com/pichenettes/stmlib/blob/e3bd7c9cc00e4364166f9905c0509b6ffd0535ec/dsp/filter.h#L177)
- Reverbs: added 4 reverbs based on the implementations found in Rings, Clouds and Elements.

Here is a demo overview of the new effects:

&nbsp;

<p align="center"><iframe width="560" height="315" src="https://www.youtube.com/embed/FZFHOwKZnD8" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe></p>

## Contents

- [Installation](#installation)
- [Interface](#interface)
- [Ladder Filter](#ladder-filter)
- [Dual State Variable Filter](#dual-state-variable-filter)
- [Reverbs](/posts/warps-symbiote#reverbs)
- [Parameters](#parameters)
- [Graphical Quick Reference](#graphical-quick-reference)
- [Change Log](#change-log)

## Installation

Download the firmware `.wav` file [version 0.2.0](https://github.com/leandrob13/eurorack/releases/tag/v0.2.0) and follow the usual update procedure stated in the [Mutable Instruments Warps manual](https://pichenettes.github.io/mutable-instruments-documentation/modules/warps/manual/).

## Interface

The interface of this firmware is the same as the one implemented in [Warps Parasites](https://mqtthiqs.github.io/parasites/warps.html#mode). From left to right, the algorithms are:

- Ladder Filter.
- Dual State Variable Filter.
- Reverbs.
- Chebyschev Waveshaper.
- Frequency Shifter.
- Bitcrusher.
- Vocoder.
- Delay.
- Meta

### Ladder Filter

A ported implementation of the Moog Ladder Filter model:

&nbsp;

This model is based on a reference implementation of an algorithm developed by Stefano D'Angelo and Vesa Valimaki, presented in a paper published at ICASSP in 2013. This improved model is based on a circuit analysis and compared against a reference Ngspice simulation. In the paper, it is noted that this particular model is more accurate in preserving the self-oscillating nature of the real filter.

&nbsp;

References: "An Improved Virtual Analog Model of the Moog Ladder Filter"
Original Implementation: D'Angelo, Valimaki

### Dual State Variable Filter

Two independent SVFs, arranged in default configurations. This is implemented using the code from [Mutable Instruments State Variable Filter](https://github.com/pichenettes/stmlib/blob/e3bd7c9cc00e4364166f9905c0509b6ffd0535ec/dsp/filter.h#L177). This filter drives the resonance up to distortion levels, sounding pretty close to an MS-20 filter model.
The Low Pass is a two pole filter while the Band Pass and High Pass are one pole.

### Reverbs

Compiled several Mutable Instruments reverbs implementation, based on their configurations in `Rings`, `Clouds` and `Elements` modules. Added control over parameters that were not available in the original implementations for an extra twist. Playing with the difussion knob is highly recommended.
The four available reverbs are:

- Caveman: found in `Rings` disastrous peace mode.
- Rings: found in the additional resonator model `KarplusVerb`.
- Clouds: close enough configuration based on the beloved reverb.
- Elements: close enough configuration with reverb freeze (timbre knob completely CW) and added input gain control for dramatic and cinematic effects.

## Parameters

| Algorithm             | Algorithm Knob/CV         | Timbre Knob/CV                    | Internal Oscillator Button                                                                        | Level 1 Knob                            | Level 2 Knob                          | Level 1&2 CV                           | Output 1+2           | Aux                                   |
|-----------------------|---------------------------|-----------------------------------|---------------------------------------------------------------------------------------------------|-----------------------------------------|---------------------------------------|----------------------------------------|----------------------|---------------------------------------|
| Ladder Filter         | Cutoff frequency          | Resonance                         | Warps internal oscillator                                                                         | Input 1 level/ oscillator frequency     | Input 2 level                         | Inputs 1&2 VCA CV control              | Filter summed output | Sum of 1+2 or internal oscillator out |
| Dual SVF              | Filter 1 cutoff frequency | Filter 2 cutoff frequency         | Toggles between different combinations: LP/HP (unlit), LP/BP (green), BP/HP (yellow), BP/BP (red) | Filter 1 resonance                      | Filter 2 resonance                    | Inputs 1&2 VCA CV control              | Filter 1 output      | Filter 2 output                       |
| Reverbs               | Diffussion                | Reverb time                       | Selects reverbs: Caveman (unlit), Rings (green), Clouds (yellow), Elements (red)                  | Reverb amount, reverb gain for Elements | Filter LP filter, feedback for Clouds | Inputs 1&2 VCA CV control              | Left output          | Right output                          |
| Chebyschev Waveshaper | Order                     | Gain                              | Warps internal oscillator                                                                         | Input 1 level/ oscillator frequency     | Input 2 level                         | Inputs 1&2 VCA CV control              | Out                  | Sum of 1+2 or internal oscillator out |
| Frequency Shifter     | Frequency shift           | Crossfade between up/down outputs | Warps internal oscillator                                                                         | Feedback                                | Dry/Wet                               | Feedback and Dry/Wet CV control        | Up                   | Down                                  |
| Bitcrusher            | Bit crushing amount       | Cross modulation: dry, AND, XOR   | Warps internal oscillator                                                                         | Input 1 level/ oscillator frequency     | Input 2 level                         | Inputs 1&2 VCA CV control              | Out                  | Sum of 1+2 or internal oscillator out |
| Doppler Panner        | X Coordinate              | Y Coordinate                      | Space size: from smaller (unlit) to larger (red)                                                  | LFO frequency                           | LFO Amplitude                         | LFO amplitude and frequency CV control | Out                  | Out symmetrical on axis               |
| Delay                 | Delay speed/direction     | Delay length                      | Selects modes: open fb loop (unlit), dual (green), analog (yellow), ping-pong (red)               | Feedback                                | Dry/Wet                               | Feedback and Dry/Wet CV control        | Out 1                | out 2                                 |

For `Meta` mode see [Mutable Instruments stock firmware documentation](https://pichenettes.github.io/mutable-instruments-documentation/modules/warps/manual/)

## Graphical Quick Reference

A quick reference guide is provided. A ton of gratitude to [epijdemic](https://www.reddit.com/user/epijdemic/) who volunteered to create such a great visual aid for the firmware.

&nbsp;

![](/images/warps_symbiote_reference.png#centerme)

&nbsp;

## Change Log

### Symbiote 0.2.0

New features:

- Replaced Parasites Vocoder with Doppler Panner, find it in position 7 in the interface.
- Replaced pulse train oscillator with square wave oscillator.
- The internal oscillator options for the ladder filter are now:
   - Triangle (green), Saw (yellow), Square (red).
- Improved cutoff frequency calibration for the ladder filter.

### Symbiote 0.1.0

New features:

- Ladder Filter: ported from an implementation of the [improved Moog Ladder Filter](https://github.com/ddiakopoulos/MoogLadders/blob/master/src/ImprovedModel.h)
- Dual State Variable Filter: implemented a dual filter based on Emillie's [State Variable Filter](https://github.com/pichenettes/stmlib/blob/e3bd7c9cc00e4364166f9905c0509b6ffd0535ec/dsp/filter.h#L177)
- Multi Reverb: added 4 reverbs based on the implementations found in Rings, Clouds and Elements.
