const float w1 = osc_w0f_for_note(((params->pitch)>>8) + oscillator.semitone, params->pitch & 0xFF);

...

sw1 = w1 / oscillator.undertone1;
sw2 = w1 / oscillator.undertone2;