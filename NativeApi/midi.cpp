#include "midi.h"
#include "channel.h"

Channel* gpChannels[16];

void midi_init() {
    for (int i = 0; i < 16; i++) {
        gpChannels[i] = new Channel(i);
    }
}

void midi_send(byte* pMsg) {
    if (0xFF == *pMsg) {
    } else if (0xF0 <= *pMsg) {
    } else {
        auto ch = *pMsg & 0xF;
        gpChannels[ch]->send(pMsg);
    }
}
