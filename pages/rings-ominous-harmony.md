<!--
.. title: Rings Ominous Harmony
.. slug: rings-ominous-harmony
.. date: 2023-11-01 17:41:35 UTC-05:00
.. tags: mutable instruments, eurorack
.. category: music programming
.. link: 
.. description: 
.. type: text
-->

Rings **Ominous Harmony** is an alternative firmware that turns Rings' chord-organ easter egg into a complete polyphonic synth voice:

- A multimode filter (LP / BP / HP) with **musical resonance and drive**, modeled after the Plaits engine2 VCF.
- **Modal resonance control**: hold the polyphony button and turn the brightness pot to dial in resonance.
- Internal envelope routing to the VCF cutoff (bipolar) and to a fully CV-controllable VCA.
- Built-in AR envelope shared by VCA and VCF, with a drone option at the top of the knob.
- 25 J6 chords organized by genre, with hysteresis on chord and genre selection to prevent flapping on noisy CV.
- Arpeggiator with 4 modes (UP, DOWN, UP-DOWN, RANDOM) and ±1 octave range, mode-CV controllable through the Structure CV input.
- Six FX flavors: two delays (a stereo tape-style and a longer mono variant), Chorus, Ensemble, and two reverbs.

Here is an overview of the firmware:

&nbsp;

<p align="center"><iframe width="560" height="315" src="about:blank" title="YouTube video player — placeholder, link to be added on release" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe></p>

## Contents

