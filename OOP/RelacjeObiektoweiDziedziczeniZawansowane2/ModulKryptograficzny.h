//
// Created by mf on 8/10/26.
//

#ifndef RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE2_MODULKRYPTOGRAFICZNY_H
#define RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE2_MODULKRYPTOGRAFICZNY_H
#include <iostream>

class ModulKryptograficzny {
    int m_kluczSzyfrujacy;
public:
    ModulKryptograficzny(int kluczSzyfrujacy):m_kluczSzyfrujacy(kluczSzyfrujacy) {}
    ~ModulKryptograficzny(){std::cout<<"Destruktor modul kryptograficzny\n";}
    int szyfruj(int dane);
};


#endif //RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE2_MODULKRYPTOGRAFICZNY_H
