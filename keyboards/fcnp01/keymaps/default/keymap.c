// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _LIGHTS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        TO(_LIGHTS), KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_F15,  KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_F16,  KC_P4,   KC_P5,   KC_P6,
        KC_F17,  KC_P1,   KC_P2,   KC_P3,
        KC_F18,  KC_P0,   KC_PDOT, KC_PENT
    ),
    [_LIGHTS] = LAYOUT(
        TO(_BASE), UG_TOGG,  UG_SPDD, UG_SPDU, UG_HUED,
        QK_BOOT,  UG_PREV, UG_NEXT, XXXXXXX, UG_HUEU,
        QK_RBT,   UG_SATD, UG_SATU, XXXXXXX,
        XXXXXXX,  UG_VALD, UG_VALU, XXXXXXX,
        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX
    )
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] = {ENCODER_CCW_CW(UG_VALD, UG_VALU)},
};

const rgblight_segment_t PROGMEM my_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_RED}       // Light 1 LEDs, starting with LED 1
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_numlock_layer
);



void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, !led_state.num_lock);
    return true;
}
