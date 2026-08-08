//
// Created by mf on 8/8/26.
//

#include "dron.h"

int Dron::ileDronow = 0;

int Dron::getZdjecie()const {
    m_licznikOdczytow++;
    return m_zdjecie;
}
int Dron::getNrIdentyfikacyjny()const {
    m_licznikOdczytow++;
    return m_nrIdentyfikacyjny;
}