//
// Created by mf on 8/10/26.
//

#ifndef POLIMORFIZM_DIAGNOSTYCZNA_H
#define POLIMORFIZM_DIAGNOSTYCZNA_H
#include "Wtyczka.h"


class Diagnostyczna: private Wtyczka{
public:
    using Wtyczka::getAktywnosc;
    Diagnostyczna(bool b, double t) :Wtyczka(b,t) {};
    double przetworzProbke(double p) override {return p;}
};


#endif //POLIMORFIZM_DIAGNOSTYCZNA_H
