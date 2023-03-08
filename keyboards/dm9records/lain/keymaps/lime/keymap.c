// Copyright 2022 Takuya Urakawa @hsgw (dm9records.com, 5z6p.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    QWERTY,
    ALT_LAYOUT,
    MOTION,
    NUMBER,
    FUNCTION,
    HARDWARE,
};

enum custom_keycodes { LED_EN = SAFE_RANGE };

#define APP_GUI MT(MOD_RGUI, KC_APP)
#define ESC_NUM LT(NUMBER , KC_ESCAPE)
#define ENTER_FUNC LT(FUNCTION , KC_ENTER)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [QWERTY] = LAYOUT(
        KC_TAB     , KC_Q          , KC_W    , KC_E    , KC_R    , KC_T   , OSM(MOD_RCTL) , KC_Y    , KC_U         , KC_I    , KC_O         , KC_P    , KC_BSPC ,
        KC_LCTL    , KC_A          , KC_S    , KC_D    , KC_F    , KC_G   , OSM(MOD_RALT) , KC_H    , KC_J         , KC_K    , KC_L         , KC_SCLN , KC_QUOT ,
        KC_LSFT    , KC_Z          , KC_X    , KC_C    , KC_V    , KC_B   , KC_RSFT       , KC_N    , KC_M         , KC_COMM , KC_DOT       , KC_SLSH ,
        MO(MOTION) , OSL(FUNCTION) , KC_LGUI , KC_LALT , ESC_NUM , KC_SPC , ENTER_FUNC    , KC_RALT , TT(HARDWARE) , APP_GUI , TT(HARDWARE)
    ),

    // Workman
    [ALT_LAYOUT] = LAYOUT(
        KC_TAB     , KC_Q          , KC_D    , KC_R    , KC_W    , KC_B     , XXXXXXX    , KC_J    , KC_F         , KC_U    , KC_P         , KC_SCLN , KC_BSPC  ,
        KC_LCTL    , KC_A          , KC_S    , KC_H    , KC_T    , KC_G     , XXXXXXX    , KC_Y    , KC_N         , KC_E    , KC_O         , KC_I    , KC_QUOTE ,
        KC_LSFT    , KC_Z          , KC_X    , KC_M    , KC_C    , KC_V     , KC_K       , KC_L    , KC_COMM      , KC_DOT  , KC_SLSH      , KC_RSFT ,
        MO(MOTION) , OSL(FUNCTION) , KC_LGUI , KC_LALT , ESC_NUM , KC_SPACE , ENTER_FUNC , KC_RALT , TT(HARDWARE) , APP_GUI , TT(HARDWARE)
    ),

    [MOTION] = LAYOUT(
        KC_GRAVE , KC_PIPE  , KC_BACKSLASH    , KC_LEFT_CURLY_BRACE , KC_RIGHT_CURLY_BRACE , KC_UNDERSCORE , XXXXXXX , _______ , KC_PGUP , KC_HOME , KC_END  , KC_PGDN , KC_DEL ,
        KC_RCTL  , KC_TILDE , KC_UNDERSCORE   , KC_LEFT_PAREN       , KC_RIGHT_PAREN       , KC_QUOTE      , XXXXXXX , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , KC_INS  , KC_ENT ,
        KC_LSFT  , KC_QUOTE , KC_DOUBLE_QUOTE , KC_LBRC             , KC_RBRC              , _______       , _______ , _______ , KC_PSCR , KC_MUTE , KC_VOLD , KC_VOLU ,
        _______  , _______  , KC_LGUI         , KC_LALT             , _______              , _______       , _______ , KC_MPRV , KC_MPLY , KC_MSTP , KC_MNXT
    ),

    [NUMBER] = LAYOUT(
        KC_EQL  , KC_1       , KC_2       , KC_3       , KC_4       , KC_5       , XXXXXXX    , KC_6       , KC_7       , KC_8       , KC_9       , KC_0     , KC_BSPC ,
        KC_LCTL , LSFT(KC_1) , LSFT(KC_2) , LSFT(KC_3) , LSFT(KC_4) , LSFT(KC_5) , XXXXXXX    , LSFT(KC_6) , LSFT(KC_7) , LSFT(KC_8) , KC_PLUS    , KC_MINUS , KC_ENT  ,
        KC_LSFT , LGUI(KC_1) , LGUI(KC_2) , LGUI(KC_3) , LGUI(KC_4) , LGUI(KC_5) , LGUI(KC_6) , LGUI(KC_7) , LGUI(KC_8) , LGUI(KC_9) , LGUI(KC_0) , KC_RSFT  ,
        _______ , _______    , KC_LGUI    , KC_LALT    , _______    , _______    , _______    , _______    , _______    , _______    , _______
    ),

    [FUNCTION] = LAYOUT(
        KC_F12  , KC_F1        , KC_F2       , KC_F3       , KC_F4       , KC_F5       , XXXXXXX     , KC_F6       , KC_F7       , KC_F8       , KC_F9        , KC_F10       , KC_F11       ,
        KC_LCTL , LGUI(KC_F1)  , LGUI(KC_F2) , LGUI(KC_F3) , LGUI(KC_F4) , LGUI(KC_F5) , XXXXXXX     , LGUI(KC_F6) , LGUI(KC_F7) , LGUI(KC_F8) , LGUI(KC_F9)  , LGUI(KC_F10) , LGUI(KC_F11) ,
        KC_LSFT , LALT(KC_F1)  , LALT(KC_F2) , LALT(KC_F3) , LALT(KC_F4) , LALT(KC_F5) , LALT(KC_F6) , LALT(KC_F7) , LALT(KC_F8) , LALT(KC_F9) , LALT(KC_F10) , LALT(KC_F11) ,
        KC_RCTL , KC_CAPS_LOCK , KC_LGUI     , KC_LALT     , _______     , _______     , _______     , KC_LEFT     , KC_DOWN     , KC_UP       , KC_RGHT
    ),

    [HARDWARE] = LAYOUT(
        XXXXXXX , KC_MS_BTN1    , KC_MS_UP   , KC_MS_BTN2     , KC_MS_WH_UP   , _______     , XXXXXXX  , XXXXXXX      , XXXXXXX       , XXXXXXX , XXXXXXX            , XXXXXXX          , QK_BOOTLOADER ,
        KC_LCTL , KC_MS_LEFT    , KC_MS_DOWN , KC_MS_RIGHT    , KC_MS_WH_DOWN , _______     , XXXXXXX  , XXXXXXX      , XXXXXXX       , XXXXXXX , XXXXXXX            , XXXXXXX          , XXXXXXX       ,
        KC_LSFT , KC_MS_WH_LEFT , KC_MS_BTN3 , KC_MS_WH_RIGHT , KC_MS_BTN4    , KC_MS_BTN5  , XXXXXXX  , XXXXXXX      , XXXXXXX       , XXXXXXX , KC_BRIGHTNESS_DOWN , KC_BRIGHTNESS_UP ,
        RGB_TOG , RGB_MOD       , KC_LGUI    , KC_LALT        , DF(QWERTY)    , DF(ALT_LAYOUT) , XXXXXXX  , XXXXXXX      , QK_BOOTLOADER , XXXXXXX , QK_BOOTLOADER
    ),
};
