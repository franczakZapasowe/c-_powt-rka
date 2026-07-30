#include <iostream>
#include "Slownik.h"
#include "Drzewo.h"
#include <string>
#include <cmath>
using namespace std;

void dodajPasmoDoPresetu(Mapa* mapa, string nazwaPresetu, int czestotliowsc, int reatio ) {
    int position = hashFunction(mapa,nazwaPresetu);
    int index = znajdzIndeksKLucza(mapa->slownik[position],nazwaPresetu);
    if (index==-1) {
        Drzewo* noweDrzewo = new Drzewo;
        noweDrzewo->korzen=nullptr;
        insert(mapa,nazwaPresetu,noweDrzewo);
        insertTree(noweDrzewo,czestotliowsc,reatio);
        return;
    }else {
        Slownik* p = odczytajZListy(mapa->slownik[position],index);
        insertTree(p->drzewo,czestotliowsc,reatio);
        return;
    }
}

int znajdzNajblizszePasmo(Drzewo* drzewo, int doceloweHz) {
    int temp = 1000000000;
    int delta = 0;
    int najlepszyKlucz = 0;
    if (drzewo!=nullptr) {
        Node * wezel = drzewo->korzen;
        while (wezel!=nullptr) {
            delta = abs(doceloweHz - wezel->klucz );
            if (delta < temp) {temp = delta; najlepszyKlucz = wezel->klucz;}

            if (wezel->klucz > doceloweHz ) wezel = wezel->lewy;
            else wezel = wezel->prawy;
        }
        return najlepszyKlucz;
    }

    return -10000;
}

Drzewo* skopiujPreset(Drzewo* zrodlo) {
    if (zrodlo!=nullptr) {
        Drzewo *nowe = new Drzewo;
        nowe ->korzen = copyHelper(zrodlo->korzen);
        return nowe;
    }
    return nullptr;
}

void zniszczSilnik(Mapa*mapa) {
    for (auto &szufladka : mapa->slownik) {
        for (auto &slownik : szufladka) {
            deleteHelper(slownik->drzewo->korzen);
            delete slownik->drzewo;
            delete slownik;
        }
    }
    delete mapa;
}
int main() {



}