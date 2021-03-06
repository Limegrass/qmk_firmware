#include QMK_KEYBOARD_H
/* #include "tapdance.h" */

#define _QWERTY 0
#define _NUM 1
#define _FKEY 2
#define _CODE 3
#define _HARDWARE 16

#define ESC_NUM LT(_NUM, KC_ESCAPE)
#define SPACE_FKEY LT(_FKEY, KC_SPACE)
#define TAB_CODE LT(_CODE, KC_TAB)
#define SLASH_CODE LT(_CODE, KC_SLASH)
#define COMM_CODE LT(_CODE, KC_COMM)
#define ENTER_CODE LT(_CODE, KC_ENTER)
#define DOT_FKEY LT(_FKEY, KC_DOT)
#define ENTER_CTRL LCTL_T(KC_ENTER)
#define ENTER_FKEY LT(_FKEY, KC_ENTER)
#define BACK_ALT LALT_T(KC_BSPC)
#define SLASH_LSFT LSFT_T(KC_BSPC)
#define ENTER_LGUI LGUI_T(KC_ENTER)

/* Make TAB_CODE into the leader key, */
/*      move TAB into leader esc, move enter into leader space */
/*      create a bind for ctrl/alt tabbing with leader if possible */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | GUI  | LOWER|      |    |      | RAISE| Shift|
 *                  `-------------|BckSpc|    |Space |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
/* replace semicolon with backspace, tapdance space enter taphold shift. */
/* tap esc */
[_QWERTY] = LAYOUT( \
  KC_Q , KC_W , KC_E , KC_R , KC_T , KC_Y , KC_U , KC_I    , KC_O   , KC_BSPC , \
  KC_A , KC_S , KC_D , KC_F , KC_G , KC_H , KC_J , KC_K    , KC_L   , KC_P , \
  KC_Z,  KC_X , KC_C , KC_V , KC_B , KC_N , KC_M , LT(_CODE, KC_COMM) , RALT_T(KC_DOT) , RCTL_T(KC_SLASH), \
         KC_LCTL, TAB_CODE,  ESC_NUM ,       LSFT_T(KC_SPACE)  , ENTER_LGUI , MO(_FKEY) \
),

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Tab | Left | Down |  Up  | Right|           |      |   -  |   =  |   [  |   ]  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Lock |   `  | Ctrl |  Alt |      |           |ScnSht| Zoom+| Zoom-|   \  |   '  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `-------------|DSKTP2|    |DSKTP3|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */

[_CODE] = LAYOUT( \
  KC_PIPE  , KC_BSLASH     , KC_LEFT_CURLY_BRACE , KC_RIGHT_CURLY_BRACE , KC_EQL, KC_PGUP , KC_HOME , KC_END  , KC_PGDN , KC_DEL , \
  KC_TILDE , KC_UNDERSCORE , KC_LEFT_PAREN       , KC_RIGHT_PAREN       , KC_QUESTION, KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , KC_INS  , \
  KC_GRAVE , KC_QUOTE      , KC_LBRACKET         , KC_RBRACKET          , KC_QUOTE, KC_DOUBLE_QUOTE, _______ , _______ , KC_SCLN  , KC_COLON , \
                    KC_LGUI, _______, MO(_HARDWARE),       _______, _______, _______                      \
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Esc |      |      |      |      |           |      |   _  |   +  |   {  |   }  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Caps|   ~  |      | Prev | Next |           | Mute | Vol- | Vol+ |   |  |   "  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|  Del |
 *                  `-------------|Ply/Pa|    | Enter|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_NUM] = LAYOUT( \
  KC_1       , KC_2       , KC_3       , KC_4       , KC_5       , KC_6       , KC_7       , KC_8       , KC_9       , KC_0       , \
  LSFT(KC_1) , LSFT(KC_2) , LSFT(KC_3) , LSFT(KC_4) , LSFT(KC_5) , LSFT(KC_6) , LSFT(KC_7) , LSFT(KC_8) , KC_PLUS , KC_MINUS , \
  LGUI(KC_1) , LGUI(KC_2) , LGUI(KC_3) , LGUI(KC_4) , LGUI(KC_5) , LGUI(KC_6) , LGUI(KC_7) , LGUI(KC_8) , LGUI(KC_9) , KC_ENTER , \
                    _______, _______, _______,      MO(_FKEY),  KC_TAB, _______                     \
),

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      | F11  |           |  F12 |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Reset|      |      |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_FKEY] =  LAYOUT( \
  KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , \
  KC_F11, KC_F12, _______ , SGUI(KC_UP) ,  _______  , LCTL(KC_LEFT)  , LCTL(KC_UP) , LCTL(KC_DOWN) , LCTL(KC_RIGHT) ,  _______ , \
  _______ ,_______ ,SGUI(KC_LEFT)  ,  SGUI(KC_DOWN) , SGUI(KC_RIGHT) ,  _______ , _______ , _______ , LALT(KC_DOT) , LCTL(KC_SLASH) , \
                    _______, _______, _______,      LSFT(KC_SPACE),  _______, _______                   \
),

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |  F12 |      |      |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Reset|      |      |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_HARDWARE] =  LAYOUT( \
  _______ , _______ , _______ , _______ , _______ ,          _______ , _______ , _______ , _______ , RESET , \
  _______ , _______ , _______ , _______ , _______ ,          _______ , _______ , _______ , _______ , _______ , \
  _______ , _______ , _______ , _______ , _______ ,          _______ , _______ , _______ , _______ , _______ , \
                      _______ , _______ , _______ ,          _______ , _______ , _______                   \
)
};
