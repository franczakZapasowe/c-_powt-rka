//
// Created by mf on 8/11/26.
//

#ifndef RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE3_DRONZWIADOWCZY_H
#define RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE3_DRONZWIADOWCZY_H
#include "Kamera.h"
#include "Nadajnik.h"


class DronZwiadowczy:public Kamera ,public Nadajnik {
public:
    DronZwiadowczy(int n):Kamera(), Nadajnik(),ModulAwioniki(n) {};
    void resetSystemowy();
};


#endif //RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE3_DRONZWIADOWCZY_H
