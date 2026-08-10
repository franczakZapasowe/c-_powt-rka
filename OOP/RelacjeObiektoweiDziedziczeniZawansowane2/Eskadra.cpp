//
// Created by mf on 8/11/26.
//

#include "Eskadra.h"

void Eskadra::dodajDrona(Dron &d) {
    if (m_licznikDronow<20) {
        if (m_drony[m_licznikDronow] == nullptr) {
            m_drony[m_licznikDronow++] = &d;
        }
    }
    else return;
}

void Eskadra::usunDrona(Dron &d) {
    for (int i =0; i < m_licznikDronow; i++) {
        if (m_drony[i]==&d) {
            m_drony[i] = m_drony[m_licznikDronow - 1];
            m_drony[m_licznikDronow - 1] = nullptr;
            m_licznikDronow--;
            return;
        }
    }
}
