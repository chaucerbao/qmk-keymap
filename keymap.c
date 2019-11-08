/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum preonic_layers {
  _QWERTY,
  _SUPER,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  SUPER = SAFE_RANGE,
  LOWER,
  RAISE,
  DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_preonic_1x2uC( \
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,  KC_5,   KC_6,  KC_7,    KC_8,    KC_9,   KC_0,    KC_BSPC,   \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,  KC_U,    KC_I,    KC_O,   KC_P,    KC_BSLASH, \
      SUPER,   KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,  KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,   \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,  KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT, \
      KC_LCTL, XXXXXXX, KC_LALT, KC_LGUI, LOWER, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT  \
      ),

  [_SUPER] = LAYOUT_preonic_1x2uC( \
      KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_DEL,  \
      _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_LPRN, KC_RPRN, \
      SUPER,   _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_LCBR, KC_RCBR, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, \
      _______, _______, _______, _______, LOWER,   _______, RAISE,   _______, _______, _______, _______  \
      ),

  [_LOWER] = LAYOUT_preonic_1x2uC( \
      _______, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, _______, _______, _______, _______, _______, KC_BSPC, KC_PSLS, KC_PAST, KC_PMNS, \
      _______, _______,         _______,         _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, \
      SUPER,   _______,         _______,         _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PEQL, \
      _______, _______,         _______,         _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, \
      _______, _______,         _______,         _______, LOWER,   _______, RAISE,   KC_P0,   _______, KC_PDOT, _______  \
      ),

  [_RAISE] = LAYOUT_preonic_1x2uC( \
      DYN_REC_STOP, DYN_REC_START1, DYN_REC_START2, _______,   _______, _______, _______, _______, _______, _______, _______, _______, \
      _______,      _______,        _______,        _______,   _______, _______, _______, _______, _______, _______, _______, _______, \
      SUPER,        _______,        _______,        _______,   _______, _______, _______, _______, _______, _______, _______, _______, \
      _______,      KC__MUTE,       KC__VOLDOWN,    KC__VOLUP, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______,      _______,        _______,        _______,   LOWER,   _______, RAISE,   _______, _______, _______, _______  \
      ),

  [_ADJUST] = LAYOUT_preonic_1x2uC( \
      RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DEBUG,   \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      SUPER,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, LOWER,   _______, RAISE,   _______, _______, _______, _______  \
      )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  switch (keycode) {
    case SUPER:
      if (record->event.pressed) {
        layer_on(_SUPER);
      } else {
        layer_off(_SUPER);
      }

      return false;

    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }

      return false;

    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }

      return false;
  }

  return true;
};
