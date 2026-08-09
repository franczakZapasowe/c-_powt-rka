//
// Created by mf on 8/9/26.
//

#ifndef POLIMORFIZM_KOMPRESOR_H
#define POLIMORFIZM_KOMPRESOR_H
#include "Wtyczka.h"

class Kompresor: virtual public Wtyczka {
public:
    double przetworzProbke(double p) override{return p /0.8;}
    Kompresor(bool t, double w):Wtyczka(t,w) {};
    ~Kompresor(){std::cout<<"Destruktor kompresor\n";}
};


#endif //POLIMORFIZM_KOMPRESOR_H
