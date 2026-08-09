//
// Created by mf on 8/9/26.
//

#ifndef POLIMORFIZM_KOREKTOR_H
#define POLIMORFIZM_KOREKTOR_H
#include "Wtyczka.h"

class Korektor: virtual public Wtyczka {
    public:
    Korektor(bool t, double w): Wtyczka(t,w) {};
    double przetworzProbke(double p) override {return m_czestotliowscProbkowania * 1.5;}
   ~Korektor() {std::cout<<"Destrkutor Korektor\n"<<std::endl;};
};


#endif //POLIMORFIZM_KOREKTOR_H
