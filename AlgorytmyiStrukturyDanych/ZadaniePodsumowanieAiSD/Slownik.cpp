//
// Created by mf on 7/27/26.
//

#include "Slownik.h"

//--------------------------Funkcje pomocnicze
Slownik* newSlownik(string klucz, Drzewo* drzewo){
    if (drzewo!=nullptr) {
        Slownik* slownik = new Slownik;
        slownik->klucz = klucz;
        slownik->drzewo = drzewo;
        return slownik;
    }
    return nullptr;
}

void destroySlownik(Slownik* slownik) {
    delete slownik;
}

Slownik* odczytajZListy(list<Slownik *> slownik, int index) {
    auto iter = slownik.begin();
    advance(iter,index);
    return *iter;
}

// ------------------------- FUNKCJE HASHUJACE
int hashCode(string key) {
    int hash = 0;
    for (char ch: key) {
        int chint = (int)ch;
        hash+=chint;
    }
    return hash;
}

int hashFunction(Mapa* m, string key) {
    int hash = hashCode(key);
    return hash % m->tabSize;
}

int znajdzIndeksKLucza(list<Slownik *> slownik, string klucz) {
    int i = 0;
    for (Slownik* s : slownik) {
        if (s->klucz == klucz) {
            return i;
        }
        i++;
    }
    return -1;
}

bool znajdzKLucz(list<Slownik *> slownik, string klucz) {
    return znajdzIndeksKLucza(slownik, klucz) >-1;
}

void insert(Mapa*mapa, string klucz, Drzewo* drzewo0) {
    if (mapa!=nullptr) {
        int position = hashFunction(mapa, klucz);
        int index = znajdzIndeksKLucza(mapa->slownik[position], klucz);
        if (index!=-1) {
            Slownik * s = odczytajZListy(mapa->slownik[position], index);
            s->drzewo = drzewo0;
            return;
        }else {
            Slownik* para = new Slownik;
            para->klucz = klucz;
            para->drzewo = drzewo0;
            mapa->slownik[position].emplace_front(para);
            mapa->iloscElementow++;
            return;
        }
    }
    return;
}