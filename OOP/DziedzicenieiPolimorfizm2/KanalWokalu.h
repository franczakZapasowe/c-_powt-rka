//
// Created by mf on 8/10/26.
//

#ifndef DZIEDZICENIEIPOLIMORFIZM2_KANALWOKALU_H
#define DZIEDZICENIEIPOLIMORFIZM2_KANALWOKALU_H
#include "KanalMiksera.h"

class KanalWokalu: public KanalMiksera {
public:
    KanalWokalu(const char* t):KanalMiksera(t) {}
    void przetwarzaj() override {std::cout<<"Kompresja na kanaleWokalu\n";}
    ~KanalWokalu(){std::cout<<"Destruktor KanalWokalu"<<std::endl;}
    void ustawAutoTune(double sila){std::cout<<"Tune ustawiony na "<<sila<<std::endl;}

};
#endif //DZIEDZICENIEIPOLIMORFIZM2_KANALWOKALU_H
