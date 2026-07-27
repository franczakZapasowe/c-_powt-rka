//
// Created by mf on 7/27/26.
//

#include "Drzewo.h"

Drzewo* newDrzewo(Node* m) {
    if (m!=nullptr) {
        Drzewo* drz = new Drzewo;
        drz->korzen = m;
        return drz;
    }
    return nullptr;
}

void deleteDrzewo(Drzewo* d) {
    delete d;
}

void insert(Drzewo* drzewo, int klucz, int wartosc) {
    if (drzewo!=nullptr) {
        Node* nowy = new Node;
        nowy -> wartosc = wartosc;
        nowy -> klucz = klucz;
        if (drzewo->korzen==nullptr) {
            drzewo->korzen = nowy;
            return;
        }
        else if (wartosc < drzewo->korzen->wartosc) {
            drzewo->korzen->lewy = nowy;
            return;
        }
        else if (wartosc > drzewo->korzen->wartosc) {
            drzewo->korzen->prway = nowy;
            return;
        }
    }
    return;
}