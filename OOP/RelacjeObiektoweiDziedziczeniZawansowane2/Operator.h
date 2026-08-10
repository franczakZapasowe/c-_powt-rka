//
// Created by mf on 8/10/26.
//

#ifndef RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE2_OPERATOR_H
#define RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE2_OPERATOR_H

class Dron;

class Operator {
    Dron *m_dron = nullptr;
    friend Dron;
public:
    void dodajDrona(Dron&d);
    void usunDrona();
    ~Operator(){usunDrona();}
};


#endif //RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE2_OPERATOR_H
