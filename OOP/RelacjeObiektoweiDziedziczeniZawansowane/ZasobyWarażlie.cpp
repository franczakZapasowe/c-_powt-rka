//
// Created by mf on 8/10/26.
//

#include "ZasobyWarażlie.h"

int ZasobyWarażlie::ileSejfowMaOsoba(Osoba &os) {
    int ile = 0;
    for (int i = 0; i < m_liczbaSejfow; i++) {
        if (m_sejfy[i]->czyDostep(os))ile++;
    }
    return ile;
}

void ZasobyWarażlie::dodajSejf(Sejf &sejf) {
    for (int i = 0; i < m_liczbaSejfow; i++) if (m_sejfy[i] == &sejf) return ;

    if (m_liczbaSejfow<10) {
        m_sejfy[m_liczbaSejfow++] = &sejf;
    }
}


void ZasobyWarażlie::dodajUprawnieniea(Osoba &os, int nr) {
    if (nr>=0 && nr <m_liczbaSejfow)
        m_sejfy[nr]->zmienOsobeUprawniona(os);
}

void ZasobyWarażlie::zabierzUprawnieniea(Osoba &os, int nr) {
    if (nr>=0 && nr <m_liczbaSejfow)
        m_sejfy[nr]->usunDostep(os);
}
