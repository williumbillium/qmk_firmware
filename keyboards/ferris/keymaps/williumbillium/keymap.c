/* Copyright 2024 William Law
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

enum layer_number {
  _GRAPHITE = 0,
  _QWERTY,
  _NAV,
  _NUM,
  _SYM,
  _FUNC,
};

// Thumb mods
#define NUM_TAB LT(_NUM,KC_TAB)
#define NAV_SPC LT(_NAV,KC_SPC)
#define SYM_BSPC LT(_SYM,KC_BSPC)
#define FUNC_ENT LT(_FUNC,KC_ENT)

// GRAPHITE layer home row mods
#define GUI_T_N GUI_T(KC_N)
#define ALT_T_R ALT_T(KC_R)
#define CTL_T_T CTL_T(KC_T)
#define SFT_T_S SFT_T(KC_S)
#define SFT_T_H SFT_T(KC_H)
#define CTL_T_A CTL_T(KC_A)
#define ALT_T_E ALT_T(KC_E)
#define GUI_T_I GUI_T(KC_I)

// QWERTY layer home row mods
#define GUI_T_A GUI_T(KC_A)
#define ALT_T_S ALT_T(KC_S)
#define CTL_T_D CTL_T(KC_D)
#define SFT_T_F SFT_T(KC_F)
#define SFT_T_J SFT_T(KC_J)
#define CTL_T_K CTL_T(KC_K)
#define ALT_T_L ALT_T(KC_L)
#define GUI_T_QOT GUI_T(KC_QUOT)

// NAV layer shortcuts
#define PRV_DSK G(C(KC_LEFT))
#define NXT_DSK G(C(KC_RIGHT))
#define CTL_END C(KC_END)
#define CTL_HOME C(KC_HOME)
#define CTL_LEFT C(KC_LEFT)
#define CTL_RGHT C(KC_RGHT)

// NAV layer home row mods
#define GUI_T_ESC GUI_T(KC_ESC)
#define ALT_T_RWD ALT_T(KC_MRWD)
#define CTL_T_PLY CTL_T(KC_MPLY)
#define SFT_T_FFD SFT_T(KC_MFFD)
#define SFT_T_DWN SFT_T(KC_DOWN)
#define CTL_T_UP CTL_T(KC_UP)
#define ALT_T_RGT ALT_T(KC_RGHT)
#define GUI_T_DEL GUI_T(KC_DEL)

// NUM layer home row mods
#define GUI_T_CRC GUI_T(KC_CIRC)
#define ALT_T_AMP ALT_T(KC_AMPR)
#define CTL_T_AST CTL_T(KC_ASTR)
#define SFT_T_LPR SFT_T(KC_LPRN)
#define SFT_T_4 SFT_T(KC_4)
#define CTL_T_5 CTL_T(KC_5)
#define ALT_T_6 ALT_T(KC_6)
#define GUI_T_SCN GUI_T(KC_SCLN)

// SYM layer home row mods
#define CTL_T_UKP MT(MOD_LCTL, POUND_KEY) // Tap = £, Hold = CTL

// FUNC layer home row mods
#define SFT_T_UCLX SFT_T(UC_LINX)
#define SFT_T_F4 SFT_T(KC_F4)
#define CTL_T_F5 SFT_T(KC_F5)
#define ALT_T_F6 SFT_T(KC_F6)
#define GUI_T_F11 SFT_T(KC_F11)


enum unicode_names {
    EURO,
    FCRSSD,
    POINTU,
    WORRIED,
    RSDEYE,
    HUNDRED,
    SMILE,
    OCIRC,
    UCIRC,
    LIGOE,
    POUND,
    FLDHND,
    THUMBU,
    CRYING,
    GRIM,
    FIRE,
    SMLEYE,
    AGRAVE,
    EGRAVE,
    ICIRC,
    CCEDIL,
    CLAP,
    POINTD,
    LDCRY,
    PEEK,
    PARTY,
    TRSJOY,
    ACIRC,
    ECIRC,
    EACUTE
};

const uint32_t PROGMEM unicode_map[] = {
    [EURO]     = 0x20AC,    // €
    [FCRSSD]   = 0x1F91E,   // Fingers crossed emoji
    [POINTU]   = 0x1F446,   // Backhand index pointing up
    [WORRIED]  = 0x1F61F,   // Worried emoji
    [RSDEYE]   = 0x1F928,   // Face with raised eyebrow
    [HUNDRED]  = 0x1F4AF,   // Hundred points
    [SMILE]    = 0x1F642,   // Slightly smiling face
    [OCIRC]    = 0x00F4,    // ô
    [UCIRC]    = 0x00FB,    // û
    [LIGOE]    = 0x0153,    // œ
    [POUND]    = 0x00A3,    // £
    [FLDHND]   = 0x1F64F,   // Folded hands
    [THUMBU]   = 0x1F44D,   // Thumbs up emoji
    [CRYING]   = 0x1F622,   // Crying emoji
    [GRIM]     = 0x1F62C,   // Grimmace emoji
    [FIRE]     = 0x1F525,   // Fire 
    [SMLEYE]   = 0x1F60A,   // Smiling face with smiling eyes
    [AGRAVE]   = 0x00E0,    // à
    [EGRAVE]   = 0x00E8,    // è
    [ICIRC]    = 0x00EE,    // î
    [CCEDIL]   = 0x00E7,    // ç
    [CLAP]     = 0x1F44F,   // Clapping hands
    [POINTD]   = 0x1F447,   // Backhand index pointing down
    [LDCRY]    = 0x1F62D,   // Loudly crying emoji
    [PEEK]     = 0x1FAE3,   // Face with peeking eye
    [PARTY]    = 0x1F389,   // Party popper
    [TRSJOY]   = 0x1F602,   // Tears of joy emoji
    [ACIRC]    = 0x00E2,    // â
    [ECIRC]    = 0x00EA,    // ê
    [EACUTE]   = 0x00E9     // é
};

// Only need these two if we are going to use MOD TAP
enum custom_keycodes {
    EURO_KEY = SAFE_RANGE,  // tap = €
    POUND_KEY  // tap = £
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case EURO_KEY:
                send_unicode_string("0x20AB"); // €
                return false; // skip further processing
            case POUND_KEY:
                send_unicode_string("0x00A2"); // £
                return false; // skip further processing
        }
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_GRAPHITE] = LAYOUT(
    KC_B,      KC_L,      KC_D,      KC_W,      KC_Z,                            KC_J,      KC_F,      KC_O,      KC_U,      KC_QUOT,
    GUI_T_N,   ALT_T_R,   CTL_T_T,   SFT_T_S,   KC_G,                            KC_Y,      SFT_T_H,   CTL_T_A,   ALT_T_E,   GUI_T_I,
    KC_Q,      KC_X,      KC_M,      KC_C,      KC_V,                            KC_K,      KC_P,      KC_COMM,   KC_DOT,    KC_SLSH,
                                                NUM_TAB,   FUNC_ENT,  SYM_BSPC,  NAV_SPC),

	[_QWERTY] = LAYOUT(
    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                            KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,
    GUI_T_A,   ALT_T_S,   CTL_T_D,   SFT_T_F,   KC_G,                            KC_H,      SFT_T_J,   CTL_T_K,   ALT_T_L,   GUI_T_QOT,
    KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,                            KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,
                                                KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS),

	[_NAV] = LAYOUT(
    KC_TRNS,   KC_TRNS,   MS_BTN4,   MS_BTN5,   KC_VOLU,                         KC_HOME,   CTL_END,   CTL_HOME,  KC_END,    KC_PSCR,
    GUI_T_ESC, ALT_T_RWD, CTL_T_PLY, SFT_T_FFD, KC_VOLD,                         KC_LEFT,   SFT_T_DWN, CTL_T_UP,  ALT_T_RGT, GUI_T_DEL,
    KC_TRNS,   KC_TRNS,   PRV_DSK,   NXT_DSK,   KC_MUTE,                         CTL_LEFT,  KC_PGDN,   KC_PGUP,   CTL_RGHT,  G(KC_UP),
                                                KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS),

	[_NUM] = LAYOUT(
    KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,                         KC_PPLS,   KC_7,      KC_8,      KC_9,      KC_EQL,
    KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RPRN,                         KC_MINS,   SFT_T_4,   CTL_T_5,   ALT_T_6,   GUI_T_SCN,
    KC_TILD,   KC_GRV,    KC_UNDS,   KC_LBRC,   KC_RBRC,                         KC_0,      KC_1,      KC_2,      KC_3,      KC_BSLS,
                                                KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS),

	[_SYM] = LAYOUT(
    UM(EURO),  UM(FCRSSD),UM(POINTU),UM(WORRIED),UM(RSDEYE),                     UM(HUNDRED),UM(SMILE), UM(OCIRC), UM(UCIRC), UM(LIGOE),
    UM(POUND), UM(FLDHND),UM(THUMBU),UM(CRYING),UM(GRIM),                        UM(FIRE),   UM(SMLEYE),UM(AGRAVE),UM(EGRAVE),UM(ICIRC),
    UM(CCEDIL),UM(CLAP),  UM(POINTD),UM(LDCRY), UM(PEEK),                        UM(PARTY),  UM(TRSJOY),UM(ACIRC), UM(ECIRC), UM(EACUTE),
                                                KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS),

	[_FUNC] = LAYOUT(
    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                           KC_NO,     KC_F7,     KC_F8,     KC_F9,     KC_F10,
    KC_NO,     KC_NO,     KC_NO,     UC_LINX,   TG(_QWERTY),                     KC_CAPS,   SFT_T_F4,  CTL_T_F5,  ALT_T_F6,  GUI_T_F11,
    KC_NO,     KC_NO,     KC_NO,     UC_WINC,   KC_NO,                           KC_NO,     KC_F1,     KC_F2,     KC_F3,     KC_F12,
                                                KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS)
};

