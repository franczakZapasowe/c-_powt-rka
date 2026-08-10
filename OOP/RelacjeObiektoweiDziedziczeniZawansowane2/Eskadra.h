//
// Created by mf on 8/11/26.
//

#ifndef RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE2_ESKADRA_H
#define RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE2_ESKADRA_H

#include "Dron.h"
class Eskadra {
    Dron *m_drony[20] = {};
    int m_licznikDronow = 0;
public:
    void dodajDrona(Dron &d);
    void usunDrona(Dron &d);
};


#endif //RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE2_ESKADRA_H
