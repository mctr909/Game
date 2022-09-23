#pragma once
#include "Utils.h"

enum struct MIDI_STATUS {
    NOTE_OFF = 0x80,
    NOTE_ON = 0x90,
    POLY_KEY = 0xA0,
    CTRL_CHG = 0xB0,
    PROG_CHG = 0xC0,
    CH_PRESS = 0xD0,
    PITCH = 0xE0,
    SYSEX = 0xF0,
};

enum struct MIDI_META {
    SEQ_NUM = 0x00,

    TEXT = 0x01,
    COPYRIGHT = 0x02,
    SEQ_NAME = 0x03,
    INST_NAME = 0x04,
    LYRIC = 0x05,
    MARK = 0x06,
    QUEUE = 0x07,
    PROG_NAME = 0x08,
    DEV_NAME = 0x09,
    
    CH_PRE = 0x20,
    PORT = 0x21,
    EOT = 0x2F,
    
    TEMPO = 0x51,
    MESURE = 0x58,
    KEY = 0x59
};

enum struct MIDI_CTRL {
    BANK_MSB = 0,
    BANK_LSB = 32,

    VOLUME = 7,
    PAN = 10,
    EXPRESSION = 11,

    HOLD = 69,
    RELEASE = 72,
    ATTACK = 73,

    RESONANCE = 71,    
    CUTOFF = 74,

    MOD_MSB = 1,
    MOD_LSB = 33,
    VIB_RATE = 76,
    VIB_DEPTH = 77,
    VIB_DELAY = 78,

    REVERB = 91,
    CHORUS = 93,
    DELAY = 94,

    DATA_MSB = 6,
    DATA_LSB = 38,
    RPN_LSB = 100,
    RPN_MSB = 101,

    SOUND_OFF = 120,
    RESET_CTRL = 121
};

void midi_init();
void midi_send(byte* pMsg);