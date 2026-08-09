//
// Created by mf on 8/9/26.
//

#ifndef POLIMORFIZM_WIELOPASMOWY_H
#define POLIMORFIZM_WIELOPASMOWY_H
#include "Kompresor.h"
#include "Korektor.h"


class Wielopasmowy: public Kompresor, public Korektor{
public:
    double przetworzProbke(double p) final {
        return p * 1.2;
    }
    Wielopasmowy(bool t, double w):Kompresor(t,w),Korektor(t,w), Wtyczka(t,w){}
    ~Wielopasmowy() {std::cout << "Wielopasmowy" << std::endl;}
};


#endif //POLIMORFIZM_WIELOPASMOWY_H
