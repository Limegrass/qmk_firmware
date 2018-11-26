#include QMK_KEYBOARD_H

#define _BASE 0
#define _FN1 1
#define _FN2 2
#define _FN3 3

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define FN1 MO(_FN1)
#define FN2 MO(_FN2)
#define FN3 MO(_FN3)
#define SP_FN1 LT(_FN1, KC_SPACE)
#define ESC_FN1 LT(_FN1, KC_ESCAPE)
#define ESC_FN2 LT(_FN2, KC_ESCAPE)
#define ENTER_FN2 LT(_FN2, KC_ENT)
#define SP_FN2 LT(_FN2, KC_SPACE)
#define SPACE_FN3 LT(_FN3, KC_SPACE)
#define BS_FN1 LT(_FN1, KC_BSPC)
#define BS_FN2 LT(_FN2, KC_BSPC)

f   
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Figure out the last two keys
    /* [_FN2] = LAYOUT( */
    /*     KC_TAB                       , KC_F1   , KC_F2   , KC_F3   , KC_F4     , _______   , _______ , KC_7    , KC_8    , KC_9       , KC_EQL  , KC_BSPC , KC_DEL  , */
    /*     KC_LCTL                      , KC_F5   , KC_F6   , KC_F7   , KC_F8     , _______   , _______ , KC_4    , KC_5    , KC_6       , KC_MINS , KC_ENT  , */
    /*     KC_LSFT                      , KC_F9   , KC_F10  , KC_F11  , KC_F12    , _______   , _______ , KC_1    , KC_2    , KC_3       , KC_PAST , KC_SLSH , */
    /*     FN1                          , KC_TRNS , KC_LGUI , KC_LALT , _______   , KC_0      , _______ , KC_DOT  , KC_TRNS , _______ */
    /* )                                , */
    [_BASE] = LAYOUT(
        KC_TAB       , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T      , KC_Y    , KC_U           , KC_I    , KC_O      , KC_P    , KC_BSLS , KC_BSPC ,
        KC_LCTL      , KC_A    , KC_S    , KC_D    , KC_F    , KC_G      , KC_H    , KC_J           , KC_K    , KC_L      , KC_SCLN , KC_QUOT ,
        KC_LSPO      , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B      , KC_N    , KC_M           , KC_COMM , KC_DOT    , KC_SLSH , KC_RSPC ,
        ESC_FN1      , TT(2)   , KC_LGUI , KC_LALT , ESC_FN2 , SPACE_FN3 , TT(3)   , LALT(KC_GRAVE) , OSL(2)  , ENTER_FN2
        // OK?       , ?       , OK      , OK      , OK      , OK        , ?       , OK?FN              , ?       , OK?
    )                ,

    [_FN1] = LAYOUT(
        _______      , _______ , _______ , KC_LBRC , KC_RBRC , _______   , _______ , _______        , KC_HOME , KC_END    , KC_PGUP , KC_PGDN , KC_DEL  ,
        KC_LCTL      , _______ , _______ , KC_LPRN , KC_RPRN , _______   , KC_LEFT , KC_DOWN        , KC_UP   , KC_RGHT   , _______ , KC_INS  ,
        KC_LSFT      , _______ , _______ , KC_BSLS , KC_SLSH , _______   , _______ , _______        , _______ , KC_MUTE   , KC_VOLD , KC_VOLU ,
        KC_TRNS      , _______ , KC_LGUI , KC_LALT , _______ , KC_MPLY   , KC_MSTP , _______        , KC_MPRV , KC_MNXT
    )                ,

    [_FN2] = LAYOUT(
        KC_TAB       , KC_1    , KC_2    , KC_3    , KC_4    , KC_5      , KC_6    , KC_7           , KC_8    , KC_9      , KC_0    , KC_MINS , KC_EQL  ,
        KC_LCTL      , _______ , _______ , _______ , _______ , _______   , _______ , _______        , _______ , _______   , KC_MINS , KC_ENT  ,
        KC_LSFT      , _______ , _______ , _______ , _______ , _______   , _______ , _______        , _______ , _______   , KC_PAST , KC_SLSH ,
        FN1          , KC_TRNS , KC_LGUI , KC_LALT , _______ , _______   , _______ , KC_DOT         , KC_TRNS , _______
    )                ,

    [_FN3] = LAYOUT(
        XXXXXXX      , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5     , KC_F6   , KC_F7          , KC_F8   , KC_F9     , KC_F10  , KC_F11  , KC_F12  ,
        KC_LCTL      , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX   , XXXXXXX , XXXXXXX        , XXXXXXX , XXXXXXX   , XXXXXXX , XXXXXXX ,
        KC_LSFT      , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX   , XXXXXXX , XXXXXXX        , XXXXXXX , XXXXXXX   , KC_UP   , XXXXXXX ,
        XXXXXXX      , XXXXXXX , KC_LGUI , KC_LALT , XXXXXXX , XXXXXXX   , KC_TRNS , KC_LEFT        , KC_DOWN , KC_RGHT
    )
};
