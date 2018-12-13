#include QMK_KEYBOARD_H

#define _BASE 0
#define _FN1 1
#define _FN2 2
#define _FN3 3
#define _FN4 4

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define FN1 MO(_FN1)
#define FN2 MO(_FN2)
#define FN3 MO(_FN3)
#define FN4 MO(_FN4)

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_GESC           , KC_1       , KC_2          , KC_3                , KC_4                 , KC_5       , KC_6       , KC_7       , KC_8       , KC_9       , KC_0       , KC_MINS , KC_EQL  , KC_DEL  , KC_BSPC ,
        KC_TAB            , KC_Q       , KC_W          , KC_E                , KC_R                 , KC_T       , KC_Y       , KC_U       , KC_I       , KC_O       , KC_P       , KC_LBRC , KC_RBRC , KC_BSLS ,
        KC_LCTL           , KC_A       , KC_S          , KC_D                , KC_F                 , KC_G       , KC_H       , KC_J       , KC_K       , KC_L       , KC_SCLN    , KC_QUOT , KC_ENT  ,
        KC_LSFT           , KC_LSFT    , KC_Z          , KC_X                , KC_C                 , KC_V       , KC_B       , KC_N       , KC_M       , KC_COMM    , KC_DOT     , KC_SLSH , KC_ENT  , KC_RSFT ,
        FN1               , KC_LGUI    , KC_LALT       , ESC_FN2             , KC_SPC               , BS_FN1     , KC_GRAVE   , FN2        , XXXXXXX    , FN3        , KC_RCTL)
                          ,

    [_FN1] = LAYOUT(
        KC_GRV            , KC_F1      , KC_F2         , KC_F3               , KC_F4                , KC_F5      , KC_F6      , KC_F7      , KC_F8      , KC_F9      , KC_F10     , KC_F11  , KC_F12  , KC_TRNS , KC_DEL  ,
        KC_GRAVE          , _______    , KC_PLUS       , KC_LEFT_CURLY_BRACE , KC_RIGHT_CURLY_BRACE , _______    , _______    , _______    , KC_HOME    , KC_END     , KC_PGUP    , KC_PGDN , KC_DEL  , _______ ,
        KC_LCTL           , KC_RCTL    , KC_UNDERSCORE , KC_LEFT_PAREN       , KC_RIGHT_PAREN       , _______    , KC_LEFT    , KC_DOWN    , KC_UP      , KC_RGHT    , KC_INS     , KC_ENT  , _______ ,
        KC_LSFT           , KC_RSFT    , _______       , KC_LBRC             , KC_RBRC              , _______    , _______    , _______    , KC_PSCREEN , KC_MUTE    , KC_VOLD    , KC_VOLU , _______ , _______ ,
        _______           , _______    , KC_LGUI       , KC_LALT             , _______              , KC_MPLY    , KC_MSTP    , _______    , KC_MPRV    , KC_MNXT    , _______)
                          ,

    [_FN2] = LAYOUT(
        _______           , _______    , _______       , _______             , _______              , _______    , _______    , _______    , _______    , _______    , _______    , _______ , _______ , _______ , _______ ,
        KC_EQL            , KC_1       , KC_2          , KC_3                , KC_4                 , KC_5       , KC_6       , KC_7       , KC_8       , KC_9       , KC_0       , KC_MINS , KC_BSPC , _______ ,
        KC_LCTL           , LGUI(KC_1) , LGUI(KC_2)    , LGUI(KC_3)          , LGUI(KC_4)           , LGUI(KC_5) , LGUI(KC_6) , LGUI(KC_7) , LGUI(KC_8) , LGUI(KC_9) , LGUI(KC_0) , KC_ENT  , _______ ,
        KC_LSFT           , _______    , _______       , _______             , _______              , _______    , _______    , _______    , _______    , _______    , KC_PAST    , KC_RSFT , _______ , _______ ,
        _______           , _______    , KC_LGUI       , KC_LALT             , _______              , KC_DEL     , _______    , _______    , _______    , _______    , _______)
                          ,

    [_FN3] = LAYOUT(
        KC_GRV            , KC_F1      , KC_F2         , KC_F3               , KC_F4                , KC_F5      , KC_F6      , KC_F7      , KC_F8      , KC_F9      , KC_F10     , KC_F11  , KC_F12  , KC_TRNS , KC_DEL  ,
        KC_TRNS           , RGB_TOG    , RGB_MOD       , RGB_HUI             , RGB_HUD              , RGB_SAI    , RGB_SAD    , RGB_VAI    , RGB_VAD    , KC_TRNS    , KC_TRNS    , KC_TRNS , KC_TRNS , RESET   ,
        KC_TRNS           , KC_TRNS    , KC_TRNS       , KC_TRNS             , KC_TRNS              , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS , KC_TRNS ,
        KC_TRNS           , KC_TRNS    , KC_TRNS       , KC_TRNS             , BL_DEC               , BL_TOGG    , BL_INC     , BL_STEP    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS , KC_TRNS , KC_TRNS ,
        KC_TRNS           , KC_TRNS    , KC_TRNS       , KC_TRNS             , KC_TRNS              , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS)
                          ,

    /* LAYOUT( */
    /*  KC_TRNS           , M(1)       , M(2)          , M(3)                , M(4)                 , M(5)       , M(6)       , M(7)       , M(8)       , M(9)       , M(10)      , M(11)   , M(12)   , KC_TRNS , KC_TRNS , */
    /*  KC_TRNS           , KC_TRNS    , KC_TRNS       , KC_TRNS             , KC_TRNS              , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS , KC_TRNS , KC_TRNS , */
    /*  KC_TRNS           , KC_TRNS    , KC_TRNS       , KC_TRNS             , KC_TRNS              , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS , KC_TRNS , */
    /*  KC_TRNS           , KC_TRNS    , KC_TRNS       , KC_TRNS             , KC_TRNS              , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS , KC_TRNS , KC_TRNS , */
    /*  KC_TRNS           , KC_TRNS    , KC_TRNS       , KC_TRNS             , KC_TRNS              , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS)   , */
};
