#include "keyactions.h"
#include "quantum.h"

int evaluate_single_tap_action(qk_tap_dance_state_t *state){
    if(state->pressed){
        return HOLD;
    }
    return TAP;
}

int evaluate_double_tap_action(qk_tap_dance_state_t *state){
    if(state->interrupted){
        return TWO_SINGLE_TAPS;
    }
    if(state->pressed){
        return TAP_HOLD;
    }
    return DOUBLE_TAP;
}

int evaluate_taps(qk_tap_dance_state_t *state) {
    switch(state->count){
        case 1:
            return evaluate_single_tap_action(state);
        case 2:
            return evaluate_double_tap_action(state);
        default:
            return 0;
    }
}

static int space_enter_shift_count = 0;
void space_enter_shift_finished(qk_tap_dance_state_t *state, void *user_data){
    space_enter_shift_count = evaluate_taps(state);
    switch(space_enter_shift_count){
        case TAP:
            register_code(KC_SPACE);
            break;
        case HOLD:
            register_mods(MOD_BIT(KC_LSFT));
            break;
        case DOUBLE_TAP:
            register_code(KC_ENTER);
            break;
        case TWO_SINGLE_TAPS:
            register_code(KC_SPACE);
            unregister_code(KC_SPACE);
            register_code(KC_SPACE);
            break;
    }
}

void space_enter_shift_reset(qk_tap_dance_state_t *state, void *user_data){
    switch(space_enter_shift_count){
        case TAP:
            unregister_code(KC_SPACE);
            break;
        case HOLD:
            unregister_mods(MOD_BIT(KC_LSFT));
            break;
        case DOUBLE_TAP:
            unregister_code(KC_ENTER);
            break;
        case TWO_SINGLE_TAPS:
            unregister_code(KC_SPACE);
            break;
    }
}

