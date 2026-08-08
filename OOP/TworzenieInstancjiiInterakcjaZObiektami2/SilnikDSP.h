//
// Created by mf on 8/8/26.
//

#ifndef POWTORKA_SILNIKDSP_H
#define POWTORKA_SILNIKDSP_H
#include "ProbkaAudio.h"

class SilnikDSP {
    static int m_sampleRate;
    SilnikDSP()=delete;
    ~SilnikDSP()=delete;
public:
    static int getSampleRate() {return m_sampleRate;}
    static void przetworzLancuch(ProbkaAudio&p,void(ProbkaAudio::*tablica[])(), int rozmiar);
};


#endif //POWTORKA_SILNIKDSP_H
