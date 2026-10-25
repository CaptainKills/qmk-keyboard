#include QMK_KEYBOARD_H

// Mod-Tap
#define MOD_A    MT(MOD_LGUI, KC_A)
#define MOD_S    MT(MOD_LALT, KC_S)
#define MOD_D    MT(MOD_LSFT, KC_D)
#define MOD_F    MT(MOD_LCTL, KC_F)
#define MOD_J    MT(MOD_RCTL, KC_J)
#define MOD_K    MT(MOD_RSFT, KC_K)
#define MOD_L    MT(MOD_RALT, KC_L)
#define MOD_SCLN MT(MOD_RGUI, KC_SEMICOLON)

// Layer-Tap
#define LAY_ESC  LT(L_KBD, KC_ESC)
#define LAY_SPC  LT(L_KBD, KC_SPACE)
#define LAY_ENT  LT(L_KBD, KC_ENTER)
#define LAY_BSPC LT(L_KBD, KC_BACKSPACE)

enum layer_t {
    L_KBD, // Alpha Layer
    L_SYM, // Symbol Layer
    L_FUN, // Function Layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[L_KBD] = LAYOUT_split_3x5_2(
      KC_Q  , KC_W  , KC_E  , KC_R    , KC_T    ,     KC_Y    , KC_U     , KC_I    , KC_O   , KC_P    ,
      MOD_A , MOD_S , MOD_D , MOD_F   , KC_G    ,     KC_H    , MOD_J    , MOD_K   , MOD_L  , MOD_SCLN,
      KC_Z  , KC_X  , KC_C  , KC_V    , KC_B    ,     KC_N    , KC_M     , KC_COMM , KC_DOT , KC_SLSH ,
                              LAY_ESC , LAY_SPC ,     LAY_ENT , LAY_BSPC
),

[L_SYM] = LAYOUT_split_3x5_2(
      KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
      KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
      KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
                                    KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS
),

[L_FUN] = LAYOUT_split_3x5_2(
      KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
      KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
      KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
                                    KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS
)
};
