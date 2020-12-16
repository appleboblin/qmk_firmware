#include QMK_KEYBOARD_H
#include "print.h"

/*
 * I have no idea what I am doing (:
 */

//Layer Mapping
#define _QW 0
#define _CO 1
#define _FN 2

//Macros (None, Yet.)
enum custom_keycodes {
	QW = SAFE_RANGE,
	CO,
	FN,
};

//Can only have one bool
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     //Copy paste from wiki
      // If console is enabled, it will print the matrix position and status of each key pressed
    #ifdef CONSOLE_ENABLE
    dprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
    #endif

    //Temp change layer
    uint8_t mod_state = get_mods();
    switch (keycode) {
        case KC_H:
            if (record->event.pressed) {
                if ((mod_state & (MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT))) == (MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT))) {
                    del_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT));
                    layer_invert(_CO);
                    set_mods(mod_state);
                    return false;
                }
            }
    }
    /*
    //write to persistent memory, Keeps default when unplug. But shortend life of MCU
    uint8_t mod_state = get_mods();
    uint8_t layer = biton32(layer_state);
    switch (keycode) {
        case KC_H:
            if (record->event.pressed) {
                if ((mod_state & (MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT))) == (MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT))) {
                    del_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT));
                    if (layer == _QW) {
                        set_single_persistent_default_layer(_CO);
                    }
                    else if (layer == _CO){
                        set_single_persistent_default_layer(_QW);
                    }
                    set_mods(mod_state);
                    return false;
                }
            }
    }
    */
    return true;
};

//Layout of each layer.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //QWERTY
    [_QW] = LAYOUT_75_ansi(
        /* ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐ 16*/
            KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_PAUS,  KC_DEL,
        /* ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┴─────────┼─────────┤ 15*/
            KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,      KC_BSPC,         KC_HOME,
        /* ├─────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬──────────────┼─────────┤ 15*/
            KC_TAB,        KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,       KC_END,
        /* ├──────────────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──────────────├─────────┤ 14*/
            KC_BSPC,          KC_A,   KC_S,       KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,               KC_PGUP,
        /* ├─────────────────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───────────┬─────────┼─────────┤ 14*/
            KC_LSFT,              KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,          KC_UP,    KC_PGDN,
        /* ├───────────┬─────────┴─┬───────┴───┬─────┴─────────┴─────────┴─────────┴─────────┴─────────┴───────┬─┴───────┬─┴───────┬─┴───────┬─────────┼─────────┼─────────┤ 10*/
            KC_LCTL,     KC_LALT,   KC_LGUI,    KC_SPC,                                                         KC_RALT,  MO(_FN),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
        /* └───────────┴───────────┴───────────┴───────────────────────────────────────────────────────────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘ */
        ),

    //Colemak
    [_CO] = LAYOUT_75_ansi(
        /* ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐ 16*/
            KC_ESC,   KC_F1,    KC_F2,     KC_F3,   KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,   KC_PAUS, KC_DEL,
        /* ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┴─────────┼─────────┤ 15*/
            KC_GRV,   KC_1,     KC_2,      KC_3,    KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_HOME,
        /* ├─────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬──────────────┼─────────┤ 15*/
            KC_TAB,        KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_LBRC,  KC_RBRC,  KC_BSLS,       KC_END,
        /* ├──────────────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──────────────├─────────┤ 14*/
            KC_BSPC,          KC_A,     KC_R,     KC_S,     KC_T,     KC_D,     KC_H,     KC_N,      KC_E,     KC_I,    KC_O,     KC_QUOT,  KC_ENT,               KC_PGUP,
        /* ├─────────────────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───────────┬─────────┼─────────┤ 14*/
            KC_LSFT,              KC_Z,     KC_X,     KC_C,      KC_V,    KC_B,     KC_K,      KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,          KC_UP,    KC_PGDN,
        /* ├───────────┬─────────┴─┬───────┴───┬─────┴─────────┴─────────┴─────────┴─────────┴─────────┴───────┬─┴───────┬─┴───────┬─┴───────┬─────────┼─────────┼─────────┤ 10*/
            KC_LCTL,    KC_LALT,    KC_LGUI,    KC_SPC,                                                         KC_RALT,  MO(_FN),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
        /* └───────────┴───────────┴───────────┴───────────────────────────────────────────────────────────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘ */
    ),

    //Function
    //sets _QW and _CO to default layer, not needed because have a shortcut for it. Its there just in cause.
    [_FN] = LAYOUT_75_ansi(
        /* ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐ */
            KC_TRNS,  BL_TOGG,  BL_STEP,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NLCK,  KC_SLCK,  KC_INS,
        /* ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┴─────────┼─────────┤ */
            KC_TRNS,  RGB_TOG,  RGB_MOD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        /* ├─────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬──────────────┼─────────┤ */
            KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_MUTE,
        /* ├──────────────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──────────────├─────────┤ */
            KC_CAPS,          KC_TRNS,  RESET,    DEBUG,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,              KC_VOLU,
        /* ├─────────────────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───────────┬─────────┼─────────┤ */
            KC_BRIU,              DF(_QW),  DF(_CO),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_VOLD,
        /* ├───────────┬─────────┴─┬───────┴───┬─────┴─────────┴─────────┴─────────┴─────────┴─────────┴───────┬─┴───────┬─┴───────┬─┴───────┬─────────┼─────────┼─────────┤ */
            KC_BRID,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                                        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_MPLY,  KC_MNXT
        /* └───────────┴───────────┴───────────┴───────────────────────────────────────────────────────────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘ */
    )
  };
