#include "channel.h"
#include "midi.h"

Channel::Channel(int number) {
    this->number = number;
    param = CHANNEL_PARAM();
    value = CHANNEL_VALUE();
}

void Channel::send(byte* pMsg) {
    auto status = (MIDI_STATUS)((*pMsg) & 0xF0);
    switch (status) {
    case MIDI_STATUS::NOTE_OFF:
        note_off(pMsg[1]);
        break;
    case MIDI_STATUS::NOTE_ON:
        note_on(pMsg[1], pMsg[2]);
        break;
    case MIDI_STATUS::CTRL_CHG:
        ctrl_chg(pMsg[1], pMsg[2]);
        break;
    case MIDI_STATUS::PROG_CHG:
        prog_chg(pMsg[1]);
        break;
    case MIDI_STATUS::PITCH:
        break;
    default:
        break;
    }
}

void Channel::note_off(byte note) {
}

void Channel::note_on(byte note, byte velo) {
    if (0 == velo) {
        note_off(note);
        return;
    }
}

void Channel::prog_chg(byte num) {
}

void Channel::ctrl_chg(byte type, byte value) {
    switch ((MIDI_CTRL)type) {
    case MIDI_CTRL::BANK_MSB:
    case MIDI_CTRL::BANK_LSB:
    case MIDI_CTRL::VOLUME:
    case MIDI_CTRL::EXPRESSION:
    case MIDI_CTRL::PAN:
        break;
    default:
        break;
    }
}

