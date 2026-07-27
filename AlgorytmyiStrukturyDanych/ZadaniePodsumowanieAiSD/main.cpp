#include <iostream>
#include "Slownik.h"
#include "Drzewo.h"
#include <string>
using namespace std;

void dodajPasmoDoPresetu(Mapa* mapa, string nazwaPresetu, int czestotliowsc, int reatio ) {
    int hash = hashFunction(nazwaPresetu);
    if (znajdzIndeksKLucza(mapa->slownik,nazwaPresetu)) {
        Drzewo* drzewo = new Drzewo;

    }else {

    }
}

int main() {

}