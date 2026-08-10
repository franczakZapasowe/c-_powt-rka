//
// Created by mf on 8/11/26.
//

#ifndef RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE3_KAMERA_H
#define RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE3_KAMERA_H
#include "ModulAwioniki.h"


class Kamera: virtual public ModulAwioniki {
protected:
    int m_stanZasilania;
public:
    Kamera(int n):ModulAwioniki(n){}
};


#endif //RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE3_KAMERA_H
