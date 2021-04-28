<!--
.. title: Minilogue-XD Subharmonikorg
.. slug: minilogue-xd-subharmonikorg
.. date: 2021-04-26 22:16:49 UTC-05:00
.. tags: Minilogue-XD, korg, logue sdk, synths
.. category: music programming
.. link: 
.. description: 
.. type: text
-->

![](/images/minilogue-xd-module.jpeg#centerme)


I finally got to play with my new [Minilogue-XD](https://www.korg.com/us/products/synthesizers/minilogue_xd_module/), a 
4 voice polyphonic synthetizer from Korg. What made this instrument stand out when I was on the hunt for an affordable 
polyphonic synth was the fact that it had two analog oscillators per voice and, the cherry on top of the cake, a third 
digital oscillator that could be programmable. The Minilogue-XD belongs to the family of Korg's Logue synths, along with 
the [Prologue](https://www.korg.com/us/products/synthesizers/prologue/) and the [NTS-1](https://www.korg.com/us/products/synthesizers/prologue/),
and you can program all of them with the help of the [logue-sdk](https://korginc.github.io/logue-sdk/).

I already own an the NTS-1 and programmed an oscillator for it, the [Subharmonikorg](/posts/subharmonikorg-subharmonic-oscillators-for-the-korg-nts-1),
so I wanted to hear how the same implementation would sound on a polyphonic synth. Fortunately, I didn't have to change
the C++ code used for the NTS-1 in order to make it work in the Minilogue-XD. Despite the fact, I kept two separate 
`.cpp` files for each just in case I could implement certain features in one of them that wouldn't sound ok in the other.

&nbsp;

The obvious advantage of having a subharmonic oscillator in a polyphonic synth is that you get to blend more harmonics
and their subharmonics, creating sounds that could be pleasant or disonant (depending of your choice of undertones). The 
additional advantage that the Minilogue-XD gives in comparison to the NTS-1 is the fact that you can use two additional 
analog oscillators in the mix which expands the sound design possibilities. 

The implementation can be found [here](https://github.com/leandrob13/logue-hub/tree/master/src/minilogue-xd/osc/subh) and 
the packaged Subharmonikorg can be downloaded [here](https://github.com/leandrob13/logue-hub/blob/master/oscillators/minilogue-xd/subharmonikorgv1.1.mnlgxdunit) 
for you to install in your Minilogue-XD if you want to give it a spin.

&nbsp;

For reference, here are the features of version 1.1-0:

### Features

- One main harmonic oscillator with semitone calibration up to one octave higher and one octave lower.
- Two subharmonic oscillators that divide the main oscillator tone up to the 7th undertone.
- Choose different undertones for each suboscillator.
- Mix between the main oscillator and the suboscillators with the `shape` and `alt` knobs respectively.
- Choose between square, saw and sine waveforms.
- Modulate the main oscillator mix with the LFO.
- Subharmonic oscillators arpeggiator with clock adjustment.

### Parameters

| Parameter      | Range        | Description                                                            |
| :------------: | :----------: | ---------------------------------------------------------------------: |
| SHAPE          | 0 to 100     |level mix of main oscillator                                            |
| ALT            | 0 to 100     |level mix of suboscillators                                             |
| semitone       | 1 to 13      |semitone tuning of main oscillator (1 as root note, 13 higher octave)   |
| undertone 1    | 1 to 7       |undertone value of first suboscillator                                  |
| undertone 2    | 1 to 7       |undertone value of second suboscillator                                 |
| oscT           | 1 to  3      |The oscillator type 1: saw, 2: square, 3: sine                          |
| Arp Type       | 1 to  3      |The arpeggiator type 1: off, 2: down, 3: up-down                        |
| Arp Clock      | 0 to  100    |The arpeggiator clock percentage of max frequency.                      |

&nbsp;
