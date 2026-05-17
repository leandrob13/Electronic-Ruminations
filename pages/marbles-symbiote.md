<!--
.. title: Marbles Symbiote
.. slug: marbles-symbiote
.. date: 2026-05-17 12:00:00 UTC-05:00
.. tags: 
.. category: 
.. link: 
.. description: 
.. type: text
-->

Marbles Symbiote firmware adds a new T-section model that turns Marbles into a self-contained generative drum + acid bassline machine:

- **Grids drum engine** ported from [Mutable Instruments Grids](https://pichenettes.github.io/mutable-instruments-documentation/modules/grids/manual/), driving BD, SD and HH on the three T-section gate outputs.
- **Euclidean sub-mode** with a shared step length across all three drum voices, also borrowed from Grids.
- **TB-3PO acid sequencer** on the X-section, ported from the [Hemisphere TB_3PO applet](https://github.com/djphazer/O_C-Phazerville), locked to the same master clock as the drums so the bassline always stays in time.
- **Bipolar `DEJA VU` knob** with separate functions per drum sub-mode: chaos on the drum map (Drums) or T2 fills and pattern rotation (Euclidean).
- **Seed lock and persistence**: the bassline pattern is reseeded on demand and locked patterns survive a power cycle.

When Grids mode is active, Marbles becomes a single-cable rhythm section: three drum gates, a clock, a 1V/oct pitch CV, a gate and an accent — all generated, all in sync, all quantized to the X-section scale.

Here is a demo overview of the new mode:

&nbsp;

<!-- TODO: video placeholder -->
<p align="center"><em>Video coming soon.</em></p>

## Contents

- [Installation](#installation)
- [Interface](#interface)
- [Grids Drums](#grids-drums)
- [Grids Euclidean](#grids-euclidean)
- [TB-3PO Acid Sequencer](#tb-3po-acid-sequencer)
- [Parameters](#parameters)
- [Change Log](#change-log)

## Installation

Download the firmware `.wav` file [version 0.1.0](https://github.com/leandrob13/eurorack/releases/tag/v0.1.0-marbles) and follow the usual update procedure stated in the [Mutable Instruments Marbles manual](https://pichenettes.github.io/mutable-instruments-documentation/modules/marbles/manual/).

## Interface

To get to the new mode, **long-press** the `T MODEL` button. This switches the T-section between the stock model bank and the alternative bank; Grids lives in the alternative bank and is indicated by a slow red blink on the T-model LED. Short-pressing the button still cycles within the current bank, so you can flip back to the stock T modes at any time.

Once in Grids mode the T-section's `DEJA VU` button selects the drum sub-mode:

- **Unlit / OFF**: Grids drum map (BD / SD / HH).
- **Lit / ON or LOCKED**: Euclidean drums (shared length across all three voices).

The X-section is automatically taken over by the TB-3PO acid sequencer whenever Grids is active. Outside of Grids mode the X-section behaves normally.

The rest of the interface knobs and CV inputs work as described in the sections below.

### Grids Drums

The classic Mutable Instruments Grids drum map. `BIAS` and `JITTER` traverse the map's X / Y coordinates, sweeping smoothly between the curated drum patterns. The `DEJA VU` knob is bipolar and CCW from center it injects chaos / randomness into the drum map (square-root-tapered so small CCW turns already produce audible perturbation). CW from center has no effect in Drums sub-mode. The `RATE`, `BIAS` and `JITTER` CV inputs add a CV offset to the density of each drum voice (BD, SD, HH respectively) on top of a fixed base level, so you can modulate beat density without giving up control of the pattern coordinates on the knobs.

T1 outputs the BD gate, T2 outputs the SD gate (replacing the master gate), and T3 outputs the HH gate.

### Grids Euclidean

Same engine as Grids' Euclidean sub-mode, but with a single shared length across all three voices. The `DEJA VU LENGTH` knob sets the step count from 1 to 16. The drum map is not used in this sub-mode, so the `BIAS` and `JITTER` knobs are silent here — density per voice is controlled entirely by the `RATE` / `BIAS` / `JITTER` CV inputs (same mapping as Drums sub-mode: BD / SD / HH respectively).

The `DEJA VU` knob is bipolar in Grids mode and behaves differently per sub-mode. In Euclidean:

- **CCW from center**: sprinkles random fill hits onto T2 (SD) on top of the Euclidean pattern. Cubic-tapered and capped so the base groove still reads through.
- **CW from center**: rotates the Euclidean pattern across all three voices.
- **Center (12 o'clock)**: no effect.

### TB-3PO Acid Sequencer

A port of the Hemisphere TB_3PO acid sequencer, running on the X-section whenever Grids mode is active. The sequencer ticks once per 16th note (locked to the Grids clock) and generates a pattern of pitches, gates, slides and accents. Slides are slewed with a 303-style portamento, accents are sent out the `Y` output, and the gate is held through slid steps.

The generator uses the scale selected by the X-section's scale selector (`state.x_scale`), filtered so it only walks the in-scale degrees — no chromatic passing tones on the diatonic and pentatonic presets.

- The `X SPREAD` knob and CV control the **density** of gates / slides / accents (one bipolar parameter, knob and CV summed).
- The `X BIAS` knob and CV **transpose** the pattern in semitones (±18 semitones / 3 octaves stepped, knob + CV combined; CV tracks 1V/oct).
- The `X STEPS` knob and CV set the **step length** from 1 to 32.
- The `X DEJA VU` switch controls **seed lock**:
  - Tap **OFF**: draw a new random seed and regenerate the pattern.
  - Flip to **ON / LOCKED**: lock the current seed and commit it to flash — the same pattern will return on next power-up.
- The `DEJA VU` CV input is repurposed in Grids mode as a **reset trigger**: a rising edge resets both the drums and the bassline to step 0.
- `X SCALE` selects the scale (reuses the existing X scale selector).
- `X RANGE` is unused in Grids mode (pitch is always 1V/oct).

Outputs:

- **X1**: 5V / 0V clock square wave (16th notes).
- **X2**: 1V/oct pitch CV, slewed on slid steps.
- **X3**: gate (high while the step is gated; held through slides).
- **Y**: accent gate (high only when the step is both accented and gated).

## Parameters

T-section (Grids mode):

|  Sub-mode   |       RATE Knob       |        BIAS Knob        |       JITTER Knob       |     RATE CV     |     BIAS CV     |    JITTER CV    |                              DEJA VU Knob                              |          DEJA VU LENGTH Knob          |              DEJA VU CV               |     DEJA VU Button      |
|:-----------:|:---------------------:|:-----------------------:|:-----------------------:|:---------------:|:---------------:|:---------------:|:----------------------------------------------------------------------:|:-------------------------------------:|:-------------------------------------:|:-----------------------:|
|  **Drums**  | Tempo / clock division | Drums map X coordinate  | Drums map Y coordinate  |  BD density CV  |  SD density CV  |  HH density CV  |  CCW from center: chaos / randomness on the drum map. CW: no effect.   |               _unused_                | Rising edge: reset both T and X to step 0 |   OFF = Drums sub-mode  |
| **Euclidean** | Tempo / clock division |        _unused_         |        _unused_         |  BD density CV  |  SD density CV  |  HH density CV  | CCW from center: T2 (SD) random fills. CW from center: pattern rotation. | Shared Euclidean length (1–16 steps)  | Rising edge: reset both T and X to step 0 | ON / LOCKED = Euclidean |

X-section (Grids mode — TB-3PO bassline):

|                  X SPREAD Knob + CV                   |                X BIAS Knob + CV                 |         X STEPS Knob + CV          |    X DEJA VU Switch     |          X SCALE          | X RANGE  |
|:-----------------------------------------------------:|:-----------------------------------------------:|:----------------------------------:|:-----------------------:|:-------------------------:|:--------:|
| Bassline density of gates / slides / accents (bipolar) | Bassline transpose, ±18 semitones (CV: 1V/oct)  | Bassline step length, 1 to 32 steps | Seed lock / reseed / commit | Scale (reuses X scale selector) | _unused_ |

| Output |              Voltage              |                            Source                            |
|:------:|:---------------------------------:|:------------------------------------------------------------:|
|   T1   |               Gate                |                       Grids BD drum gate                       |
|   T2   |               Gate                |             Grids SD drum gate (master gate output)             |
|   T3   |               Gate                |                       Grids HH drum gate                       |
|   X1   |          5V / 0V clock           |   Grids step clock (16th notes, locked to the drum engine)   |
|   X2   |             1V/oct              | TB-3PO pitch CV, scale-quantized, slewed on slid steps     |
|   X3   |               Gate                |       TB-3PO gate (held through slides)                       |
|   Y    |               Gate                |          TB-3PO accent (high on accented + gated steps)         |

## Change Log

### Symbiote 0.1.0

New features:

- Grids drum engine ported into the T-section, driving BD / SD / HH on T1 / T2 / T3.
- Euclidean drums sub-mode with shared step length across all three voices, selected by the T-section `DEJA VU` button.
- TB-3PO acid sequencer running on the X-section while Grids mode is active, locked to the drum clock.
- Scale-aware in-scale pitch selection: the bassline walks only the diatonic degrees of the selected X-section scale.
- 303-style slide slewing on slid steps, with held gate and a separate accent output.
- Seed lock and flash persistence: locked patterns survive a power cycle; `X DEJA VU` taps draw a new seed, flipping to ON commits it.
- Independent step length controls: `DEJA VU LENGTH` (Euclidean drums, 1–16) and `X STEPS` (TB-3PO bassline, 1–32).
- `DEJA VU` CV input repurposed in Grids mode as a global reset (resets both drums and bassline to step 0).
- Bipolar `DEJA VU` knob mapping: CCW = drum-map chaos (Drums) / T2 fills (Euclidean); CW = pattern rotation (Euclidean).