- [Installation](#installation)
- [Entering Ominous Harmony](#entering-ominous-harmony)
- [Parameters](#parameters)
- [Filter Modes](#filter-modes)
- [Resonance Capture](#resonance-capture)
- [FX](#fx)
- [Arpeggiator](#arpeggiator)
- [Genre Chords](#genre-chords)
- [Change Log](#change-log)

## Installation

The current release is **v0.1.0**. The release `.wav` file will be published on the [eurorack releases page](https://github.com/leandrob13/eurorack/releases) — link to be added once the tag is cut. Once the file is available, follow the usual update procedure described in the [Mutable Instruments Rings manual](https://pichenettes.github.io/mutable-instruments-documentation/modules/rings/manual/).

## Entering Ominous Harmony

To enter **Ominous Harmony** mode:

- Frequency knob fully CCW.
- Structure knob fully CW.
- Long press the **model button** until the LEDs light in a multicolor pattern.

The same long-press toggles the mode back off. The mode is persisted to flash and survives a power cycle.

## Parameters

The V/Oct CV input selects the chord within the current genre; the Frequency knob defines the root note. There is no CV control over the root.

The polyphony LED indicates the current bank, which also selects the filter topology:

| Polyphony LED | Bank | Brightness knob role |
|:---:|:---:|:---|
| Green | 1 | Drawbar registration / harmonics blend (no filter on the bus) |
| Yellow | 2 | Low-pass filter cutoff |
| Rainbow | 3 | Band-pass filter cutoff |
| Red | 4 | High-pass filter cutoff |

The polyphony button cycles through the four banks; **holding** the polyphony button enters resonance-edit mode (see [Resonance Capture](#resonance-capture) below).

| Parameter | Description | Knob | CV Input | Attenueverter |
|:---:|:---:|:---:|:---:|:---:|
| Frequency | Root note of the chord | Quantized to semitones when V/Oct is patched | FM input | Without CV input patched, transposes the frequency by a few semitones; otherwise attenuverts the FM input |
| Structure | Genre and arpeggiator controls | Genre selection (1 of 25), with hysteresis to lock the chosen bank | Arpeggiator mode CV — summed with the attenuverter to select an arp mode | Arpeggiator mode. From center CCW: UP, DOWN, UP-DOWN, RANDOM. From center CW: same modes with +1 octave |
| Brightness | Waveform selector / VCF cutoff / VCF resonance | Bank 1 (green): scans through registrations sorted by brightness. Banks 2 / 3 / 4: VCF cutoff. **Polyphony button held**: captures into VCF resonance | Summed into VCF cutoff (active in banks 2 / 3 / 4) | Bipolar envelope-to-filter amount when the brightness CV is unpatched; otherwise attenuverts the cutoff CV |
| Damping | AR envelope shape and VCA controls | Sweeps through paired attack / decay times for the AR envelope. Fully CW disables the envelope (drone) | VCA control, summed with the envelope output when the envelope is active | Attenuates the VCA CV when the envelope is enabled; otherwise sets the VCA bias level |

## Filter Modes

In banks 2 / 3 / 4, the chord bus is routed through a per-sample state-variable filter modeled on the Plaits engine2 VCF. All five tone-shaping coefficients (cutoff, Q, drive, stage-2 mix) are smoothed by a parameter interpolator across each audio block, so cutoff sweeps and CV modulation glide cleanly with no zipper noise.

- **LP (bank 2 — yellow)**: a cascaded dual-stage state-variable LP. The first SVF carries the resonance peak; the second runs at a much gentler Q and is mixed in to round off the peak and add the "Plaits-flavor" subtle warmth.
- **BP (bank 3 — rainbow)**: a single-stage band-pass with a higher Q baseline so the bandpass band stays audible even at low resonance settings.
- **HP (bank 4 — red)**: a single-stage high-pass, same Q baseline as the band-pass.

All three modes share the same drive path: the chord bus is soft-clipped before the filter and again on the way out, so pushing resonance into self-oscillation territory gives a graceful overdrive rather than a hard clip. The drive gain follows resonance — louder at low resonance, gently attenuated at high resonance — to keep the self-oscillation peaks tame.

The cutoff is referenced to the chord's tonic (Frequency knob + V/Oct transpose), so the filter tracks the chord root: turning the Frequency knob sweeps the filter and the chord pitch together.

## Resonance Capture

Resonance is on a modal capture surface so the existing brightness pot can stay assigned to cutoff:

1. **Hold the polyphony button** for ~0.3 s. The pot reading now drives **filter resonance** instead of cutoff. The cutoff value latches at its last position.
2. While holding, turn the brightness pot to set the resonance.
3. **Release the button.** The pot returns to controlling cutoff, and the resonance value you set is retained until the next capture.

Tapping the polyphony button (a short press, under ~0.3 s) still cycles through banks 1 → 2 → 4 → 3 → 1; only a deliberate hold enters resonance-edit mode.

The resonance value is session-only — it is not currently persisted to flash, so it resets to zero on power cycle.

## FX

The **model selection button** selects the FX type:

| Type | Description | Model LED | Position knob | Position CV input | Position attenueverter |
|:---:|:---:|:---:|:---:|:---:|:---:|
| Delay | Tape-style stereo delay with soft-clipped, DC-blocked, low-pass-damped feedback | Solid green (Delay), blinking green (Delay 2) | Delay time | Delay time CV | Feedback amount |
| Chorus | Stereo chorus and ensemble voicings | Chorus (solid yellow), Ensemble (blinking yellow) | Effect amount | Effect amount CV | CV attenueverter |
| Reverb | Reverb models | Caveman (solid red), Shinier Caveman (blinking red) | Reverb decay amount | Reverb amount CV | CV attenueverter |

The two **delay** voicings share the same engine and the same musical character:

- **Delay** (solid green): true-stereo delay with independent left / right read pointers (longer, brighter spread).
- **Delay 2** (blinking green): mono-sum delay with a longer single buffer (up to ~512 ms at 48 kHz), useful for ping-pong-style washes.

The delay engine includes:

- **Tape-style read-pointer slew**: when the delay time changes (knob or CV), the read pointer glides to the new offset across the audio block, producing a brief pitch-bend on the tail instead of the click / zipper of a raw pointer jump.
- **Low-pass-damped feedback**: each repeat is slightly darker than the last, masking the noise floor and keeping long tails musical instead of fizzy.
- **DC blocker** in the feedback loop, preventing long-term DC build-up that would otherwise eat headroom.
- **Soft-clipped feedback**: pushing the feedback past unity overdrives gracefully instead of crackling.

Below ~10 % of the Position knob the delay is bypassed entirely, so a fully-CCW delay-time knob gives a clean dry signal without the residual buffer hiss of an active delay.

## Arpeggiator

To use the arpeggiator, the **Strum CV input** must be patched and the **Structure attenueverter** must be **off-center**. Patch a clock signal to the Strum CV input, select an arpeggiator mode with the Structure attenueverter, and select a genre with the Structure knob.

- The **V/Oct CV input** selects the chord within the current genre.
- The **Frequency knob** selects the root note.
- The **Structure CV input** sums with the attenueverter value, so the arp mode itself can be CV-modulated mid-pattern.

From center to CCW: UP, DOWN, UP-DOWN, RANDOM. From center to CW: same modes with +1 octave.

## Genre Chords

The order of the chords, from top to bottom, corresponds to CCW → CW positions on the Structure knob.

| Number | Chords |
|:---:|:---:|
| 1 | Oct Stack |
| 2 | 5th Stack |
| 3 | Trad Maj |
| 4 | Trad Min |
| 5 | Blues |
| 6 | Cinematic 1 |
| 7 | Cinematic 2 |
| 8 | Cinematic / House |
| 9 | Cinematic / Synthwave |
| 10 | New Age / Cinematic |
| 11 | EDM |
| 12 | Techno |
| 13 | House 1 |
| 14 | House 2 |
| 15 | House / Techno |
| 16 | Jazz |
| 17 | Jazz House |
| 18 | Pop 1 |
| 19 | Pop 2 |
| 20 | Pop Min |
| 21 | Pop / Synth |
| 22 | Synthwave 3 |
| 23 | Synthwave 5 |
| 24 | Synthwave / House |
| 25 | Trance |

## Change Log

### Ominous Harmony 0.1.0 (upcoming)

New features:

- **Plaits-style VCF** replaces the original block-level filter on the chord bus. Per-sample parameter-interpolated cutoff, Q, drive and stage-2 mix; cascaded dual-stage LP, single-stage BP/HP; soft-clipped drive path with resonance-dependent gain compensation.
- **Modal resonance control**: holding the polyphony button enters resonance-edit mode, where the brightness pot captures into filter resonance. Cutoff latches while held; resonance latches after release.
- **Tape-style delay**: the delay's read pointer is now slewed across the block, with a one-pole low-pass and a DC blocker in the feedback loop and a soft-clip on the feedback multiply. Knob and CV sweeps glide musically, long tails decay smoothly, and high-feedback regimes overdrive gracefully.
- **Hysteresis on chord and genre selection** locks the chosen genre / chord against noisy V/Oct or Structure CV.
- **Arpeggiator mode CV control**: the Structure CV input sums with the Structure attenueverter to modulate the arp mode in real time.
- **AR envelope** routed to VCA and VCF, with a drone option at the top of the Damping knob.
- **Fully CV-controllable VCA** through the Damping CV input.
- LP / BP / HP filters (now Plaits-style — see above) replace the original formant filter.
- 25 J6 genre chords.
