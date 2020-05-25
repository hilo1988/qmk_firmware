/* Copyright 2018 Eucalyn
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
#include"keymap_jp.h"

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

enum custom_keycodes {
  RGBRST = SAFE_RANGE
};


// CMD + CTL
#define CC_T(kc) MT(MOD_LGUI | MOD_LCTL, kc)
#define UNDER_SCORE LSFT(KC_MINS)

#define LAYER_MAC  0
#define LAYER_10KEY  1
#define LAYER_MOD  2
#define LAYER_WIN  3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   // mac
  [LAYER_MAC] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,    KC_BSPC,  \
    CC_T(KC_TAB),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,    KC_O,    CC_T(KC_P),    KC_LBRC, KC_RBRC, KC_BSLS,  \
    KC_LCTL,     KC_A,    KC_S,    KC_D,    LT(LAYER_10KEY, KC_F),    SGUI_T(KC_G),                SGUI_T(KC_H),    LT(LAYER_10KEY, KC_J),    KC_K,    KC_L,    CTL_T(KC_SCLN), KC_QUOT,        KC_ENT,   \
    KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, LSFT(UNDER_SCORE),   KC_UP,  LT(LAYER_MOD, KC_GRV),   \
    LGUI_T(KC_ESC),    KC_LGUI,    KC_LALT,    CTL_T(KC_LANG2),   GUI_T(KC_SPC),           GUI_T(KC_SPC),  ALT_T(KC_LANG1),  CTL_T(JP_YEN),               KC_LEFT,KC_DOWN,KC_RGHT \
  ),
  // mac 10キー系
  [LAYER_10KEY] = LAYOUT( \
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,    KC_DEL, \
    _______,   _______,  KC_UP, KC_UP, _______, XXXXXXX,                          XXXXXXX,        KC_7,       KC_8,      KC_9,    XXXXXXX, XXXXXXX, XXXXXXX, JP_PIPE, \
    KC_CAPS,     KC_LEFT, KC_DOWN, KC_RGHT, _______, XXXXXXX,                      XXXXXXX,     KC_4,        RSFT_T(KC_5),        ALT_T(KC_6), KC_COLON, KC_GRV,        XXXXXXX, \
    _______,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              XXXXXXX,    KC_1,      KC_2,        KC_3   , XXXXXXX, KC_TILDE, KC_PGUP, _______, \
    XXXXXXX,   _______,    _______,    _______,    KC_LANG2,                                              GUI_T(KC_0),      KC_0,         KC_DOT,                                           KC_HOME, KC_PGDN, KC_END \
  ),
  // LEDとか
  [LAYER_MOD] = LAYOUT( \
      XXXXXXX,  KC_TRNS,   TO(LAYER_WIN),   XXXXXXX,   XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
      RGB_TOG,   RGBRST,  RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
      XXXXXXX,     RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
      XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PGUP,  _______, \
      XXXXXXX,   _______,    _______,    _______,    XXXXXXX,                        XXXXXXX, XXXXXXX,     XXXXXXX,                       KC_HOME, KC_PGDN, KC_END \
    ),
    // windows
    [LAYER_WIN] = LAYOUT( \
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,    KC_BSPC,  \
        CC_T(KC_TAB),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,    KC_O,    CC_T(KC_P),    KC_LBRC, KC_RBRC, KC_BSLS,  \
        KC_LCTL,     KC_A,    KC_S,    KC_D,    LT(1, KC_F),    SGUI_T(KC_G),                SGUI_T(KC_H),    LT(1, KC_J),    KC_K,    KC_L,    CTL_T(KC_SCLN), KC_QUOT,        KC_ENT,   \
        KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(UNDER_SCORE),   KC_UP,  TO(0),   \
        KC_LGUI,    KC_LCTL,    KC_LALT,    CTL_T(KC_F13),   CTL_T(KC_SPC),           CTL_T(KC_SPC),  ALT_T(KC_F14),  CTL_T(JP_YEN),               KC_LEFT,KC_DOWN,KC_RGHT \
    ),

};

// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;

  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
