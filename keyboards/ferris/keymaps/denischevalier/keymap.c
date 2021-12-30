// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ferris_layers {
  _ALPHA,
  _ACCENTS,
  _SYMBOLS1,
  _SYMBOLS2,
  _LAYER_SWITCH,
  _NUMPAD,
  _MIDI,
  _NAV,
  _QWERTY,
  _EMOJI
};

enum ferris_tap_dances {
  TD_Q_ESC
};

#define KC_LST LSFT_T(KC_TAB)

// Unicode map
enum unicode_names {
  // Accents
  _LEDIAE,
  _LECIRC,
  _LOE,
  _LOCIRC,
  _LUDIAE,
  _LUGRAV,
  _LUCIRC,
  _LEGRAV,
  _LEACUT,
  _LAGRAV,
  _LICIRC,
  _LCCEDI,
  _LACIRC,
  _LIDIAE,
  _LNTILD,
  _UEDIAE,
  _UECIRC,
  _UOE,
  _UOCIRC,
  _UUDIAE,
  _UUGRAV,
  _UUCIRC,
  _UEGRAV,
  _UEACUT,
  _UAGRAV,
  _UICIRC,
  _UCCEDI,
  _UACIRC,
  _UIDIAE,
  _UNTILD,
  // Single symbols
  _SBROPE,
  _SBRCLO,
  _COMMA,
  _SEMICOLON,
  _APOST,
  _EUR,
  _MIDDOT,
  _ANTISLASH,
  _BACKTICK,
  // Emojis
  _FIRE,
  _RAISING_HANDS,
  _OK_HAND,
  _WAVING_HAND,
  _PARTY_POPPER,
  _BANK,
  _OPEN_MOUTH,
  _FACE_PALM,
  _PLUS_ONE,
  _CLAP,
  _GRINNING_FACE,
  _ROFL,
  _WINKING_FACE,
  _THINKING_FACE,
  _SCREAM,
  _ANGRY,
  _MINUS_ONE,
  _PRAYING_HANDS,
  _TICK,
  _CROSS,
  _MONOCLE
};

