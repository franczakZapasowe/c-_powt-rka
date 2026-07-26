#include <list>
#include "Drzewo.h"
#include <string>

using namespace std;

#ifndef ZADANIEPODSUMOWANIEAISD_SLOWNIK_H
#define ZADANIEPODSUMOWANIEAISD_SLOWNIK_H

struct Slownik {
    string klucz;
    Drzewo* drzewo;
};

Slownik * newSlownik(string klucz, Drzewo* drzewo);
void destroySlownik(Slownik* slownik);

struct Mapa {
    list<Slownik*> slownik;
    int tabSize;
    int iloscElementow;
};

int hashCode(string key);
int hashFunction(string key);
#endif //ZADANIEPODSUMOWANIEAISD_SLOWNIK_H
