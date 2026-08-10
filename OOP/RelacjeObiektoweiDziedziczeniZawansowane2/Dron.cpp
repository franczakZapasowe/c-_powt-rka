//
// Created by mf on 8/10/26.
//

#include "Dron.h"
#include "Operator.h"
void Dron::wyslijRaport(int tajneDane) {
    m_modul.szyfruj(tajneDane);
}

void Dron::przypiszOperatora(Operator &o) {
    o.usunDrona();
    usunOperatora();

    m_operatoor = &o;
    m_operatoor->m_dron = this;
}

void Dron::usunOperatora() {
    if (m_operatoor != nullptr) {
        m_operatoor->m_dron = nullptr;
        m_operatoor = nullptr;
    }
}
