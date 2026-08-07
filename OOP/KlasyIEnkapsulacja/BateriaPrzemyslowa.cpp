//
// Created by mf on 8/7/26.
#include "BateriaPrzemyslowa.h"
#include <cassert>
void BateriaPrzemyslowa::setPoziomNaladowania(int p) {
    if (p<0)
        m_poziomNaldaowania = 0;
    else if (p>100)
        m_poziomNaldaowania = 100;
    else
        m_poziomNaldaowania = p;
}

void BateriaPrzemyslowa::setTemperatura(int t) {
    assert(t>=-50 && t<=50);
    m_temperatura = t;
}

void BateriaPrzemyslowa::setLimitNapiecia(int l) {
    assert(l<100);
    m_limitNapiecia = l;
}

void BateriaPrzemyslowa::setterZbiorczy(int p, int t, int l) {
    setPoziomNaladowania(p);
    setTemperatura(t);
    setLimitNapiecia(l);
}


int BateriaPrzemyslowa::skorygowanyPoziomNaladowania(int x, int y) {
    return m_poziomNaldaowania* m_temperatura * m_limitNapiecia*x*y;
}

int BateriaPrzemyslowa::skorygowanyPoziomNaladowania(int x) {
    return m_poziomNaldaowania* m_temperatura * m_limitNapiecia*x;
}


