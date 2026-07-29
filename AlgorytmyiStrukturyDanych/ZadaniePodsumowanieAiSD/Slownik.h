#include <list>
#include "Drzewo.h"
#include <string>
#include <vector>
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
    vector<list <Slownik*>> slownik;
    int tabSize;
    int iloscElementow;
};

int hashCode(string key);
int hashFunction(Mapa* m,string key);
int znajdzIndeksKLucza(list<Slownik*> slownik,string klucz);
bool znajdzKLucz(list<Slownik*> slownik,string klucz);
void insert(Mapa*mapa, string klucz, Drzewo* drzewo0);
Slownik* odczytajZListy(list<Slownik *> slownik, int index);

#endif //ZADANIEPODSUMOWANIEAISD_SLOWNIK_H
