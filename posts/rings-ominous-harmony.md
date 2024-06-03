<!--
.. title: Rings Ominous Harmony
.. slug: rings-ominous-harmony
.. date: 2023-11-01 17:41:35 UTC-05:00
.. tags: 
.. category: 
.. link: 
.. description: 
.. type: text
-->

Rings **Ominous Harmony** adds additional features that turns it into a complete polyphonic synth voice with the following features:

- Replaces the formant filter and adds low, high and band pass filters.
- Internal envelope control over filter frequency.
- Fully controllable VCA via CV.
- Internal AR envelope for VCA and VCF.
- Includes 25 J6 chords.
- Arpeggiator with 4 modes with 1 octave transposition.

Here is an overview of the new features:

&nbsp;

<p align="center"><iframe width="560" height="315" src="https://www.youtube.com/embed/FZFHOwKZnD8" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe></p>

## Contents

- [Installation](#installation)
- [Parameters](#parameters)
- [Genre Chords](#genre-chords)
- [Change Log](#change-log)

## Installation

Download the firmware `.wav` file [version 0.1.0](https://github.com/leandrob13/eurorack/releases/tag/v0.2.0) and follow the usual update procedure stated in the [Mutable Instruments Rings manual](https://pichenettes.github.io/mutable-instruments-documentation/modules/rings/manual/).

## Parameters

To enter **Ominous Harmony** mode do the following:

- Frequency knob fully CCW.
- Structure knob fully CW.
- Long press the model button until you see the leds light in a multicolor pattern. 

### Controls

The V/Oct CV input selects the chord, while the frequency knob defines the root of the chord. There is no CV control over the root note. 

| Parameters |               Description                |                                                                                    Knob                                                                                    |                                                 CV Input                                                 |                                                   Attenueverter                                                   |
|:----------:|:----------------------------------------:|:--------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|:--------------------------------------------------------------------------------------------------------:|:-----------------------------------------------------------------------------------------------------------------:|
| Frequency  |     The frequency of the oscillators     |                                                          Root note, quantized to semitones when V/Oct is patched                                                           |                                                 FM input                                                 |     With CV input unpatched, transposes the frequency to a few semitones, otherwise it attenueverts the input     |
| Structure  |      Genre and arpeggiator controls      |                                                                      Genre selection from a set of 25                                                                      | The input gets summed to the value read from the attenueverter in order to cv control the mode selection | Arpeggiator mode. From center to CCW: UP, DOWN, UP-DOWN, RANDOM. From center to CW, same as before with +1 Octave |
| Brightness | Waveform selector / VCF cutoff frequency | Poliphony led green: scans through various registrations sorted by brightness. Poliphony led yellow: low pass. Poliphony led red: higpass. Poliphony led rainbow: bandpass |                          The input gets summed to the value read from the knob                           |    Attenueverts the cv input when patched. When unpatched it sets the envelope amount to the filter (Bipolar)     |
|  Damping   |       AR Envelope and VCA controls       |                   It scans through different attack and decay times for the envelope generator. At fully CW position the envelope generator is disabled                    |             Input for VCA control. It gets summed to the envelope value when it is enabled.              |      When the envelope is enabled, it attenuates the CV input. Otherwise it serves as a bias level control.       |

### FX

The **Model Selection Button** selects the FX type:

|  Type  |        Description         |                Model selection lead                 |       Position Knob        |          Position CV Input          | Position Attenueverter |
|:------:|:--------------------------:|:---------------------------------------------------:|:--------------------------:|:-----------------------------------:|:----------------------:|
| Delay  |    Simple crunchy delay    |    Mono digital delay (Solid and blinking Green)    |         Delay time         |        Delay time CV control        |    Feedback amount     |
| Chorus | Chorus and Ensemble models |  Chorus (Solid yellow), Ensemble (Blinking yellow)  | Chorus and ensemble amount | Chorus and ensemble amount CV input | CV input attenueverter |
| Chorus |       Reverb models        | Caveman (Solid red), Shinier Caveman (Blinking red) | Reverb decay amount amount |       Reverb amount CV input        | CV input attenueverter |

### Arpegiattor

To use the arpeggiator, the **Strum CV input** must be patched and the **Structure attenueverter** must not be in the center. Patch a clock signal to the **Strum CV input**, select an arpeggiator mode and a genre to hear the arppegiator.
The **V/Oct CV input** is used to select the chord in the genre. The **Frequency knob** selects the root note.

## Genre Chords

The order of the chords, from top to bottom, correspond to CCW to CW position in the Structure knob.


| Number |       Chords        |
|:------:|:-------------------:|
|   1    |      Oct Stack      |
|   2    |      5th Stack      |
|   3    |      Trad Maj       |
|   4    |      Trad Min       |
|   5    |        Blues        |
|   6    |     Cinematic 1     |
|   7    |     Cinematic 2     |
|   8    |   Cinematic/House   |
|   9    | Cinematic/Synthwave |
|   10   |  New Age/Cinematic  |
|   11   |         EDM         |
|   12   |       Techno        |
|   13   |       House 1       |
|   14   |       House 2       |
|   15   |    House/Techno     |
|   16   |        Jazz         |
|   17   |     Jazz House      |
|   18   |        Pop 1        |
|   19   |        Pop 2        |
|   20   |       Pop Min       |
|   21   |      Pop/Synth      |
|   22   |     Synthwave 3     |
|   23   |     Synthwave 5     |
|   24   |   Synthwave/House   |
|   25   |       Trance        |

## Change Log

### Ominous Harmomy 0.1.0

New Features:

- Adds Low, High adn Band Pass filters.
- Adds Fully controllable VCA via CV.
- Adds an AR internal envelope.
- Adds 25 J6 chords.
- Adds arpeggiator.