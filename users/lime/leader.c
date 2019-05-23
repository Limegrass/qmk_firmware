#include "leader.h"
#include "quantum.h"

LEADER_EXTERNS();
void matrix_scan_user(void){
    LEADER_DICTIONARY(){
        leading = false;
        leader_end();
        SEQ_ONE_KEY(KC_Q){
            SEND_STRING("Test");
        }
        leader_end();
    }
}
