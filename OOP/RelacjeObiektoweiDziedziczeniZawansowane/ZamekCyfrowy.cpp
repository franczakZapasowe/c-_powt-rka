//
// Created by mf on 8/10/26.
//

#include "ZamekCyfrowy.h"

#include <iostream>


bool ZamekCyfrowy::weryfikuj(Osoba &os) {
    if (czyPusta()) {
        return true;
    }else {
        for (int i = 0; i < 3; i++) {
            if (m_osoby[i] == &os)
                return true;
        }
    }
    return false;
}

bool ZamekCyfrowy::czyPusta() const {
    return m_licznikOsob == 0;
}

void ZamekCyfrowy::zmianaOsobyUprawnionej(Osoba &os) {
    for (int i = 0; i < 3; i++) {
        if (m_osoby[i]==nullptr) {
            m_osoby[i] = &os;
            m_licznikOsob++;
            break;
        }
    }
}

void ZamekCyfrowy::usuniecieOsoby(Osoba &os) {
    for (int i = 0; i < 3; i++) {
        if (m_osoby[i] == &os) {
            m_osoby[i] = nullptr;
            m_licznikOsob--;
            break;
        }
    }
}
