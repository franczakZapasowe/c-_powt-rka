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

void insertTree(Drzewo* drzewo, int klucz, int wartosc) {
        Node* nowy = new Node(klucz, wartosc);
        nowy -> wartosc = wartosc;
        nowy -> klucz = klucz;
        nowy -> ojciec = nullptr;
        nowy -> prawy = nullptr;
        nowy -> lewy = nullptr;
        if (drzewo->korzen==nullptr) {
            drzewo->korzen = nowy;
            return;
        }
        Node* wezel = drzewo->korzen;
        Node* ojciec = nullptr;
        while (wezel!=nullptr) {
            ojciec = wezel;
            if (wezel->klucz > nowy->klucz) {
                wezel = wezel->lewy;
            }else {
                wezel = wezel->prawy;
            }
        }
        nowy->ojciec = ojciec;
        if (ojciec->klucz> nowy->klucz) {ojciec->lewy = nowy; return;}
        else {ojciec->prawy = nowy; return;}
}

Node*copyHelper(const Node* source, Node*parent){
  if (source == nullptr) return nullptr;

    Node*nowy = new Node(source->klucz, source->wartosc);

    nowy->ojciec = parent;

    nowy->lewy = copyHelper(source->lewy, nowy);
    nowy->prawy = copyHelper(source->prawy, nowy);

    return nowy;
}

void deleteHelper(Node* nowy) {
    if (nowy == nullptr) return;
    deleteHelper(nowy->lewy);
    deleteHelper(nowy->prawy);
    delete nowy;
}