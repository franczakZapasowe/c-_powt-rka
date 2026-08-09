//
// Created by mf on 8/9/26.
//
#include <iostream>
#ifndef POLIMORFIZM_WTYCZKA_H
#define POLIMORFIZM_WTYCZKA_H


class Wtyczka {
    protected:
    bool m_aktywnosc;
    double m_czestotliowscProbkowania;
    Wtyczka(bool aktywnosc, double czestotliowscProbkowania)
        :m_aktywnosc(aktywnosc),m_czestotliowscProbkowania(czestotliowscProbkowania){}
public:
    virtual bool getAktywnosc(){return m_aktywnosc;}
    virtual double przetworzProbke(double p) = 0;
    virtual ~Wtyczka(){std::cout<<"Destruktor, wtyczka\n";}

};


#endif //POLIMORFIZM_WTYCZKA_H
