/*
Copyright 2018 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xCB10
#define PRODUCT_ID      0x1147
#define DEVICE_VER      0x0100
#define MANUFACTURER    Keebio
#define PRODUCT         Laplace
#define DESCRIPTION     40 percent staggered keyboard

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 7

/* key matrix pins */
#define MATRIX_ROW_PINS {D3, F4, D2, F5, D7, B4, D0, E6}
#define MATRIX_COL_PINS {D1, B5, F7, B1, B3, B2, B6}
/* Originals (My arduino is broken so I have custom pins) */
/* #define MATRIX_ROW_PINS {D3, F4, D2, F5, D7, B4, C6, E6} */
/* #define MATRIX_COL_PINS {D1, F6, F7, B1, B3, B2, B6} */

/* WS2812 RGB LED */
#define RGB_DI_PIN D4
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 14

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define TAPPING_TERM 120
/* #define TAPPING_TERM 200 */
#define ONESHOT_TAP_TOGGLE 5  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 333  /* Time (in ms) before the one shot key is released */

#define RETRO_TAPPING

/* key combination for magic key command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

#endif
