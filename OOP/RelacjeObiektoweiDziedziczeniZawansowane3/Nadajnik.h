//
// Created by mf on 8/11/26.
//

#ifndef RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE3_NADAJNIK_H
#define RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE3_NADAJNIK_H
#include "ModulAwioniki.h"


class Nadajnik: virtual public ModulAwioniki {
protected:
    int m_stanZasilania=0;
public:
    Nadajnik(int n):ModulAwioniki(n){}
};


#endif //RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE3_NADAJNIK_H
