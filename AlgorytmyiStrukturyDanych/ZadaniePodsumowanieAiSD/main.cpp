#include <iostream>
#include "Slownik.h"
#include "Drzewo.h"
#include <string>
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

int main() {

}