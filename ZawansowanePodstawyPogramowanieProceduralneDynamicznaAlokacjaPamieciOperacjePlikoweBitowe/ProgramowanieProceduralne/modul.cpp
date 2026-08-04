//
// Created by mf on 8/1/26.
//
#include "modul.h"
#include <iostream>
#include <random>
namespace modul {
    void generatorLiczb() {
        static int poprzedniStan;
        std::cout<<"Poprdzedni stan: "<<poprzedniStan<<"\n";
        std::mt19937 rng;
        std::uniform_int_distribution<std::mt19937::result_type> dist;
        int aktualnystan = dist(rng);
        poprzedniStan = aktualnystan*bazowyMnoznik;
        std::cout<<"Wynik: "<<aktualnystan*bazowyMnoznik<<"\n";
    }
    int bazowyMnoznik = 10;
}
