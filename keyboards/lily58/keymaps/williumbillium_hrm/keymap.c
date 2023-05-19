 /* Copyright 2020 Naoki Katahira
  * Copyright 2023 Elliot Powell
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

/*
 * 2023/03/25
 * First keymap with all three layers
 * Mod tap on thumbs
 * Homerow mods
 */

#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | `    |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |E/CTRL|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   '  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | Esc  | Tab  | /Enter  /       \BackSp\  |Space |Delete|      |
 *                   |      | LGUI |RAISE |/       /         \      \ |LOWER |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  XXXXXXX,       KC_1,         KC_2,        KC_3,        KC_4,          KC_5,                                KC_6,              KC_7,        KC_8,        KC_9,        KC_0,           XXXXXXX,
  KC_TAB,        KC_Q,         KC_W,        KC_E,        KC_R,          KC_T,                                KC_Y,              KC_U,        KC_I,        KC_O,        KC_P,           KC_BSLS,
  CTL_T(KC_ESC), CTL_T(KC_A),  ALT_T(KC_S), GUI_T(KC_D), SFT_T(KC_F),   KC_G,                                KC_H,              SFT_T(KC_J), GUI_T(KC_K), ALT_T(KC_L), SFT_T(KC_QUOT), KC_QUOT,
  KC_LSFT,       KC_Z,         KC_X,        KC_C,        KC_V,          KC_B,              KC_LBRC, KC_RBRC, KC_N,              KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,        KC_RSFT,
                                            XXXXXXX,     GUI_T(KC_ESC), LT(_RAISE,KC_TAB), KC_ENT,  KC_BSPC, LT(_LOWER,KC_SPC), KC_DEL,      XXXXXXX
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      | Back | Fwd  |VolUp |                    |CMD+Lt|CMD+Dn|CMD+Up|CMD+Rt|Scrnst|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |PrvTab|NxtTab|VolDn |-------.    ,-------| Left | Down |  Up  |Right |MaxWin|      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |ShwDsk|PrvDsk|NxtDsk| Mute |-------|    |-------|ALT+Lt| PgDn | PgUp |ALT+Rt|      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | Esc  | Tab  | /Enter  /       \BackSp\  |Space |Delete|      |
 *                   |      | LGUI |RAISE |/       /         \      \ |LOWER |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______,      _______,     _______,                   _______,    _______,    _______,  _______,    _______,       _______,
  _______, _______, _______, KC_BTN4,      KC_BTN5,     KC_VOLU,                   G(KC_LEFT), G(KC_DOWN), G(KC_UP), G(KC_RGHT), G(S(KC_4)),    _______,
  _______, _______, _______, C(S(KC_TAB)), C(KC_TAB),   KC_VOLD,                   KC_LEFT,    KC_DOWN,    KC_UP,    KC_RGHT,    C(G(KC_Z)),    _______,
  _______, _______, KC_F11,  C(KC_LEFT),   C(KC_RIGHT), KC_MUTE, _______, _______, A(KC_LEFT), KC_PGDN,    KC_PGUP,  A(KC_RGHT), _______,       _______,

                             _______,      _______,     _______, _______, _______,  _______,   _______,    _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  !   |  @   |  #   |  $   |  %   |                    |  +   |  7   |  8   |  9   |  =   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  ^   |  &   |  *   |  (   |  )   |-------.    ,-------|  -   |  4   |  5   |  6   |  ;   |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |  ~   |  `   |  _   |  [   |  ]   |-------|    |-------|  0   |  1   |  2   |  3   |  \   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | Esc  | Tab  | /Enter  /       \Backsp\  |Space |Delete|      |
 *                   |      | LGUI | RAISE|/       /         \      \ |LOWER |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  TG(_ADJUST), _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_PLUS, KC_7,    KC_8,    KC_9,    KC_EQL,  _______,
  _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,                     KC_MINS, KC_4,    KC_5,    KC_6,    KC_SCLN, _______,
  _______, KC_TILD, KC_GRV,  KC_UNDS, KC_LBRC, KC_RBRC,  _______, _______,  KC_0,    KC_1,    KC_2,    KC_3,    KC_BSLS,  _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGBTOG|RGBHUI|RGBSAI|RGBVAI|      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |RGBMOD|RGBHUD|RGBSAD|RGBVAD|      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | Alt  | LGUI | Tab  | /Enter  /       \BackSp\  |Space |Delete|      |
 *                   |      |      | RAISE|/       /         \      \ |LOWER |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  TG(_ADJUST), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};


