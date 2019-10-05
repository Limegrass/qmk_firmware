ifeq ($(strip $(LEADER_ENABLE)), yes)
	SRC += leader.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += tapdance.c
endif

ifeq ($(strip $(UNICODEMAP_ENABLE)), yes)
	SRC += unicode_map.c
endif

ifeq ($(strip $(UCIS_ENABLE)), yes)
	SRC += ucis.c
endif
