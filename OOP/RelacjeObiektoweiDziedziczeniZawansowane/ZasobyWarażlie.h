//
// Created by mf on 8/10/26.
//

#ifndef RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE_ZASOBYWARAŻLIE_H
#define RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE_ZASOBYWARAŻLIE_H
#include "Sejf.h"
#include  "Osoba.h"
class ZasobyWarażlie {
    Sejf *m_sejfy[10];
    int m_liczbaSejfow = 0;
public:
    int ileSejfowMaOsoba(Osoba &os);
    void dodajSejf (Sejf &sejf);
    void dodajUprawnieniea(Osoba &os, int nr);
    void zabierzUprawnieniea(Osoba &os, int nr);
};


#endif //RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE_ZASOBYWARAŻLIE_H
