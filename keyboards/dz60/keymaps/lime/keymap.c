#include QMK_KEYBOARD_H

#define _BASE 0
#define _FN1 1
#define _FN2 2
#define _FN3 3
#define _FN4 4
#define _FN5 5

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define FN1 MO(_FN1)
#define FN2 MO(_FN2)
#define FN3 MO(_FN3)
#define FN4 MO(_FN4)
#define FN5 MO(_FN5)

#define OSL2 OSL(_FN2)
#define OSL3 OSL(_FN3)

#define ESC_FN1 LT(_FN1, KC_ESCAPE)
#define ESC_FN2 LT(_FN2, KC_ESCAPE)

#define SPACE_FN1 LT(_FN1, KC_SPACE)
#define SPACE_FN2 LT(_FN2, KC_SPACE)
#define SPACE_FN3 LT(_FN3, KC_SPACE)
#define ENTER_FN2 LT(_FN2, KC_ENT)
#define BS_FN1 LT(_FN1, KC_BSPC)
#define BS_FN2 LT(_FN2, KC_BSPC)

#define BSLS_FN2 LT(_FN2, KC_BSLS)

#define PIPE_FN4 LT(_FN4, KC_PIPE)

#define TILDE_FN3 LT(_FN3, KC_TILDE)

    /* LAYOUT( */
    /*  KC_TRNS                        , M(1)       , M(2)          , M(3)                , M(4)                 , M(5)          , M(6)       , M(7)       , M(8)       , M(9)       , M(10)      , M(11)         , M(12)          , KC_TRNS , KC_TRNS , */
    /*  KC_TRNS                        , KC_TRNS    , KC_TRNS       , KC_TRNS             , KC_TRNS              , KC_TRNS       , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS       , KC_TRNS        , KC_TRNS , */
    /*  KC_TRNS                        , KC_TRNS    , KC_TRNS       , KC_TRNS             , KC_TRNS              , KC_TRNS       , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS       , KC_TRNS        , */
    /*  KC_TRNS                       , KC_TRNS    , KC_TRNS       , KC_TRNS             , KC_TRNS              , KC_TRNS       , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS       , KC_TRNS        , KC_TRNS , */
    /*  KC_TRNS                       , KC_TRNS    , KC_TRNS       , KC_TRNS             , KC_TRNS              , KC_TRNS       , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS)   , */

    /* [_FN4] = LAYOUT( */
    /*     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , */
    /*     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , */
    /*     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , */
    /*     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , */
    /*     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______) */
    /*             , */

//TODO: Take advantage of LM(layer, mod)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_GESC , KC_1    , KC_2    , KC_3    , KC_4      , KC_5      , KC_6           , KC_7    , KC_8    , KC_9     , KC_0     , KC_MINS , KC_EQL  , KC_DEL  , KC_BSPC ,
        KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R      , KC_T      , KC_Y           , KC_U    , KC_I    , KC_O     , KC_P     , KC_LBRC , KC_RBRC , KC_BSLS ,
        KC_LCTL , KC_A    , KC_S    , KC_D    , KC_F      , KC_G      , KC_H           , KC_J    , KC_K    , KC_L     , KC_SCLN  , KC_QUOT , KC_ENT  ,
        KC_LSFT , KC_LSFT , KC_Z    , KC_X    , KC_C      , KC_V      , KC_B           , KC_N    , KC_M    , KC_COMM  , KC_DOT   , KC_SLSH , KC_ENT  , KC_RSFT ,
        FN1     , KC_LGUI , KC_LALT , ESC_FN2 , SPACE_FN3 , SPACE_FN2 , LALT(KC_GRAVE) , KC_BSLS , XXXXXXX , TT(_FN5) , KC_RCTL) ,

    [_FN1] = LAYOUT(
        KC_GRV   , KC_F1    , KC_F2         , KC_F3               , KC_F4                , KC_F5         , KC_F6   , KC_F7   , KC_F8      , KC_F9   , KC_F10   , KC_F11  , KC_F12  , _______ , KC_DEL ,
        KC_GRAVE , KC_PIPE  , KC_BSLASH     , KC_LEFT_CURLY_BRACE , KC_RIGHT_CURLY_BRACE , KC_UNDERSCORE , _______ , _______ , KC_PGUP    , KC_HOME , KC_END   , KC_PGDN , KC_DEL  , _______ ,
        _______  , KC_TILDE , KC_UNDERSCORE , KC_LEFT_PAREN       , KC_RIGHT_PAREN       , KC_PLUS       , KC_LEFT , KC_DOWN , KC_UP      , KC_RGHT , KC_INS   , KC_ENT  , _______ ,
        _______  , _______  , KC_PLUS       , KC_UNDERSCORE       , KC_LBRC              , KC_RBRC       , _______ , _______ , KC_PSCREEN , KC_MUTE , KC_VOLD  , KC_VOLU , _______ , _______ ,
        _______  , _______  , _______       , KC_COLON            , KC_BSPC              , KC_ENTER      , _______ , _______ , _______    , FN4     , _______) ,

    [_FN2] = LAYOUT(
        _______ , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______ , _______  , _______       , _______      , _______ , _______ ,
        KC_EQL  , KC_1       , KC_2       , KC_3       , KC_4       , KC_5       , KC_6       , KC_7       , KC_8       , KC_9    , KC_0     , KC_MINS       , KC_EQL       , _______ ,
        _______ , LSFT(KC_1) , LSFT(KC_2) , LSFT(KC_3) , LSFT(KC_4) , LSFT(KC_5) , LSFT(KC_6) , LSFT(KC_7) , LSFT(KC_8) , KC_PLUS , KC_MINUS , LSFT(KC_MINS) , LSFT(KC_EQL) ,
        _______ , _______    , LGUI(KC_1) , LGUI(KC_2) , LGUI(KC_3) , LGUI(KC_4) , LGUI(KC_5) , LGUI(KC_6) , LGUI(KC_7) , _______ , _______  , _______       , KC_MPLY      , _______ ,
        KC_BSPC , _______    , _______    , _______    , KC_BSPC    , KC_DEL     , _______    , _______    , KC_MPRV    , KC_MSTP , KC_MNXT) ,

    [_FN3] = LAYOUT(
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______  , _______ , _______ , _______ , _______ ,
        _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10   , KC_F11  , KC_F12  , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______  , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______  , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______) ,

    [_FN4] = LAYOUT(
        _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10   , KC_F11  , KC_F12  , _______ , KC_DEL ,
        _______ , RGB_TOG , RGB_MOD , RGB_HUI , RGB_HUD , RGB_SAI , RGB_SAD , RGB_VAI , RGB_VAD , _______ , _______  , _______ , _______ , RESET   ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______  , _______ , _______ ,
        _______ , _______ , _______ , _______ , BL_DEC  , BL_TOGG , BL_INC  , BL_STEP , _______ , _______ , _______  , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______) ,

    // Gaming/PS layer
    [_FN5] = LAYOUT(
        _______ , _______ , _______ , _______  , _______ , _______ , _______ , _______ , _______ , _______ , _______  , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______  , _______ , _______ , _______ , _______ , _______ , _______ , _______  , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______  , _______ , _______ , _______ , _______ , _______ , _______ , _______  , _______ , _______ ,
        _______ , _______ , _______ , _______  , _______ , _______ , _______ , _______ , _______ , _______ , _______  , _______ , _______ , _______ ,
        _______ , _______ , _______ , KC_SPACE , _______ , KC_BSPC , _______ , _______ , _______ , _______ , _______) ,
};
