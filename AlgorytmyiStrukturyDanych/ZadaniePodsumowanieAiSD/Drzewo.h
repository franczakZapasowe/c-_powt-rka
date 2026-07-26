//
// Created by mf on 7/27/26.
//

#ifndef ZADANIEPODSUMOWANIEAISD_DRZEWO_H
#define ZADANIEPODSUMOWANIEAISD_DRZEWO_H

struct Node {
    int klucz;
    int wartosc;
    Node* prway;
    Node* lewy;
    Node* ojciec;
};


struct Drzewo {
  Node*korzen;
};

//podstawowe operacje
Drzewo* newDrzewo(Node*n);
void deleteDrzewo(Drzewo* d);
//funkcjonalnosci
void insert(Drzewo* drzewo, int klucz, int wartosc);

#endif //ZADANIEPODSUMOWANIEAISD_DRZEWO_H
