ifeq ($(strip $(LEADER_ENABLE)), yes)
    SRC += leader.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
    SRC += tapdance.c
endif
