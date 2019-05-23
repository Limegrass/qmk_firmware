#ifndef LIME_TAPDANCE_H
#define LIME_TAPDANCE_H
#include "quantum.h"
enum TDKeys {
    TD_SPACE_ENTER_SHIFT = 0
};
int evaluate_taps (qk_tap_dance_state_t *state);
int evaluate_single_tap_action (qk_tap_dance_state_t *state);
int evaluate_double_tap_action (qk_tap_dance_state_t *state);
void space_enter_shift_finished(qk_tap_dance_state_t *state, void *user_data);
void space_enter_shift_reset(qk_tap_dance_state_t *state, void *user_data);
#endif
