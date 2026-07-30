//
// Created by mf on 7/27/26.
//

#ifndef ZADANIEPODSUMOWANIEAISD_DRZEWO_H
#define ZADANIEPODSUMOWANIEAISD_DRZEWO_H
#include <algorithm>

struct Node {
    int klucz;
    int wartosc;
    Node* prawy;
    Node* lewy;
    Node* ojciec;

    Node(int klucz, int wartosc):klucz(klucz), wartosc(wartosc), prawy(nullptr), lewy(nullptr), ojciec(nullptr){}

};

Node*copyHelper(const Node* source, Node*parent = nullptr);
void deleteHelper(Node * nowy);

struct Drzewo {
    Node*korzen;

    Drzewo():korzen(nullptr){}

    //konstruktor kopiujacy
    Drzewo(const Drzewo&other) {
        this->korzen = copyHelper(other.korzen);
    }

    Drzewo& operator=(const Drzewo&other) {
        if (this != &other) {
            deleteHelper(this->korzen);
            this->korzen = copyHelper(other.korzen);
        }
        return *this;
    }

    ~Drzewo() {
        deleteHelper(this->korzen);
    }
};
//podstawowe operacje
Drzewo* newDrzewo(Node*n);
void deleteDrzewo(Drzewo* d);
//funkcjonalnosci
void insertTree(Drzewo* drzewo, int klucz, int wartosc);
Drzewo* deepCopyDrzewo(const Drzewo* drzewo);
#endif //ZADANIEPODSUMOWANIEAISD_DRZEWO_H
