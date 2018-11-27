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

/* , */
/*         [] = LAYOUT( */
/*         XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX , XXXXXXX    , XXXXXXX , XXXXXXX   , XXXXXXX , */
/*         KC_LCTL, XXXXXXX, XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX , XXXXXXX    , XXXXXXX , XXXXXXX   , */
/*         KC_LSFT, XXXXXXX, XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX , XXXXXXX    , XXXXXXX , XXXXXXX   , */
/*         XXXXXXX, XXXXXXX, KC_LGUI , KC_LALT , XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX , XXXXXXX */
/*         ) */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
            KC_TAB  , KC_Q , KC_W    , KC_E    , KC_R    , KC_T      , KC_Y     , KC_U     , KC_I    , KC_O      , KC_P    , KC_BSLS   , KC_BSPC ,
            KC_LCTL , KC_A , KC_S    , KC_D    , KC_F    , KC_G      , KC_H     , KC_J     , KC_K    , KC_L      , KC_SCLN , KC_QUOT   ,
            KC_LSFT , KC_Z , KC_X    , KC_C    , KC_V    , KC_B      , KC_N     , KC_M     , KC_COMM , KC_DOT    , KC_SLSH , KC_ENT ,
            FN1     , OSL2 , KC_LGUI , KC_LALT , ESC_FN2 , SPACE_FN3 , TG(_FN4) , KC_GRAVE , OSL3    , ENTER_FN2
            )

    ,
    [_FN1] = LAYOUT(
            KC_GRAVE , _______ , _______ , KC_LEFT_CURLY_BRACE , KC_RIGHT_CURLY_BRACE , _______ , _______ , _______ , KC_HOME    , KC_END  , KC_PGUP , KC_PGDN , KC_DEL ,
            KC_LCTL  , KC_RCTL , _______ , KC_LEFT_PAREN       , KC_RIGHT_PAREN       , _______ , KC_LEFT , KC_DOWN , KC_UP      , KC_RGHT , KC_INS  , KC_ENT  ,
            KC_LSFT  , KC_RSFT , _______ , KC_LBRC             , KC_RBRC              , _______ , _______ , _______ , KC_PSCREEN , KC_MUTE , KC_VOLD , KC_VOLU ,
            _______  , _______ , KC_LGUI , KC_LALT             , _______              , KC_MPLY , KC_MSTP , _______ , KC_MPRV    , KC_MNXT
            )

    ,
    [_FN2] = LAYOUT(
            KC_EQL   , KC_1       , KC_2       , KC_3       , KC_4       , KC_5       , KC_6       , KC_7       , KC_8       , KC_9       , KC_0       , KC_MINS , KC_BSPC ,
            KC_LCTL  , LGUI(KC_1) , LGUI(KC_2) , LGUI(KC_3) , LGUI(KC_4) , LGUI(KC_5) , LGUI(KC_6) , LGUI(KC_7) , LGUI(KC_8) , LGUI(KC_9) , LGUI(KC_0) , KC_ENT  ,
            KC_LSFT  , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , KC_PAST    , KC_RSFT,
            _______  , _______    , KC_LGUI    , KC_LALT    , _______    , _______    , _______    , _______    , _______    , _______
            )

    ,
    [_FN3] = LAYOUT(
            KC_ESCAPE , KC_F1       , KC_F2       , KC_F3       , KC_F4       , KC_F5       , KC_F6       , KC_F7       , KC_F8       , KC_F9       , KC_F10       , KC_F11       , KC_F12 ,
            KC_LALT   , LALT(KC_F1) , LALT(KC_F2) , LALT(KC_F3) , LALT(KC_F4) , LALT(KC_F5) , LALT(KC_F6) , LALT(KC_F7) , LALT(KC_F8) , LALT(KC_F9) , LALT(KC_F10) , LALT(KC_F11) ,
            KC_LGUI   , LGUI(KC_F1) , LGUI(KC_F2) , LGUI(KC_F3) , LGUI(KC_F4) , LGUI(KC_F5) , LGUI(KC_F6) , LGUI(KC_F7) , LGUI(KC_F8) , LGUI(KC_F9) , LGUI(KC_F10) , LGUI(KC_F11) ,
            _______   , KC_CAPSLOCK , KC_LGUI     , KC_LALT     , _______     , _______     , KC_LEFT     , KC_DOWN     , KC_UP     , KC_RGHT
            )

    ,
    [_FN4] = LAYOUT(
            KC_TAB   , KC_F1   , KC_F2   , KC_F3   , KC_F4   , _______ , KC_PAST , KC_7    , KC_8    , KC_9    , KC_EQL  , KC_DEL , KC_BSPC ,
            KC_LCTL  , KC_F5   , KC_F6   , KC_F7   , KC_F8   , _______ , KC_SLSH , KC_4    , KC_5    , KC_6    , KC_MINS , KC_ENT ,
            KC_LSFT  , KC_F9   , KC_F10  , KC_F11  , KC_F12  , _______ , KC_DOT  , KC_1    , KC_2    , KC_3    , KC_UP   , KC_TAB ,
            _______  , _______ , KC_LGUI , KC_LALT , _______ , KC_0    , _______ , KC_LEFT , KC_DOWN , KC_RGHT
            )


};