const uint32_t PROGMEM unicode_map[] = {
  [_LEDIAE] = 0xEB, // ë
  [_LECIRC] = 0xEA, // ê
  [_LOE] = 0x153, // œ
  [_LOCIRC] = 0xF4, // ô
  [_LUDIAE] = 0xFC, // ü
  [_LUGRAV] = 0xF9, // ù
  [_LUCIRC] = 0xFB, // û
  [_LEGRAV] = 0xE8, // è
  [_LEACUT] = 0xE9, // é
  [_LAGRAV] = 0xE0, // à
  [_LICIRC] = 0xEE, // î
  [_LCCEDI] = 0xE7, // ç
  [_LACIRC] = 0xE2, // â
  [_LIDIAE] = 0xEF, // ï
  [_LNTILD] = 0xF1, // ñ
  [_UEDIAE] = 0xCB, // Ë
  [_UECIRC] = 0xCA, // Ê
  [_UOE] = 0x152, // Œ
  [_UOCIRC] = 0xD4, // Ô
  [_UUDIAE] = 0xDC, // Ü
  [_UUGRAV] = 0xD9, // Ù
  [_UUCIRC] = 0xDB, // Û
  [_UEGRAV] = 0xC8, // È
  [_UEACUT] = 0xC9, // É
  [_UAGRAV] = 0xC0, // À
  [_UICIRC] = 0xCE, // Î
  [_UCCEDI] = 0xC7, // Ç
  [_UACIRC] = 0xC2, // Â
  [_UIDIAE] = 0xCF, // Ï
  [_UNTILD] = 0xF1, // Ñ
  [_SBROPE] = 0x5B, // [
  [_SBRCLO] = 0x5D, // ]
  [_COMMA] = 0x2C, // ,
  [_SEMICOLON] = 0x3B, // ;
  [_APOST] = 0x27, // '
  [_EUR] = 0x20AC, // €
  [_MIDDOT] = 0xB7, // ·
  [_ANTISLASH] = 0x5C, // "\"
  [_BACKTICK] = 0x60, // `
  [_FIRE] = 0x1F525, // 🔥
  [_RAISING_HANDS] = 0x1F64C, // 🙌
  [_OK_HAND] = 0x1F44C, // 👌
  [_WAVING_HAND] = 0x1F44B, // 👋
  [_PARTY_POPPER] = 0x1F389, // 🎉
  [_BANK] = 0x1F3E6, // 🏦
  [_OPEN_MOUTH] = 0x1F62E, // 😮
  [_FACE_PALM] = 0x1F926, // 🤦
  [_PLUS_ONE] = 0x1F44D, // 👍
  [_CLAP] = 0x1F44F, // 👏
  [_GRINNING_FACE] = 0x1F600, // 😀
  [_ROFL] = 0x1F923, // 🤣
  [_WINKING_FACE] = 0x1F609, // 😉
  [_THINKING_FACE] = 0x1F914, // 🤔
  [_SCREAM] = 0x1F631, // 😱
  [_ANGRY] = 0x1F621, // 😡
  [_MINUS_ONE] = 0x1F44E, // 👎
  [_PRAYING_HANDS] = 0x1F64F, // 🙏
  [_TICK] = 0x2705, // ✅
  [_CROSS] = 0x274E, // ❎
  [_MONOCLE] = 0x1F9D0, // 🧐
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ALPHA] = LAYOUT(
    OSL(_SYMBOLS1), KC_F, KC_P, KC_O, KC_Y,    KC_G,         KC_D,         KC_U,         KC_R,         KC_Z,
    KC_LSFT,        KC_X, KC_E, KC_A, KC_I,    LCTL_T(KC_H), LALT_T(KC_J), LGUI_T(KC_K), RALT_T(KC_L), LT(_LAYER_SWITCH,KC_M),
    OSL(_ACCENTS),  KC_V, KC_C, KC_B, KC_T,    KC_N,         KC_W,         KC_Q,         KC_S,         KC_ESC,
                              KC_TAB, KC_SPC, KC_ENT, KC_BSPC
  ),
  [_ACCENTS] = LAYOUT(
    OSL(_SYMBOLS1), XP(_LEDIAE,_UEDIAE), XP(_LECIRC,_UECIRC), XP(_LOE,_UOE),       XP(_LOCIRC,_UOCIRC),    KC_NO,               XP(_LUDIAE,_UUDIAE), XP(_LUGRAV,_UUGRAV), XP(_LUCIRC,_UUCIRC), KC_NO,
    KC_LSFT,        XP(_LEGRAV,_UEGRAV), XP(_LEACUT,_UEACUT), XP(_LAGRAV,_UAGRAV), XP(_LICIRC,_UICIRC),    OSM(MOD_LCTL),       OSM(MOD_LALT),       OSM(MOD_LGUI),       OSM(MOD_RALT),       MO(_LAYER_SWITCH),
    KC_NO,          KC_NO,               XP(_LCCEDI,_UCCEDI), XP(_LACIRC,_UACIRC), XP(_LIDIAE,_UIDIAE),    XP(_LNTILD,_UNTILD), KC_NO,               KC_NO,               KC_NO,               KC_NO,
                                                         KC_TAB, KC_SPC, KC_ENT, KC_BSPC
  ),
  [_SYMBOLS1] = LAYOUT(
    KC_P0,         KC_P1,      KC_P2,      KC_P3,   KC_P4,      KC_P5,           KC_P6,             KC_P7,           KC_P8,           KC_P9,
    MO(_SYMBOLS2), X(_SBROPE), X(_SBRCLO), KC_LPRN, KC_RPRN,    LCTL_T(KC_PDOT), LALT_T(X(_COMMA)), LGUI_T(KC_EXLM), RALT_T(KC_QUES), LT(_LAYER_SWITCH,X(_SEMICOLON)),
    KC_NO,         KC_LT,      KC_GT,      KC_LCBR, KC_RCBR,    KC_COLN,         KC_DQUO,           X(_APOST),        KC_AT,           KC_AMPR,
                                               KC_TAB, KC_SPC, KC_ENT, KC_BSPC
  ),
  [_SYMBOLS2] = LAYOUT(
    KC_F1,   KC_F2,      KC_F3,   KC_F4,   KC_F5,            KC_F6,           KC_F7,           KC_F8,            KC_F9,           KC_F10,
    KC_TRNS, KC_HASH,    KC_DLR,  X(_EUR), KC_PERC,          LCTL_T(KC_PSLS), LALT_T(KC_ASTR), LGUI_T(KC_PMNS),  RALT_T(KC_PLUS), LT(_LAYER_SWITCH,KC_F11),
    KC_NO,   X(_MIDDOT), KC_TILD, KC_PIPE, X(_ANTISLASH),    X(_BACKTICK),    KC_CIRC,         KC_UNDS,          KC_PEQL,         KC_F12,
                                            KC_TAB, KC_SPC, KC_ENT, KC_BSPC
  ),
  [_LAYER_SWITCH] = LAYOUT(
    KC_SLCK,    KC_PSCR, KC_INS, KC_DEL, KC_ESC,          KC_NO,       KC_NO,     KC_NO,    KC_NO,       KC_NO,
    KC_NO,      KC_NO,   KC_NO,  KC_NO,  TO(_EMOJI),      TO(_NUMPAD), TO(_MIDI), TO(_NAV), TO(_QWERTY), KC_TRNS,
    TO(_ALPHA), KC_NO,   KC_NO,  KC_NO,  KC_NO,           KC_NO,       KC_NO,     KC_NO,    KC_NO,       KC_NO,
                                        KC_TAB, KC_SPC, KC_ENT, KC_BSPC
  ),
  [_NUMPAD] = LAYOUT(
    KC_LCBR,    KC_CIRC, KC_AMPR, X(_SBROPE), X(_SBRCLO),    KC_PAST,         KC_P7,         KC_P8,         KC_P9,         KC_PPLS,
    KC_RCBR,    KC_LT,   KC_GT,   KC_LPRN,    KC_RPRN,       LCTL_T(KC_PSLS), LALT_T(KC_P4), LGUI_T(KC_P5), RALT_T(KC_P6), LT(_LAYER_SWITCH,KC_PMNS),
    TO(_ALPHA), KC_COLN, KC_EXLM, KC_PERC,    KC_PDOT,       KC_P0,           KC_P1,         KC_P2,         KC_P3,         KC_PEQL,
                                            KC_TAB, KC_SPC, KC_ENT, KC_BSPC
  ),
  [_MIDI] = LAYOUT(
    KC_NO,      KC_NO,   MI_Db_4, MI_Eb_4, KC_NO,     MI_Gb_4, MI_Ab_5, MI_Bb_5, KC_NO,  KC_NO,
    MI_OCTD,    MI_C_4,  MI_D_4,  MI_E_4,  MI_F_4,    MI_G_4,  MI_A_5,  MI_B_5,  MI_C_5, MI_OCTU,
    TO(_ALPHA), KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
                                     KC_TAB, KC_SPC, KC_ENT, KC_BSPC
  ),
  [_NAV] = LAYOUT(
    KC_VOLD,    KC_VOLU, KC_BTN1, KC_MS_U, KC_BTN2,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_CUT,
    KC_MUTE,    KC_MSTP, KC_MS_L, KC_MS_D, KC_MS_R,    KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, LT(_LAYER_SWITCH,KC_COPY),
    TO(_ALPHA), KC_MPLY, KC_ACL0, KC_ACL1, KC_ACL2,    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,  KC_PSTE,
                                      KC_TAB, KC_SPC, KC_ENT, KC_BSPC
  ),
  [_QWERTY] = LAYOUT(
    KC_Q, KC_W, KC_E, KC_R, KC_T,    KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G,    LCTL_T(KC_H), LALT_T(KC_J), LGUI_T(KC_K), RALT_T(KC_L), LT(_LAYER_SWITCH,KC_SCLN),
    KC_Z, KC_X, KC_C, KC_V, KC_B,    KC_N,         KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
            LSFT_T(KC_TAB), KC_SPC, KC_ENT, KC_BSPC
  ),
  [_EMOJI] = LAYOUT(
    KC_NO,      KC_NO,          X(_FIRE),      X(_RAISING_HANDS), X(_OK_HAND),          X(_WAVING_HAND),   KC_NO,     KC_NO,            X(_PARTY_POPPER),  KC_NO,
    X(_BANK),   X(_OPEN_MOUTH), X(_FACE_PALM), X(_PLUS_ONE),      X(_CLAP),             X(_GRINNING_FACE), X(_ROFL),  X(_WINKING_FACE), X(_THINKING_FACE), MO(_LAYER_SWITCH),
    TO(_ALPHA), X(_SCREAM),     X(_ANGRY),     X(_MINUS_ONE),     X(_PRAYING_HANDS),    X(_TICK),          X(_CROSS), KC_NO,            X(_MONOCLE),       KC_NO,
                                                               LSFT_T(KC_TAB), KC_SPC, KC_ENT, KC_BSPC
  ),
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};
