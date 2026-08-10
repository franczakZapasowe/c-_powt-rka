#include <iostream>
#include "Osoba.h"
#include "Sejf.h"
#include "ZamekCyfrowy.h"
#include "ZasobyWarażlie.h"
#
int main() {

    int tablica[10] = {12,412,2,15,23,3,2,1,6};
    Osoba szef;
    Osoba kierownik;
    Osoba zlodziej;
    Osoba pracownik;

    Sejf sejf1(tablica,szef);
    Sejf sejf2(tablica,kierownik);
    Sejf sejf3(tablica);

    ZasobyWarażlie z;
    z.dodajSejf(sejf1);
    z.dodajSejf(sejf2);
    z.dodajSejf(sejf3);

    std::cout<<"Szef ma dostep do(powinno byc 2 prywatny i publiczny): "<<z.ileSejfowMaOsoba(szef)<<std::endl;
    std::cout<<"Zlodziej ma dostep do(powinno byc 1 prywatny): "<<z.ileSejfowMaOsoba(zlodziej)<<std::endl;

    return 0;
}
