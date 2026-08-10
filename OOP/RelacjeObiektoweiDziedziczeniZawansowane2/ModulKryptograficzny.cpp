//
// Created by mf on 8/10/26.
//

#include "ModulKryptograficzny.h"


int ModulKryptograficzny::szyfruj(int dane) {
    return dane *= m_kluczSzyfrujacy;
}
