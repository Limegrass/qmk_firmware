#include QMK_KEYBOARD_H

#define _BASE 0
#define _COLEMAK_DHM 1
#define _MOTION 2
#define _NUMBER 3
#define _FUNCTION 4
#define _HARDWARE 15
#define _GAMEBASE 6
#define _GAMENUMBER 7
#define _GAMEFUNCTION 8
#define _FPS 9

#define APP_GUI MT(MOD_RGUI, KC_APP)
#define ESC_NUM LT(_NUMBER , KC_ESCAPE)
#define ENTER_FUNC LT(_FUNCTION , KC_ENTER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer
     * ,-------------------------------------------------------------------------.
     * | Esc |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |Bspace |
     * |-------------------------------------------------------------------------+
     * |Tab/L3|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |Enter |
     * |-------------------------------------------------------------------------+
     * | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |Shift|
     * |-------------------------------------------------------------------------+
     * | Ctrl| Alt | Gui | App |  L2  |   Space   |  L1  | Left| Down|  Up |Right|
     * `-------------------------------------------------------------------------'
     */
    [_BASE] = LAYOUT(
            KC_TAB        , KC_Q           , KC_W    , KC_E    , KC_R    , KC_T     , KC_Y       , KC_U    , KC_I          , KC_O    , KC_P          , KC_BSPC       ,
            KC_LCTL       , KC_A           , KC_S    , KC_D    , KC_F    , KC_G     , KC_H       , KC_J    , KC_K          , KC_L    , KC_SCLN       , KC_QUOTE      ,
            KC_LEFT_SHIFT , KC_Z           , KC_X    , KC_C    , KC_V    , KC_B     , KC_N       , KC_M    , KC_COMM       , KC_DOT  , KC_SLSH       , KC_RIGHT_SHIFT ,
            MO(_MOTION)   , OSL(_FUNCTION) , KC_LGUI , KC_LALT , ESC_NUM , KC_SPACE , ENTER_FUNC , KC_RALT , APP_GUI       , APP_GUI , TT(_HARDWARE)
            )             ,

    [_COLEMAK_DHM] = LAYOUT(
            KC_TAB        , KC_Q           , KC_W    , KC_F    , KC_P    , KC_B     , KC_J       , KC_L    , KC_U          , KC_Y    , KC_SCLN       , KC_BSPC       ,
            KC_LCTL       , KC_A           , KC_R    , KC_S    , KC_T    , KC_G     , KC_M       , KC_N    , KC_E          , KC_I    , KC_O          , KC_QUOTE      ,
            KC_LEFT_SHIFT , KC_Z           , KC_X    , KC_C    , KC_D    , KC_V     , KC_K       , KC_H    , KC_COMM       , KC_DOT  , KC_SLSH       , KC_RIGHT_SHIFT ,
            MO(_MOTION)   , OSL(_FUNCTION) , KC_LGUI , KC_LALT , ESC_NUM , KC_SPACE , ENTER_FUNC , KC_RALT , APP_GUI       , APP_GUI , TT(_HARDWARE)
            )             ,

    [_MOTION] = LAYOUT(
            KC_GRAVE    , KC_PIPE  , KC_BACKSLASH    , KC_LEFT_CURLY_BRACE , KC_RIGHT_CURLY_BRACE , KC_UNDERSCORE , _______ , KC_PGUP , KC_HOME , KC_END  , KC_PGDN , KC_DEL  ,
            KC_RCTL     , KC_TILDE , KC_UNDERSCORE   , KC_LEFT_PAREN       , KC_RIGHT_PAREN       , KC_QUOTE      , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , KC_INS  , KC_ENT  ,
            KC_LSFT     , KC_PLUS  , KC_MINUS        , KC_LBRC             , KC_RBRC              , _______       , _______ , _______ , KC_PSCR , KC_MUTE , KC_VOLD , KC_VOLU ,
            _______     , _______  , KC_LGUI         , KC_LALT             , _______              , _______       , _______ , KC_MPRV , KC_MPLY , KC_MSTP , KC_MNXT
            )           ,

    [_NUMBER] = LAYOUT(
            KC_EQL  , LSFT(KC_1) , LSFT(KC_2) , LSFT(KC_3) , LSFT(KC_4) , LSFT(KC_5) , LSFT(KC_6) , LSFT(KC_7) , LSFT(KC_8) , KC_PLUS    , KC_MINUS   , KC_BSPC ,
            KC_LCTL , KC_1       , KC_2       , KC_3       , KC_4       , KC_5       , KC_6       , KC_7       , KC_8       , KC_9       , KC_0        , KC_ENT  ,
            KC_LSFT , LGUI(KC_1) , LGUI(KC_2) , LGUI(KC_3) , LGUI(KC_4) , LGUI(KC_5) , LGUI(KC_6) , LGUI(KC_7) , LGUI(KC_8) , LGUI(KC_9) , LGUI(KC_0) , KC_RSFT ,
            _______ , _______    , KC_LGUI    , KC_LALT    , _______    , _______    , _______    , _______    , _______    , _______    , _______
            ),

    [_FUNCTION] = LAYOUT(
            KC_F12        , KC_F1        , KC_F2       , KC_F3       , KC_F4       , KC_F5       , KC_F6       , KC_F7       , KC_F8       , KC_F9       , KC_F10       , KC_F11       ,
            KC_LCTL       , LGUI(KC_F1)  , LGUI(KC_F2) , LGUI(KC_F3) , LGUI(KC_F4) , LGUI(KC_F5) , LGUI(KC_F6) , LGUI(KC_F7) , LGUI(KC_F8) , LGUI(KC_F9) , LGUI(KC_F10) , LGUI(KC_F11) ,
            KC_LSFT       , LALT(KC_F1)  , LALT(KC_F2) , LALT(KC_F3) , LALT(KC_F4) , LALT(KC_F5) , LALT(KC_F6) , LALT(KC_F7) , LALT(KC_F8) , LALT(KC_F9) , LALT(KC_F10) , LALT(KC_F11) ,
            KC_RCTL       , KC_CAPS_LOCK , KC_LGUI     , KC_LALT     , _______     , _______     , _______     , KC_LEFT     , KC_DOWN     , KC_UP       , KC_RGHT
            )             ,

    [_HARDWARE] = LAYOUT(
            XXXXXXX       , KC_MS_BTN1    , KC_MS_UP   , KC_MS_BTN2     , KC_MS_WH_UP   , _______      , XXXXXXX       , XXXXXXX  , XXXXXXX       , XXXXXXX , XXXXXXX            , QK_BOOTLOADER    ,
            KC_LCTL       , KC_MS_LEFT    , KC_MS_DOWN , KC_MS_RIGHT    , KC_MS_WH_DOWN , _______      , XXXXXXX       , XXXXXXX  , XXXXXXX       , XXXXXXX , XXXXXXX            , XXXXXXX          ,
            KC_LSFT       , KC_MS_WH_LEFT , KC_MS_BTN3 , KC_MS_WH_RIGHT , KC_MS_BTN4    , KC_MS_BTN5   , XXXXXXX       , XXXXXXX  , XXXXXXX       , XXXXXXX , KC_BRIGHTNESS_DOWN , KC_BRIGHTNESS_UP ,
            RGB_TOG       , RGB_MOD       , KC_LGUI    , KC_LALT        , DF(_BASE)     , DF(_COLEMAK_DHM) , DF(_GAMEBASE) , DF(_FPS) , QK_BOOTLOADER , XXXXXXX , QK_BOOTLOADER
            )             ,

    [_GAMEBASE] = LAYOUT(
            KC_TAB          , KC_Q              , KC_W    , KC_E    , KC_R     , KC_T     , KC_Y             , KC_U      , KC_I    , KC_O      , KC_P      , KC_BSPC       ,
            KC_LCTL         , KC_A              , KC_S    , KC_D    , KC_F     , KC_G     , KC_H             , KC_J      , KC_K    , KC_L      , KC_SCLN   , KC_QUOTE      ,
            KC_LSFT         , KC_Z              , KC_X    , KC_C    , KC_V     , KC_B     , KC_N             , KC_M      , KC_COMM , KC_DOT    , KC_SLSH   , KC_RSFT       ,
            MO(_GAMENUMBER) , MO(_GAMEFUNCTION) , KC_LGUI , KC_LALT , KC_SPACE , KC_SPACE , LT(_GAMEFUNCTION , KC_ENTER) , KC_RALT , DF(_BASE) , KC_ESCAPE , TT(_HARDWARE)
            )               ,

    [_GAMENUMBER] = LAYOUT(
            KC_GRAVE        , KC_1               , KC_2    , KC_3    , KC_4    , _______ , _______   , KC_PGUP , KC_HOME , KC_END  , KC_PGDN , KC_DEL  ,
            _______         , KC_5               , KC_6    , KC_7    , KC_8    , _______ , KC_LEFT   , KC_DOWN , KC_UP   , KC_RGHT , KC_INS  , KC_ENT  ,
            _______         , KC_9               , KC_0    , KC_EQL  , _______ , _______ , _______   , _______ , KC_PSCR , KC_MUTE , KC_VOLD , KC_VOLU ,
            _______         , OSL(_GAMEFUNCTION) , _______ , _______ , _______ , _______ , DF(_BASE) , KC_MPRV , KC_MPLY , KC_MSTP , KC_MNXT
            )               ,

    [_GAMEFUNCTION] = LAYOUT(
            KC_GRAVE , KC_F1   , KC_F2   , KC_F3   , KC_F4   , _______ , _______   , _______ , _______ , _______ , _______  , _______ ,
            _______  , KC_F5   , KC_F6   , KC_F7   , KC_F8   , _______ , _______   , _______ , _______ , _______ , _______  , _______ ,
            _______  , KC_F9   , KC_F10  , KC_F11  , KC_F12  , _______ , _______   , _______ , _______ , _______ , _______  , _______ ,
            _______  , _______ , _______ , _______ , _______ , _______ , DF(_BASE) , _______ , _______ , _______ , _______
            ),

    [_FPS] = LAYOUT(
            KC_TAB   , KC_Q            , KC_W    , KC_E    , KC_R     , KC_T     , KC_Y             , KC_U      , KC_I    , KC_O      , KC_P      , KC_BSPC       ,
            KC_LCTL  , KC_A            , KC_S    , KC_D    , KC_F     , KC_G     , KC_H             , KC_J      , KC_K    , KC_L      , KC_SCLN   , KC_QUOTE      ,
            KC_LSFT  , KC_Z            , KC_X    , KC_C    , KC_V     , KC_B     , KC_N             , KC_M      , KC_COMM , KC_DOT    , KC_SLSH   , KC_RSFT       ,
            KC_LCTL  , MO(_GAMENUMBER) , KC_LGUI , KC_LALT , KC_SPACE , KC_SPACE , LT(_GAMEFUNCTION , KC_ENTER) , KC_RALT , DF(_BASE) , KC_ESCAPE , TT(_HARDWARE)
            )        ,
};
