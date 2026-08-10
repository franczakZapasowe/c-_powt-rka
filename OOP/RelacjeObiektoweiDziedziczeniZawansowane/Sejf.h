//
// Created by mf on 8/10/26.
//

#ifndef RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE_SEJF_H
#define RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE_SEJF_H
#include "ZamekCyfrowy.h"
#include "Osoba.h"

class Sejf {
    int m_tablica[10];
    ZamekCyfrowy m_zamek;
public:

    Sejf(const int tablica[10], Osoba &osoba) : m_zamek(osoba) {
        for (int i = 0; i < 10; i++) {
            m_tablica[i] = tablica[i];
        }
    }
    Sejf(const int tablica[10]) {
        for (int i = 0; i < 10; i++) {
            m_tablica[i] = tablica[i];
        }
    }

    ~Sejf(){}
    void odczytajDane(Osoba &os);
    void zmienOsobeUprawniona(Osoba &os);
    bool czyDostep(Osoba &os);
    void usunDostep(Osoba &os);
};


#endif //RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE_SEJF_H
