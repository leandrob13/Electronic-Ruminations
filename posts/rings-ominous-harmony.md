<!--
.. title: Rings Ominous Harmony
.. slug: rings-ominous-harmony
.. date: 2023-09-09 17:41:35 UTC-05:00
.. tags: 
.. category: 
.. link: 
.. description: 
.. type: text
-->


## Contents

- [Installation](#installation)
- [Interface](#interface)
- [Parameters](#controls)
- [Graphical Quick Reference](#graphical-quick-reference)
- [Change Log](#change-log)

## Parameters

To enter **Ominous Harmony** mode do the following:

- Frequency knob fully CCW.
- Structure knob fully CW.
- Long press the model button until you see the leds light in a multicolor pattern. 

### Controls

The **Poliphony button** selects between 4 banks of 25 genres each, to total the 100 genres in the [J6 Chords Table](https://static.roland.com/manuals/J-6_manual_v102/eng/28645807.html). Long press the button to access the fourth bank.

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

