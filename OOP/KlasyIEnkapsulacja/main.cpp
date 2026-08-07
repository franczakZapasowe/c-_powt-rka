#include <iostream>
#include "BateriaPrzemyslowa.h"
int main() {

    BateriaPrzemyslowa p;
    p.setLimitNapiecia(5);
    p.setPoziomNaladowania(1000);
    p.setTemperatura(10);

   // std::cout<<p.getLimitNapiecia()<<std::endl;
    std::cout<<p.getPoziomNaldaowania()<<std::endl;


    int wynik1 = p.skorygowanyPoziomNaladowania(10,12);
    int wynik2 = p.skorygowanyPoziomNaladowania(10000);
    std::cout<<wynik1<<std::endl;
    std::cout<<wynik2<<std::endl;

    return 0;
}