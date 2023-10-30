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

- Replaces the formant filter and adds low pass and high pass filters.
- Internal envelope control over filter frequency.
- Fully controllable VCA via CV.
- Includes the complete 100 J6 chords, split in 4 banks.
- Arpeggiator with 4 modes with 1 octave transposition.

Here is an overview of the new features:

&nbsp;

<p align="center"><iframe width="560" height="315" src="https://www.youtube.com/embed/FZFHOwKZnD8" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe></p>

## Contents

- [Installation](#installation)
- [Parameters](#parameters)
- [Genre Banks](#genre-banks)
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

| Parameters |           Description            |                                                                    Knob                                                                    |                                                 CV Input                                                 |                                                    Attenueverter                                                    |
|:----------:|:--------------------------------:|:------------------------------------------------------------------------------------------------------------------------------------------:|:--------------------------------------------------------------------------------------------------------:|:-------------------------------------------------------------------------------------------------------------------:|
| Frequency  | The frequency of the oscillators |                                          Root note, quantized to semitones when V/Oct is patched                                           |                                                 FM input                                                 |      With CV input unpatched, transposes the frequency to a few semitones, otherwise it attenueverts the input      |
| Structure  |  Genre and arpeggiator controls  |                                          Genre selection based on the order of the J6 genre table                                          | The input gets summed to the value read from the attenueverter in order to cv control the mode selection |  Arpeggiator mode. From center to CCW: UP, DOWN, UP-DOWN, RANDOM. From center to CW, same as before with +1 Octave  |
| Brightness |        Waveform selector         | scans through various registrations sorted by brightness. Each registration is a different mixture of octaves of square and sawtooth waves |                          The input gets summed to the value read from the knob                           |                                              Attenueverts the cv input                                              |
|  Damping   |   AD Envelope and VCA controls   |   It scans through different attack and decay times for the envelope generator. At fully CW position the envelope generator is disabled    |             Input for VCA control. It gets summed to the envelope value when it is enabled.              |       When the envelope is enabled, it attenuates the CV input. Otherwise it serves as a bias level control.        |

### FX

The **Model Selection Button** selects the FX type:

|  Type  |           Description            |                Model selection lead                 |       Position Knob        |          Position CV Input          |                                      Position Attenueverter                                      |
|:------:|:--------------------------------:|:---------------------------------------------------:|:--------------------------:|:-----------------------------------:|:------------------------------------------------------------------------------------------------:|
| Filter | Filter based on the MI SVF model | Low Pass (Solid Green), High Pass (Blinking Green)  |      Filter frequency      |      Filter frequency CV input      | bipolar envelope amount to filter frequency (Env enabled), CV input attenueverter (Env disabled) |
| Chorus |    Chorus and Ensemble models    |  Chorus (Solid yellow), Ensemble (Blinking yellow)  | Chorus and ensemble amount | Chorus and ensemble amount CV input |                                      CV input attenueverter                                      |
| Chorus |          Reverb models           | Caveman (Solid red), Shinier Caveman (Blinking red) | Reverb decay amount amount |       Reverb amount CV input        |                                      CV input attenueverter                                      |

### Arpegiattor

To use the arpeggiator, the **Strum CV input** must be patched and the **Structure attenueverter** must not be in the center. Patch a clock signal to the **Strum CV input**, select an arpeggiator mode and a genre to hear the arppegiator.
The **V/Oct CV input** is used to select the chord in the genre. The **Frequency knob** selects the root note.

## Genre Banks

The **Poliphony button** selects between 4 banks of 25 genres each, to total the 100 genres in the [J6 Chords Table](https://static.roland.com/manuals/J-6_manual_v102/eng/28645807.html). Long press the button to access the fourth bank. The order in each bank column, from top to bottom, correspond to CCW to CW position in the Structure knob.

|                                                                                                                                                                                                                    Bank 1 (Green)                                                                                                                                                                                                                    |                                                                                                                                                                                    Bank 2 (Yellow)                                                                                                                                                                                    |                                                                                                                                                                                                 Bank 3 (Red)                                                                                                                                                                                                  |                                                                                                                                                                                                                 Bank 4 (Rainbow)                                                                                                                                                                                                                 |
|:----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|:------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|
| - Oct Stack1 <br/> - 4th Stack1 <br/> - 5th Stack1 <br/> - Blues1 <br/> - Bossa Nova1 <br/> - Bossa Nova2 <br/> - Cinematic1 <br/> - Cinematic2 <br/> - Cinematic3 <br/> - Cinematic/House1 <br/> - Cinematic/Synthwave1 <br/> - Classical1 <br/> - Classical2 <br/> - Classical3 <br/> - Classical4 <br/> - EDM1 <br/> - EDM2 <br/> - EDM3 <br/> - EDM4 <br/> - EDM5 <br/> - EDM6 <br/> - Funk1 <br/> - Funk2 <br/> - Techno1 <br/> - Trance1 <br/> | - Gospel/R&B1 <br/>- Gospel/R&B2 <br/>- Gospel/R&B3 <br/>- House1 <br/>- House2 <br/>- House3 <br/>- House4 <br/>- House5 <br/>- House6 <br/>- House/Techno1 <br/>- Jazz1 <br/>- Jazz2 <br/>- Jazz3 <br/>- Jazz4 <br/>- Jazz5 <br/>- Jazz6 <br/>- Jazz7 <br/>- Jazz8 <br/>- Jazz9 <br/>- Jazz10 <br/>- Jazz11 <br/>- Jazz12 <br/>- Jazz13 <br/>- Jazz House1 <br/>- Jazz House2 <br/> | - Jazz Min1 <br/>- Jazz Min2 <br/>- Jazz/Bossa1 <br/>- Lofi R&B1 <br/>- Lofi R&B2 <br/>- Modern1 <br/>- Modern2 <br/>- Neo Soul1 <br/>- Neo Soul2 <br/>- Neo Soul3 <br/>- Neo Soul4 <br/>- Neo-Soul1 <br/>- Neo-Soul2 <br/>- Neo-Soul3 <br/>- Neo-Soul4 <br/>- Neo-Soul5 <br/>- Neo-Soul6 <br/>- New Age/Cinematic1 <br/>- Pop1 <br/>- Pop2 <br/>- Pop3 <br/>- Pop4 <br/>- Pop5 <br/>- Pop6 <br/>- Pop7 <br/> | - Pop Min1 <br/>- Pop Min2 <br/>- Pop/Synth1 <br/>- Synthwave1 <br/>- Synthwave2 <br/>- Synthwave3 <br/>- Synthwave4 <br/>- Synthwave5 <br/>- Synthwave6 <br/>- Synthwave7 <br/>- Synthwave8 <br/>- Synthwave/House1 <br/>- Trad Maj1 <br/>- Trad Min1 <br/>- Trad Min 21 <br/>- Utility1 <br/>- Utility2 <br/>- Utility3 <br/>- Utility4 <br/>- Utility5 <br/>- Utility6 <br/>- Utility7 <br/>- Utility8 <br/>- Utility9 <br/>- Utility10 <br/> |

## Change Log

### Ominous Harmomy 0.1.0

New Features:

- Adds Low Pass and High Pass filters in green mode.
- Adds Fully controllable VCA via CV.
- Adds 100 J6 chords.
- Adds arpeggiator.