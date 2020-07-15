#pragma once

#ifdef AUDIO_ENABLE
  #define STARTUP_SONG SONG(PREONIC_SOUND)
#endif

#define MUSIC_MASK (keycode != KC_NO)
#define MIDI_BASIC

#define NO_ACTION_ONESHOT
#define NO_ACTION_TAPPING
