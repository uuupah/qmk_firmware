#include QMK_KEYBOARD_H

#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 4

#define _BASE 0
#define _FN1 1
#define _FN2 2
#define _FN3 3
#define _FN4 4
#define _FN5 5

// Tap-Hold keys
#define KC_ASFT MT(MOD_LSFT, KC_A)
#define KC_F_L3 LT(_FN3, KC_F)
#define KC_ZCTL MT(MOD_LCTL, KC_Z)
#define KC_XALT MT(MOD_LALT, KC_X)
#define KC_CGUI MT(MOD_LGUI, KC_C)
#define KC_V_L4 LT(_FN4, KC_V)
#define KC_SPL2 LT(_FN2, KC_SPC)
#define KC_B_L1 LT(_FN1, KC_B)
#define KC_N_L5 LT(_FN5, KC_N)
#define KC_MALT MT(MOD_RALT, KC_M)
#define KC_BSCT MT(MOD_RCTL, KC_BSPC)
#define KC_ENTS MT(MOD_RSFT, KC_ENT)
#define KC_ESCS MT(MOD_RSFT, KC_ESC)

#define KC_GUIC LGUI(KC_C)

#define win_l LGUI(KC_L)
//
#define vsc_fmt LSA(KC_F)

#define ctrl_z LCTL(KC_Z)
#define ctrl_x LCTL(KC_X)
#define ctrl_c LCTL(KC_C)
#define ctrl_v LCTL(KC_V)

enum custom_keycodes {
    vsc_clg,
    vsc_pin,
    vsc_fexp,
    vsc_trim,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case vsc_clg:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING(SS_LCTL("k"));
                SEND_STRING("m");
            } else {
                // when keycode QMKURL is released
            }
            break;

        case vsc_pin:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("k"));
                SEND_STRING(SS_LSFT(SS_TAP(X_ENTER)));
            } else {
            }
            break;

        case vsc_fexp:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("k"));
                SEND_STRING("r");
            } else {
            }
            break;

        case vsc_trim:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("k"));
                SEND_STRING(SS_LCTL("x"));
            } else {
            }
            break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_ortho_3x10(
        KC_ESC, KC_F5, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, vsc_fexp, vsc_fmt, 
        win_l, KC_S, KC_D, KC_F_L3, KC_G, KC_H, KC_J, KC_K, vsc_trim, vsc_clg, 
        ctrl_z, ctrl_x, ctrl_c, ctrl_v, TG(1), KC_B_L1, KC_N_L5, KC_MALT, KC_BSCT, vsc_pin),
        
    [_FN1] = LAYOUT_ortho_3x10(
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y,  KC_U, KC_I, KC_O, KC_P, 
        KC_A, KC_S, KC_D, KC_F, KC_G, KC_H,  KC_J, KC_K, KC_L, KC_ENT, 
        KC_Z, KC_X, KC_C, KC_V, TG(1),KC_SPC,KC_B, KC_N, KC_M, KC_BSPC)
        };
