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
- **TB-3PO acid sequencer** on the X-section, ported from the [Hemisphere TB_3PO applet](https://github.com/djphazer/O_C-Phazerville/blob/phazerville/software/src/applets/TB3PO.h) by [Logarhythm1](https://github.com/Logarhythm1), locked to the same master clock as the drums so the bassline always stays in time.
- **Bipolar `DEJA VU` knob** with separate functions per drum sub-mode: chaos on the drum map (Drums) or T2 fills and pattern rotation (Euclidean).
- **Seed lock and persistence**: the bassline pattern is reseeded on demand and locked patterns survive a power cycle.
- **External clocking of the bassline** (new in 0.2.0): patch a clock to the X clock input and the bassline follows it, with `RATE` acting as a ¼×–4× clock divider / multiplier just like the drum clock.
- **4-slot pattern bank** (new in 0.2.0): save and recall up to four bassline seeds straight from the front panel, stored in flash.
- **Two extra standalone T-section models** (new in 0.2.0): a **Markov** chain gate generator and a deterministic **Toggle** ring counter, selectable from the `T MODEL` button with the X-section running as stock Marbles.

When Grids mode is active, Marbles becomes a single-cable rhythm section: three drum gates, a clock, a 1V/oct pitch CV, a gate and an accent — all generated, all in sync, all quantized to the X-section scale.

The two extra T-section models (Markov and Toggle) are independent of Grids mode and are covered in [Markov and Toggle T-Models](#markov-and-toggle-t-models).

Here is a demo overview of the new mode:

&nbsp;

<p align="center"><iframe width="560" height="315" src="https://www.youtube.com/embed/uLKE2HvbbIw" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe></p>

## Contents

- [Installation](#installation)
- [Interface](#interface)
- [Grids Drums](#grids-drums)
- [Grids Euclidean](#grids-euclidean)
- [TB-3PO Acid Sequencer](#tb-3po-acid-sequencer)
- [Markov and Toggle T-Models](#markov-and-toggle-t-models)
- [Parameters](#parameters)
- [Change Log](#change-log)

## Installation

Download the firmware `.wav` file [version 0.2.0](https://github.com/leandrob13/eurorack/releases/tag/marbles-symbiote-v0.2.0) and follow the usual update procedure stated in the [Mutable Instruments Marbles manual](https://pichenettes.github.io/mutable-instruments-documentation/modules/marbles/manual/).

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
- `X RANGE` button steps through the **4-slot pattern bank** (see below). Pitch is always 1V/oct in Grids mode, so the stock voltage-range function is not used here.
- `X MODE` button **saves** the current bassline seed into the active bank slot.
- Patch a clock to the **X clock input** to drive the bassline from an external clock (see below).

#### External clocking

By default the bassline is locked to the internal Grids clock. Patch a clock to the **X clock input** and the bassline follows it instead. The `RATE` knob then doubles as a clock divider / multiplier for the bassline — exactly like it does for the drums when the `t` clock is patched:

- **12 o'clock (center)**: neutral. The external clock is interpreted the same way the internal clock is, so feeding one clock into both the `t` and `X` inputs keeps the drums and the bassline in perfect lockstep.
- **CCW / CW**: divides or multiplies the external clock from ¼× up to 4× (musical ratios 1/4, 1/3, 1/2, 2/3, 1, 3/2, 2, 3, 4), matching the drum clock. The `T RANGE` setting (0.25× / 4×) is folded in as well.

If the external clock stops, the bassline gate is released so a stalled upstream sequencer can't latch a downstream VCA or envelope open.

#### Pattern bank

Bassline seeds can be saved into a **4-slot bank** that persists in flash, so you can build up a handful of patterns and switch between them live:

- **`X RANGE` button**: short-press to step through the four slots (1 → 2 → 3 → 4 → 1). Selecting a slot that holds a saved seed loads it immediately; empty slots are skipped and leave the current pattern untouched.
- **`X MODE` button**: short-press to **save** the current bassline seed into the active slot.
- The `X CONTROL MODE` LED shows the active slot at a glance — **green / yellow / red / blinking-green** for slots 1–4. After a save or select, the `X CONTROL MODE` and `X RANGE` LEDs flash the slot color for about a second to confirm.

Outputs:

- **X1**: 5V / 0V clock square wave (16th notes; mirrors the external clock when one is patched).
- **X2**: 1V/oct pitch CV, slewed on slid steps.
- **X3**: gate (high while the step is gated; held through slides).
- **Y**: accent gate (high only when the step is both accented and gated).

## Markov and Toggle T-Models

Beyond Grids, this firmware exposes two more T-section models. They are plain T-section generators — the X-section keeps its normal Marbles behavior — and they live as "dark" (unlit) slots one step past the visible models.

**Reaching them:** short-press `T MODEL` to cycle the visible models (green → yellow → red); one more short press past `DRUMS` (red) lands on **Markov**, with the T-model LED **unlit**. A **long-press** from there flips between **Markov** (unlit) and **Toggle** (a brief green flash). A short press from either dark state exits back to the first model.

### Markov

Probabilistic gate patterns generated by a Markov chain with an 8-step history — the stock Mutable Instruments Markov generator, now selectable. The usual T-section controls apply: `RATE` sets the tempo, `BIAS` shapes pattern density / character, `JITTER` adds timing swing, and the `T DEJA VU` button (with the `DEJA VU LENGTH` knob) loops and locks a pattern. `T RANGE` sets the tempo range. The T-model LED stays dark while Markov is active.

### Toggle

A deterministic 3-way ring counter: exactly one of T1 / T2 / T3 fires on each clock tick, cycling T1 → T2 → T3 → T1 (the Branches toggle mode extended to three outputs). `RATE` sets the tempo and `JITTER` adds swing; `BIAS` and `T DEJA VU` are unused in this mode. The T-model LED gives a brief green flash to distinguish Toggle from Markov's fully-dark slot.

## Parameters

T-section (Grids mode):

|  Sub-mode   |       RATE Knob       |        BIAS Knob        |       JITTER Knob       |     RATE CV     |     BIAS CV     |    JITTER CV    |                              DEJA VU Knob                              |          DEJA VU LENGTH Knob          |              DEJA VU CV               |     DEJA VU Button      |
|:-----------:|:---------------------:|:-----------------------:|:-----------------------:|:---------------:|:---------------:|:---------------:|:----------------------------------------------------------------------:|:-------------------------------------:|:-------------------------------------:|:-----------------------:|
|  **Drums**  | Tempo / clock division | Drums map X coordinate  | Drums map Y coordinate  |  BD density CV  |  SD density CV  |  HH density CV  |  CCW from center: chaos / randomness on the drum map. CW: no effect.   |               _unused_                | Rising edge: reset both T and X to step 0 |   OFF = Drums sub-mode  |
| **Euclidean** | Tempo / clock division |        _unused_         |        _unused_         |  BD density CV  |  SD density CV  |  HH density CV  | CCW from center: T2 (SD) random fills. CW from center: pattern rotation. | Shared Euclidean length (1–16 steps)  | Rising edge: reset both T and X to step 0 | ON / LOCKED = Euclidean |

X-section (Grids mode — TB-3PO bassline):

|                  X SPREAD Knob + CV                   |                X BIAS Knob + CV                 |         X STEPS Knob + CV          |    X DEJA VU Switch     |          X SCALE          |         X RANGE Button          |         X MODE Button          |
|:-----------------------------------------------------:|:-----------------------------------------------:|:----------------------------------:|:-----------------------:|:-------------------------:|:-------------------------------:|:------------------------------:|
| Bassline density of gates / slides / accents (bipolar) | Bassline transpose, ±18 semitones (CV: 1V/oct)  | Bassline step length, 1 to 32 steps | Seed lock / reseed / commit | Scale (reuses X scale selector) | Step through the 4-slot pattern bank | Save current seed to active slot |

| Output |              Voltage              |                            Source                            |
|:------:|:---------------------------------:|:------------------------------------------------------------:|
|   T1   |               Gate                |                       Grids BD drum gate                       |
|   T2   |               Gate                |             Grids SD drum gate (master gate output)             |
|   T3   |               Gate                |                       Grids HH drum gate                       |
|   X1   |          5V / 0V clock           |   Grids step clock (16th notes, locked to the drum engine; mirrors the X clock input when patched)   |
|   X2   |             1V/oct              | TB-3PO pitch CV, scale-quantized, slewed on slid steps     |
|   X3   |               Gate                |       TB-3PO gate (held through slides)                       |
|   Y    |               Gate                |          TB-3PO accent (high on accented + gated steps)         |

## Change Log

### Symbiote 0.2.0

New features:

- **External clocking of the TB-3PO bassline**: patch a clock to the X clock input and the bassline follows it instead of the internal Grids clock. The `RATE` knob acts as a clock divider / multiplier (¼× to 4×, neutral 1:1 at 12 o'clock) in the same musical ratios as the drum clock, with `T RANGE` folded in — so one clock shared between the `t` and `X` inputs keeps drums and bassline locked together.
- **4-slot pattern bank** for bassline seeds, persisted in flash: `X MODE` saves the current seed to the active slot, `X RANGE` steps through the four slots and recalls a saved seed instantly (empty slots are skipped). The `X CONTROL MODE` LED shows the active slot color, with a one-second flash confirmation on save / select.
- **Two new standalone T-section models**, reachable as "dark" slots past `DRUMS` on the `T MODEL` button: a **Markov** chain gate generator (8-step history; LED unlit) and a deterministic **Toggle** ring counter that fires one of T1 / T2 / T3 per clock tick (LED brief green flash). Long-press flips between the two; short-press exits back to the first model. The X-section is unaffected by both.

Fixes:

- The external bassline clock now respects the `RATE` ratio and stays in lockstep with the drums when sharing a clock, instead of running ~6× too fast and ignoring the rate knob.
- When the external bassline clock stops, the gate is released so a stalled upstream clock can no longer latch downstream VCAs / envelopes open.

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
