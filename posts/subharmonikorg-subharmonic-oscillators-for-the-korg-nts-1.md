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

I have been using the [Korg NTS-1](https://www.korg.com/us/products/dj/nts_1/) for about 5 months but it was just 
recently that I was able to spend some time trying to understand how to program it. Korg published its [logue-sdk](https://korginc.github.io/logue-sdk/)
which is written in C/C++ and it provides useful templates and make files in order tu build custom oscillators, delays 
and modulation effects for your logue based synths. I have only tried programming the NTS-1 since I believe one of the
main purposes of this little synth is to experiment and understand the logue-sdk and how to digitally process the 
signals, which is another way of saying that if you mess up and brick your synth it will only cost you $99 to replace
it instead of bricking the minilogue which retails at $549. 

For a complete review of the NTS-1, I recommend my favorite synth reviewer Loopop. Watch the video below:

<iframe width="560" height="315" src="https://www.youtube.com/embed/Vhonu-rM0B0" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

## The Subharmonikorg

With the introductions out of the way, lets talk about the Subharmonikorg. I was inspired to program this oscillator
after I saw what Moog did with its analog synth, [The Subharmonicon](https://www.youtube.com/watch?v=ns0Zu5HjShY) which
is sort of a mix of two previous instruments: the [Tratonium](http://www.analogue.org/network/traut_e.htm) and the
[Rythmicon](https://en.wikipedia.org/wiki/Rhythmicon). I wanted to emulate the subharmonic sound generation and found
out the subharmonics are derived from the [Underton Series](https://en.wikipedia.org/wiki/Undertone_series) which is 
basically a mathematic formula that is used to calculate the subharmonics of a given note based on its frequency. So if 
it is mathematically derived then it could be programmed.

The formula is easy: just divide the the note frequency by an integer and you will get the undertone frequency related
to the original note. This can be illustrated in the code hosted in the [Logue-Hub Repository](https://github.com/leandrob13/logue-hub):

```c
const float w1 = osc_w0f_for_note(((params->pitch)>>8) + oscillator.semitone, params->pitch & 0xFF);
...
sw1 = w1 / oscillator.undertone1;
sw2 = w1 / oscillator.undertone2;
```

Where the function `osc_w0f_for_note` returns frequency value that corresponds to the pitch (note value) passed to the
`OSC_CYCLE` function exposed in the `logue-sdk` API. Then w1 is divided by the undertones values taken from the editing
params of the NTS-1, which are integer numbers greater than zero.




