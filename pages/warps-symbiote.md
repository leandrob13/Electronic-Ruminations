<!--
.. title: Warps Symbiote
.. slug: warps-symbiote
.. date: 2023-07-02 19:09:09 UTC-05:00
.. tags: mutable instruments, eurorack
.. category: music programming
.. link: 
.. description: 
.. type: text
.. status: featured
-->

Warps Symbiote firmware is built on top of the [Warps Parasites firmware](https://mqtthiqs.github.io/parasites/warps.html) and is my attempt to bring new life to the Mutable Instruments clones available from other manufacturers, let's try to preserve such an important legacy.

The current beta (**v0.4.0-beta**) reshuffles the algorithm slots, adds a new stereo multimode filter, a dual parallel filter sub-mode, an ensemble voice, and fixes the Chebyschev waveshaper. The older releases (0.1.0 → 0.3.0-beta) shipped a Moog-style Ladder Filter, a Dual State Variable Filter and four reverbs and are documented further down on this page.

Here is the original demo overview of the symbiote effects (still valid for the unchanged algorithms in the lower half of the panel):

&nbsp;

<p align="center"><iframe width="560" height="315" src="https://www.youtube.com/embed/FZFHOwKZnD8" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe></p>

## Contents

- [Symbiote 0.4.0](#symbiote-040)
  - [Installation](#installation)
  - [Interface](#interface)
  - [Stereo Filter](#stereo-filter)
  - [Dual Parallel Filter](#dual-parallel-filter)
  - [Ensemble Voice](#ensemble-voice)
  - [Chebyschev Waveshaper (oversampled fix)](#chebyschev-waveshaper-oversampled-fix)
  - [Parameters (v0.4.0)](#parameters-v040)
- [Symbiote 0.3.0 and below](#symbiote-030-and-below)
  - [Installation (legacy)](#installation-legacy)
  - [Interface (legacy)](#interface-legacy)
  - [Ladder Filter](#ladder-filter)
  - [Dual State Variable Filter](#dual-state-variable-filter)
  - [Reverbs](#reverbs)
  - [Parameters (legacy)](#parameters-legacy)
  - [Graphical Quick Reference](#graphical-quick-reference)
- [Change Log](#change-log)

## Symbiote 0.4.0

### Installation

Download the firmware `.wav` file [version 0.4.0-beta](https://github.com/leandrob13/eurorack/releases/tag/v0.4.0-beta) and follow the usual update procedure stated in the [Mutable Instruments Warps manual](https://pichenettes.github.io/mutable-instruments-documentation/modules/warps/manual/).

### Interface

The first two algorithm slots have changed, and a few other algorithms have shifted position to make room. The new left-to-right algorithm list is:

1. Stereo Filter (with Dual Parallel Filter as a sub-mode).
2. Ensemble Voice.
3. Reverbs.
4. Frequency Shifter.
5. Bitcrusher.
6. Chebyschev Waveshaper (now oversampled).
7. Doppler Panner.
8. Delay.
9. Meta.

Reverbs, Frequency Shifter, Bitcrusher, Doppler Panner, Delay and Meta keep the same behaviour described in the legacy section below — only their slot numbers have shifted. The Ladder Filter is no longer available; the Dual State Variable Filter has been folded into the new Stereo Filter slot as the "Dual Parallel Filter" sub-mode.

The internal-oscillator button now also doubles as a sub-mode latch on slot 1: hold the button and turn the `MODULATION` knob to choose between the Stereo Filter (knob CCW) and the Dual Parallel Filter (knob CW). The choice is saved to flash and survives a power cycle.

### Stereo Filter

A stereo multimode SVF with four filter shapes selected with the internal-oscillator button:

- **Unlit**: Low-pass (4-pole, both channels).
- **Green**: High-pass.
- **Yellow**: Band-pass.
- **Red**: Notch.

Both channels share the same cutoff (`ALGORITHM` knob) and the same resonance (`MODULATION` knob). Resonance follows an exponential taper that pushes the filter all the way into self-oscillation territory at the top of the knob's travel. `LEVEL 1` and `LEVEL 2` continue to act as the per-input drive amount, with the `LEVEL 1&2` CV inputs modulating the VCAs as in stock Warps. The filtered stereo output is sent to **OUT 1** (left) and **AUX** (right).

### Dual Parallel Filter

The Dual State Variable Filter from earlier releases is still here, but now lives as a sub-mode of slot 1. To enter it, **hold the internal-oscillator button** and **turn the `MODULATION` knob fully clockwise**. To return to the Stereo Filter, hold the button again and turn `MODULATION` fully counter-clockwise.

Inside this sub-mode the two filters are independent again:

- `ALGORITHM` knob → Filter 1 cutoff (Left / OUT 1).
- `MODULATION` knob → Filter 2 cutoff (Right / AUX).
- `LEVEL 1` knob → Filter 1 resonance.
- `LEVEL 2` knob → Filter 2 resonance.
- Internal-oscillator button cycles the layout: **LP / HP** (unlit), **LP / BP** (green), **BP / HP** (yellow), **BP / BP** (red).
- `LEVEL 1&2` CV inputs become the per-input drive CV, like in the legacy Dual SVF.

Resonance calibration has been tightened for v0.4.0 so the dual filter's distortion sweet-spot is easier to land on.

### Ensemble Voice

A stereo ensemble / chorus effect, layered on top of a stereo low-pass filter and Warps' internal oscillator — handy for instant pad-like textures from a single audio input or from the internal oscillator alone.

- `ALGORITHM` knob → cutoff of the front-end stereo low-pass filter (no resonance).
- `MODULATION` knob → ensemble amount and depth (one knob, taper-linked so the effect smoothly opens up from a subtle thickening at noon to a full chorus swirl fully CW).
- Internal-oscillator button → enables Warps' internal oscillator as a voice. When unlit, the algorithm processes the external inputs only; when lit, the oscillator is mixed in and `LEVEL 2` controls its amplitude. The colour selects the oscillator waveform, matching the existing internal-oscillator behaviour (sine, triangle, saw, square).
- `LEVEL 1` → external input drive.
- `LEVEL 1&2` CV inputs → VCA CV control.

The ensemble engine uses three chorus taps per channel driven by two LFOs (a slow 0.75 Hz movement and a faster 6.57 Hz shimmer), cross-fed between the left and right outputs to widen the stereo image. Wet output goes to **OUT 1** (left) and **AUX** (right).

### Chebyschev Waveshaper (oversampled fix)

The Chebyschev Waveshaper now runs **oversampled** and uses the latest Parasites v1.01 algorithm. This fixes the aliasing / glitchy high-frequency artefacts that the older release tried to tame by downsampling the input — those workarounds are no longer needed. As of v0.4.0 the algorithm has moved from slot 4 to **slot 6** (between Bitcrusher and Doppler Panner).

The knob layout is unchanged from the legacy description: `ALGORITHM` selects the Chebyschev order, `MODULATION` controls gain, internal oscillator button enables Warps' internal oscillator, `LEVEL 1` / `LEVEL 2` are input drives, and `LEVEL 1&2` CVs modulate the input VCAs.

### Parameters (v0.4.0)

|         Algorithm         |      Algorithm Knob/CV      |              Timbre Knob/CV               |                                            Internal Oscillator Button                                            |               Level 1 Knob               |               Level 2 Knob               |              Level 1&2 CV               |                   Output 1                    |                       Aux                       |
|:-------------------------:|:---------------------------:|:-----------------------------------------:|:----------------------------------------------------------------------------------------------------------------:|:----------------------------------------:|:----------------------------------------:|:---------------------------------------:|:---------------------------------------------:|:-----------------------------------------------:|
|     **Stereo Filter**     |  Cutoff (shared L+R)        | Resonance (shared L+R)                   | Cycles filter mode: **LP** (unlit), **HP** (green), **BP** (yellow), **N** (red). Hold + `MOD` CCW = Stereo, CW = Dual Parallel | Input 1 drive                            | Input 2 drive                            | Inputs 1&2 VCA CV                       | Filtered left channel                         | Filtered right channel                          |
|  **Dual Parallel Filter** | Filter 1 cutoff             | Filter 2 cutoff                          | Layout: **LP/HP** (unlit), **LP/BP** (green), **BP/HP** (yellow), **BP/BP** (red). Hold + `MOD` CCW returns to Stereo Filter | Filter 1 resonance                       | Filter 2 resonance                       | Inputs 1&2 drive CV                     | Filter 1 output                               | Filter 2 output                                 |
|    **Ensemble Voice**     |  Front LP filter cutoff     | Ensemble amount + depth                  | Toggles internal oscillator voice. Colour selects waveform                                                       | Input drive                              | Internal oscillator amplitude            | Inputs 1&2 VCA CV                       | Ensemble left                                  | Ensemble right                                  |
|        Reverbs            |  Diffusion                  | Reverb time                              | Selects reverb: Caveman (unlit), Rings (green), Clouds (yellow), Elements (red)                                  | Reverb amount, reverb gain for Elements  | Filter LP, feedback for Clouds           | Inputs 1&2 VCA CV                       | Left output                                   | Right output                                    |
|   Frequency Shifter       |  Frequency shift            | Crossfade between up/down outputs        | Warps internal oscillator                                                                                        | Feedback                                 | Dry/Wet                                  | Feedback and Dry/Wet CV                 | Up                                            | Down                                            |
|      Bitcrusher           |  Bit crushing amount        | Cross modulation: dry, AND, XOR          | Warps internal oscillator                                                                                        | Input 1 level / oscillator frequency     | Input 2 level                            | Inputs 1&2 VCA CV                       | Out                                           | Sum of 1+2 or internal oscillator               |
| **Chebyschev Waveshaper** |  Order                      | Gain                                     | Warps internal oscillator                                                                                        | Input 1 level / oscillator frequency     | Input 2 level                            | Inputs 1&2 VCA CV                       | Out (oversampled)                             | Sum of 1+2 or internal oscillator               |
|     Doppler Panner        |  X coordinate               | Y coordinate                             | Space size: smaller (unlit) → larger (red)                                                                       | LFO frequency                            | LFO amplitude                            | LFO amplitude and frequency CV          | Out                                           | Out symmetrical on axis                         |
|         Delay             |  Delay speed / direction    | Delay length                             | Modes: open feedback loop (unlit), dual (green), analog (yellow), ping-pong (red)                                | Feedback                                 | Dry/Wet                                  | Feedback and Dry/Wet CV                 | Out 1                                         | Out 2                                           |

For `Meta` mode see [Mutable Instruments stock firmware documentation](https://pichenettes.github.io/mutable-instruments-documentation/modules/warps/manual/).

## Symbiote 0.3.0 and below

The rest of this page documents the firmware up to and including **0.3.0-beta** (the last release before the v0.4.0 layout reshuffle). The Ladder Filter and the standalone Dual State Variable Filter described here have been replaced or repackaged in v0.4.0, but everything from "Reverbs" onward still applies to the current firmware — only the slot numbers have changed (see the [v0.4.0 interface section](#interface) above).

### Installation (legacy)

Download the firmware `.wav` file [version 0.2.0](https://github.com/leandrob13/eurorack/releases/tag/v0.2.0) (or the [0.3.0-beta](https://github.com/leandrob13/eurorack/releases/tag/v0.3.0-beta) for the Ladder Filter / Chebyschev re-tuning) and follow the usual update procedure stated in the [Mutable Instruments Warps manual](https://pichenettes.github.io/mutable-instruments-documentation/modules/warps/manual/).

### Interface (legacy)

The interface of this firmware is the same as the one implemented in [Warps Parasites](https://mqtthiqs.github.io/parasites/warps.html#mode). From left to right, the algorithms are:

- Ladder Filter.
- Dual State Variable Filter.
- Reverbs.
- Chebyschev Waveshaper.
- Frequency Shifter.
- Bitcrusher.
- Doppler Panner.
- Delay.
- Meta

### Ladder Filter

A ported implementation of the Moog Ladder Filter model:

This model is based on a reference implementation of an algorithm developed by Stefano D'Angelo and Vesa Valimaki, presented in a paper published at ICASSP in 2013. This improved model is based on a circuit analysis and compared against a reference Ngspice simulation. In the paper, it is noted that this particular model is more accurate in preserving the self-oscillating nature of the real filter.

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

### Parameters (legacy)

|       Algorithm       |     Algorithm Knob/CV      |           Timbre Knob/CV           |                                     Internal Oscillator Button                                     |               Level 1 Knob               |              Level 2 Knob              |              Level 1&2 CV               |      Output 1+2       |                  Aux                   |
|:---------------------:|:--------------------------:|:----------------------------------:|:--------------------------------------------------------------------------------------------------:|:----------------------------------------:|:--------------------------------------:|:---------------------------------------:|:---------------------:|:--------------------------------------:|
|     Ladder Filter     |      Cutoff frequency      |             Resonance              |                                     Warps internal oscillator                                      |   Input 1 level/ oscillator frequency    |             Input 2 level              |        Inputs 1&2 VCA CV control        | Filter summed output  | Sum of 1+2 or internal oscillator out  |
|       Dual SVF        | Filter 1 cutoff frequency  |     Filter 2 cutoff frequency      | Toggles between different combinations: LP/HP (unlit), LP/BP (green), BP/HP (yellow), BP/BP (red)  |            Filter 1 resonance            |           Filter 2 resonance           |        Inputs 1&2 VCA CV control        |    Filter 1 output    |            Filter 2 output             |
|        Reverbs        |         Diffussion         |            Reverb time             |          Selects reverbs: Caveman (unlit), Rings (green), Clouds (yellow), Elements (red)          | Reverb amount, reverb gain for Elements  | Filter LP filter, feedback for Clouds  |        Inputs 1&2 VCA CV control        |      Left output      |              Right output              |
| Chebyschev Waveshaper |           Order            |                Gain                |                                     Warps internal oscillator                                      |   Input 1 level/ oscillator frequency    |             Input 2 level              |        Inputs 1&2 VCA CV control        |          Out          | Sum of 1+2 or internal oscillator out  |
|   Frequency Shifter   |      Frequency shift       | Crossfade between up/down outputs  |                                     Warps internal oscillator                                      |                 Feedback                 |                Dry/Wet                 |     Feedback and Dry/Wet CV control     |          Up           |                  Down                  |
|      Bitcrusher       |    Bit crushing amount     |  Cross modulation: dry, AND, XOR   |                                     Warps internal oscillator                                      |   Input 1 level/ oscillator frequency    |             Input 2 level              |        Inputs 1&2 VCA CV control        |          Out          | Sum of 1+2 or internal oscillator out  |
|    Doppler Panner     |        X Coordinate        |            Y Coordinate            |                          Space size: from smaller (unlit) to larger (red)                          |              LFO frequency               |             LFO Amplitude              | LFO amplitude and frequency CV control  |          Out          |        Out symmetrical on axis         |
|         Delay         |   Delay speed/direction    |            Delay length            |        Selects modes: open fb loop (unlit), dual (green), analog (yellow), ping-pong (red)         |                 Feedback                 |                Dry/Wet                 |     Feedback and Dry/Wet CV control     |         Out 1         |                 out 2                  |

For `Meta` mode see [Mutable Instruments stock firmware documentation](https://pichenettes.github.io/mutable-instruments-documentation/modules/warps/manual/)

### Graphical Quick Reference

A quick reference guide is provided for the 0.2.0 layout. A ton of gratitude to [epijdemic](https://www.reddit.com/user/epijdemic/) who volunteered to create such a great visual aid for the firmware.
You can download the PDF [here](/pdf/symbiote_v2.pdf).

&nbsp;

![](/images/warps_symbiote_ref.png#centerme)

&nbsp;

## Change Log

### Symbiote 0.4.0-beta

New features:

- **Stereo Filter**: stereo multimode filter (LP / HP / BP / Notch) in algorithm slot 1.
- **Dual Parallel Filter**: the previous Dual State Variable Filter is now a sub-mode of slot 1. Hold the internal-oscillator button and turn the `MODULATION` knob fully CW to enter it; fully CCW returns to the Stereo Filter. The choice is persisted to flash.
- **Ensemble Voice**: new ensemble / chorus effect with a stereo low-pass front-end and an optional internal oscillator voice, in algorithm slot 2.

Fixes:

- Chebyschev Waveshaper now runs oversampled using the Parasites v1.01 algorithm. The earlier downsampling workaround has been removed. The algorithm moved from slot 4 to slot 6.
- Tightened resonance calibration for the Dual Parallel Filter.
- Algorithm slot reshuffle: Frequency Shifter is now slot 4, Bitcrusher is slot 5, Chebyschev is slot 6 (the rest are unchanged).

### Symbiote 0.3.0-beta

Fixes:

- Tweaked Ladder Filter calibration so that the filter would open up a bit more.
- Set the sample rate back at 96 kHz.
- Down-sampled the audio fed into the Chebyschev Waveshaper to tame the glitchy sounds when high knob values are selected.

### Symbiote 0.2.0

New features:

- Replaced Parasites Vocoder with Doppler Panner, find it in position 7 in the interface.
- Replaced pulse train oscillator with square wave oscillator.
- The internal oscillator options for the ladder filter are now: Triangle (green), Saw (yellow), Square (red).
- Improved cutoff frequency calibration for the ladder filter.

### Symbiote 0.1.0

New features:

- Ladder Filter: ported from an implementation of the [improved Moog Ladder Filter](https://github.com/ddiakopoulos/MoogLadders/blob/master/src/ImprovedModel.h)
- Dual State Variable Filter: implemented a dual filter based on Emillie's [State Variable Filter](https://github.com/pichenettes/stmlib/blob/e3bd7c9cc00e4364166f9905c0509b6ffd0535ec/dsp/filter.h#L177)
- Multi Reverb: added 4 reverbs based on the implementations found in Rings, Clouds and Elements.
