#pragma once

#ifdef AUDIO_ENABLE
  #define STARTUP_SONG SONG(Q__NOTE(_E6), Q__NOTE(_G6), Q__NOTE(_E7), Q__NOTE(_C7), Q__NOTE(_D7), H__NOTE(_G7))
#endif

#define MUSIC_MASK (keycode != KC_NO)

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
// #define MIDI_ENABLE_STRICT 1

/* Enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/
#define MIDI_BASIC

/* Enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
// #define MIDI_ADVANCED

/* Override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
// #define MIDI_TONE_KEYCODE_OCTAVES 2

#define NO_ACTION_ONESHOT
#define NO_ACTION_TAPPING

#define GRAVE_ESC_GUI_OVERRIDE
