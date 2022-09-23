#pragma once
#include "Utils.h"

typedef struct CHANNEL_VALUE {
    double amp;
    double panL;
    double panR;
    double pitch;

    int writeIndex;
    int tapSize;
    double* pTapL;
    double* pTapR;
};
typedef struct CHANNEL_PARAM {
    byte isDrum;
    byte bankM;
    byte bankL;
    byte prog;

    byte vol;
    byte exp;
    byte pan;

    byte rev;
    byte cho;
    byte del;

    byte mod;
    byte cutoff;
    byte reso;

    byte attack;
    byte release;
    byte hold;

    byte rpnL;
    byte rpnR;
    byte data;
    byte pitchRange;

    int pitch;
};

class Channel {
public:
    int number;
    CHANNEL_PARAM param;
    CHANNEL_VALUE value;
    Channel(int number);
    void send(byte* pMsg);
private:
    void note_on(byte note, byte velo);
    void note_off(byte note);
    void ctrl_chg(byte type, byte value);
    void prog_chg(byte num);
};
