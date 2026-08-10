//
// Created by mf on 8/10/26.
//

#ifndef RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE2_DRON_H
#define RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE2_DRON_H
#include <iostream>
#include "ModulKryptograficzny.h"

class Operator;

class Dron {
    ModulKryptograficzny m_modul;
    int m_numerSeryjny;
    Operator *m_operatoor = nullptr;
    friend Operator;
public:
    ~Dron() {
        std::cout<<"Destruktor DRON\n";
        usunOperatora();
    }
    void wyslijRaport(int tajneDane);

    Dron(const ModulKryptograficzny &m_modul, int m_numer_seryjny)
        : m_modul(m_modul),
          m_numerSeryjny(m_numer_seryjny) {
    }
    Dron(int numerSeryjny, int kluczSzyfrujacy):m_modul(kluczSzyfrujacy),m_numerSeryjny(numerSeryjny){}
    void przypiszOperatora(Operator&o);
    void usunOperatora();
};


#endif //RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE2_DRON_H
