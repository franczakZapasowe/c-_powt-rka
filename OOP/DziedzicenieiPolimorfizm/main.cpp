#include<iostream>
#include "Wtyczka.h"
#include "Diagnostyczna.h"
#include "Kompresor.h"
#include "Wielopasmowy.h"


int main() {

    Wtyczka *tab[4] = {};

    tab[0]=new Kompresor(true, 20.2);
    tab[1]=new Korektor(true,12.2);
    tab[2]=new Wielopasmowy(true, 22.1);
    tab[3]= (Wtyczka*) new Diagnostyczna(true,1.1);

    double audio = 1.0;
    for (int i=0; i<4; i++) {
        audio = tab[i]->przetworzProbke(audio);
        std::cout<<audio<<std::endl;
    }

    for (int i = 0; i < 4; ++i) {
        if (tab[i] != nullptr) {
            delete tab[i];
            tab[i] = nullptr;
        }
    }
    return 0;
}
