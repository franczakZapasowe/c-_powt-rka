#include <iostream>
#include "KanalBebnow.h"
#include "KanalMiksera.h"
#include "KanalWokalu.h"

int main() {
    KanalMiksera *tablica[4];
    tablica[0]=new KanalWokalu("Eq");
    tablica[1]=new KanalWokalu("Deser");
    tablica[2]=new KanalBebnow("HH");
    tablica[3]=new KanalBebnow("Base");

    for (int i=0;i<4;i++) {
        tablica[i]->przetwarzaj();
        KanalWokalu *wokal = dynamic_cast<KanalWokalu *>(tablica[i]);
        if (wokal!=nullptr) wokal->ustawAutoTune(i+0.1);
    }

    for (int i=0;i<4;i++) {
        if (tablica[i]!=nullptr) {
            delete tablica[i];
            tablica[i]=nullptr;
        }
    }
}