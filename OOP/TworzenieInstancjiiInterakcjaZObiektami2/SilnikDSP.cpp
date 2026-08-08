//
// Created by mf on 8/8/26.
//

#include "SilnikDSP.h"

int SilnikDSP::m_sampleRate = 44100;

void SilnikDSP::przetworzLancuch(ProbkaAudio&p,void(ProbkaAudio::*tablica[])(), int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
            (p.*tablica[i])();
    }
}
