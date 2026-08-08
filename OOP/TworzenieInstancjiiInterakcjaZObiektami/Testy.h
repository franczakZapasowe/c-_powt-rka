//
// Created by mf on 8/8/26.
//

#ifndef ZADANIE_TESTY_H
#define ZADANIE_TESTY_H
#include "dron.h"

class Testy {
public:
    static void testDrona(int (Dron::*wsk)() const, const Dron &dron );
    Testy()=delete;
private:
    static int liczbaUdanych;
    static int liczbaWykonanych;
    static void statystyki();
};


#endif //ZADANIE_TESTY_H
