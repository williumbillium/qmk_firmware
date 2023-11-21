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

/*
 * 2023/11/21
 * Convert from Mac to Windows
 */

#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _FUNC,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define FUNC MO(_FUNC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   '  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | Esc  | Tab  | /Enter  /       \BackSp\  |Space |Delete|      |
 *                   |      | FUNC |RAISE |/       /         \      \ |LOWER |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  XXXXXXX, XXXXXXX,      XXXXXXX,     XXXXXXX,     XXXXXXX,          XXXXXXX,                             XXXXXXX,           XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,        XXXXXXX,
  XXXXXXX, KC_Q,         KC_W,        KC_E,        KC_R,             KC_T,                                KC_Y,              KC_U,        KC_I,        KC_O,        KC_P,           XXXXXXX,
  XXXXXXX, GUI_T(KC_A),  ALT_T(KC_S), CTL_T(KC_D), SFT_T(KC_F),      KC_G,                                KC_H,              SFT_T(KC_J), CTL_T(KC_K), ALT_T(KC_L), GUI_T(KC_QUOT), XXXXXXX,
  XXXXXXX, KC_Z,         KC_X,        KC_C,        KC_V,             KC_B,              XXXXXXX, XXXXXXX, KC_N,              KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,        XXXXXXX,
                                      XXXXXXX,     LT(_FUNC,KC_ESC), LT(_RAISE,KC_TAB), KC_ENT,  KC_BSPC, LT(_LOWER,KC_SPC), KC_DEL,      XXXXXXX
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      | Back | Fwd  |VolUp |                    | Home |CTLEnd|CTL+Hm| End  |Scrnst|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |VolDn |-------.    ,-------| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |PrvDsk|NxtDsk| Mute |-------|    |-------|CTL+Lt| PgDn | PgUp |CTL+Rt|MaxWin|      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | Esc  | Tab  | /Enter  /       \BackSp\  |Space |Delete|      |
 *                   |      | FUNC |RAISE |/       /         \      \ |LOWER |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______,       _______,        _______,                   _______,    _______,        _______,      _______,        _______,    _______,
  _______, _______, _______, KC_BTN4,       KC_BTN5,        KC_VOLU,                   KC_HOME,    C(KC_END),      C(KC_HOME),   KC_END,         KC_PSCR,    _______,
  _______, KC_LGUI, KC_LALT, KC_LCTL,       KC_LSFT,        KC_VOLD,                   KC_LEFT,    SFT_T(KC_DOWN), CTL_T(KC_UP), ALT_T(KC_RGHT), KC_LGUI,    _______,
  _______, _______, _______, G(C(KC_LEFT)), G(C(KC_RIGHT)), KC_MUTE, _______, _______, C(KC_LEFT), KC_PGDN,        KC_PGUP,      C(KC_RGHT),     G(KC_UP), _______,
                             _______,       _______,        _______, _______, _______, _______,    _______,        _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |ADJUST|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  !   |  @   |  #   |  $   |  %   |                    |  +   |  7   |  8   |  9   |  =   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  ^   |  &   |  *   |  (   |  )   |-------.    ,-------|  -   |  4   |  5   |  6   |  ;   |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  ~   |  `   |  _   |  [   |  ]   |-------|    |-------|  0   |  1   |  2   |  3   |  \   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | Esc  | Tab  | /Enter  /       \Backsp\  |Space |Delete|      |
 *                   |      | FUNC | RAISE|/       /         \      \ |LOWER |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______,     _______,     _______,     _______,        _______,
  _______,     KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_PLUS, KC_7,        KC_8,        KC_9,        KC_EQL,         _______,
  _______,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,                     KC_MINS, SFT_T(KC_4), CTL_T(KC_5), ALT_T(KC_6), GUI_T(KC_SCLN), _______,
  _______,     KC_TILD, KC_GRV,  KC_UNDS, KC_LBRC, KC_RBRC,  _______, _______,  KC_0,    KC_1,        KC_2,        KC_3,        KC_BSLS,        _______,
                                 _______, _______, _______,  _______, _______,  _______, _______,     _______
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGBTOG|RGBHUI|RGBSAI|RGBVAI|      |      |-------.    ,-------|      |  F4  |  F5  |  F6  | F11  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |RGBMOD|RGBHUD|RGBSAD|RGBVAD|      |      |-------|    |-------|      |  F1  |  F2  |  F3  | F12  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | Esc  | Tab  | /Enter  /       \BackSp\  |Space |Delete|      |
 *                   |      | FUNC | RAISE|/       /         \      \ |LOWER |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_FUNC] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
  RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  XXXXXXX,
  RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,  XXXXXXX,
                                 _______, _______, _______, _______, _______,  _______, _______, _______
  )
};


