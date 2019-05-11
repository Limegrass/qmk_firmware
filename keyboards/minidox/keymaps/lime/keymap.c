#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _NUM 1
#define _FKEY 2
#define _CODE 3
#define _HARDWARE 16


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define ESC_NUM LT(_NUM, KC_ESCAPE)
#define SPACE_FKEY LT(_FKEY, KC_SPACE)
#define ENTER_CODE LT(_CODE, KC_ENTER)
#define TAB_CTRL LCTL(KC_TAB)

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
[_QWERTY] = LAYOUT( \
  KC_Q          , KC_W , KC_E , KC_R , KC_T , KC_Y , KC_U , KC_I , KC_O    , KC_P    , \
  KC_A          , KC_S , KC_D , KC_F , KC_G , KC_H , KC_J , KC_K , KC_L    , KC_SCLN , \
  OSM(MOD_LSFT) , KC_Z , KC_X , KC_C , KC_V , KC_B , KC_N , KC_M , KC_COMM , KC_DOT  , \
         KC_LGUI, TAB_CTRL,   ESC_NUM,         SPACE_FKEY, ENTER_CODE, KC_BSPC   \
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
  KC_PIPE  , KC_BSLASH     , KC_LEFT_CURLY_BRACE , KC_RIGHT_CURLY_BRACE , KC_SLASH, _______ , KC_HOME , KC_END  , KC_PGUP  , KC_PGDN , \
  KC_TILDE , KC_UNDERSCORE , KC_LEFT_PAREN       , KC_RIGHT_PAREN       , KC_QUESTION, KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , KC_INS  , \
  KC_GRAVE , KC_QUOTE      , KC_LBRACKET         , KC_RBRACKET          , _______ , _______ , _______ , _______ , _______  , _______ , \
                    _______, _______, MO(_HARDWARE),       _______, _______, KC_DEL                      \
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
  LSFT(KC_1) , LSFT(KC_2) , LSFT(KC_3) , LSFT(KC_4) , LSFT(KC_5) , LSFT(KC_6) , LSFT(KC_7) , LSFT(KC_8) , LSFT(KC_9) , LSFT(KC_0) , \
  LGUI(KC_1) , LGUI(KC_2) , LGUI(KC_3) , LGUI(KC_4) , LGUI(KC_5) , LGUI(KC_6) , LGUI(KC_7) , LGUI(KC_8) , LGUI(KC_9) , LGUI(KC_0) , \
                    _______, _______, _______,      _______,  _______, _______                     \
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
[_FKEY] =  LAYOUT( \
  KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , \
  _______ , _______ , _______ , _______ , KC_F11  , KC_F12  , _______ , _______ , _______ , _______ , \
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , \
                    _______, _______, _______,      _______,  _______, _______                   \
)
};

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

/*
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};
  void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_FN1);
        update_tri_layer(_FN1, _FN2, _ADJUST);
      } else {
        layer_off(_FN1);
        update_tri_layer(_FN1, _FN2, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_FN2);
        update_tri_layer(_FN1, _FN2, _ADJUST);
      } else {
        layer_off(_FN2);
        update_tri_layer(_FN1, _FN2, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
*/
