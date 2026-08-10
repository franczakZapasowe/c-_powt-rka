//
// Created by mf on 8/10/26.
//

#include "Sejf.h"
#include "iostream"
void Sejf::odczytajDane(Osoba &os) {
    if (m_zamek.weryfikuj(os)) {
        std::cout<<"Otwarto sejf\n";
        for (int i = 0; i< 10; i++) {
            std::cout<<m_tablica[i]<<" ";
        }
        std::cout<<"\n";
    }
    else
        std::cout<<"Nie mozna otworzyc sejfu\n";
}

void Sejf::zmienOsobeUprawniona(Osoba &os) {
        m_zamek.zmianaOsobyUprawnionej(os);
}

void Sejf::usunDostep(Osoba &os) {
    m_zamek.usuniecieOsoby(os);
}

bool Sejf::czyDostep(Osoba &os) {
    return m_zamek.weryfikuj(os);
}
