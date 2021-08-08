<!--
.. title: Subharmonikorg: Subharmonic Oscillators for the Korg NTS-1
.. slug: subharmonikorg-subharmonic-oscillators-for-the-korg-nts-1
.. date: 2021-04-04 18:21:00 UTC-05:00
.. tags: nts-1, korg, logue sdk, synths
.. category: music programming
.. link: 
.. description: 
.. type: text
-->

![](/images/nts-1.png#centerme)


I have been using the [Korg NTS-1](https://www.korg.com/us/products/dj/nts_1/) for about 5 months, but it was just 
recently that I was able to spend some time trying to understand how to program it. Korg published its [logue-sdk](https://korginc.github.io/logue-sdk/)
which is written in C/C++ and it provides useful templates and make files in order tu build custom oscillators, delays 
and modulation effects for your logue based synths. I have only tried programming the NTS-1 since I believe one of the
main purposes of this little synth is to experiment and understand the logue-sdk and how to digitally process the 
signals, which is another way of saying that if you mess up and brick your synth it will only cost you $99 to replace
it instead of bricking the Minilogue XD which retails at $549. 

For a complete review of the NTS-1, I recommend my favorite synth reviewer Loopop. Watch the video below:

&nbsp;
<iframe width="560" height="315" src="https://www.youtube.com/embed/Vhonu-rM0B0" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

&nbsp;
## The Subharmonikorg

With the introductions out of the way, lets talk about the Subharmonikorg. I was inspired to program this oscillator
after I saw what Moog did with its analog synth, [The Subharmonicon](https://www.youtube.com/watch?v=ns0Zu5HjShY) which
is sort of a mix of two previous instruments: the [Tratonium](http://www.analogue.org/network/traut_e.htm) and the
[Rythmicon](https://en.wikipedia.org/wiki/Rhythmicon). I wanted to emulate the subharmonic sound generation and found
out that the subharmonics are derived from the [Undertone Series](https://en.wikipedia.org/wiki/Undertone_series) which is 
basically a mathematics formula that is used to calculate the subharmonics of a given note based on its frequency. So if 
it is mathematically derived then it could be programmed.

The formula is easy: just divide the note frequency by an integer and you will get the undertone frequency related
to the original note. This can be illustrated in the code hosted in the [Logue-Hub Repository](https://github.com/leandrob13/logue-hub/blob/master/src/nts-1/osc/subh/subh.cpp#L72):

&nbsp;

```c
const float w1 = osc_w0f_for_note(
    ((params->pitch)>>8) + oscillator.semitone, 
    params->pitch & 0xFF
);

...

sw1 = w1 / oscillator.undertone1;
sw2 = w1 / oscillator.undertone2;
```

&nbsp;

Where the function `osc_w0f_for_note` returns the frequency value that corresponds to the pitch (note value) passed to the
`OSC_CYCLE` function exposed in the `logue-sdk` API. Then w1 is divided by the undertones values taken from the editing
params of the NTS-1, which are integer numbers greater than zero. I limited the max possible value of subharmonics to the 
7th undertone.

### Features

The features for version 1.1-0 are as follows:

- One main harmonic oscillator with semitone calibration up to one octave higher and one octave lower.
- Two subharmonic oscillators that divide the main oscillator tone up to the 7th undertone.
- Choose different undertones for each suboscillator.
- Mix between the main oscillator and the suboscillators with the `shape` and `alt` knobs respectively.
- Choose between square, saw and sine waveforms.
- Modulate the main oscillator mix with the LFO.
- Subharmonic oscillators arpeggiator with clock adjustment.

The arpeggiator is a separate implementation from the native NTS-1 arpeggiator. In the current version 1.1-0, there are 
only two patterns available which only affect the suboscillators: `down` and `up-down`. This means that if you hold a 
note, the main oscillator will stay on it while both suboscillators will cycle from the 2nd through the 7th subharmonic. 
Having separate arpeggiators allows you to play with interesting rhythm patterns. 

### Parameters

The parameters you can edit are listed below.

&nbsp; 

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
## The Showcase

I did some noise experiment where I played with the NTS-1 Subharmonikorg and Moog's [Werkstatt-01](https://www.moogmusic.com/products/werkstatt-01-cv-expander).
The Subharmonikorg is playing its arpeggio while I hit some lead notes with the Werkstatt. I tried to keep the mood creepy.

&nbsp;

Here is the video of the weird experiment:

&nbsp;

<iframe width="560" height="315" src="https://www.youtube.com/embed/ZgSYehljJU8" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
&nbsp;

- For the whole 7 minutes noise, listen to it in bandcamp [here](https://leandrob.bandcamp.com/track/tormentor).

- Get the latest version of the Subharmonikorg in github [here](https://github.com/leandrob13/logue-hub/tree/master/oscillators/nts-1). 

There are some other oscillator ideas I have and some new features I want to test out for the NTS-1 for this oscillator. 
Hopefully I will also try this out with my newest adquisition, the Minilogue XD.
