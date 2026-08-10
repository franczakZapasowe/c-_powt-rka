//
// Created by mf on 8/10/26.
//

#include "Operator.h"
#include "Dron.h"
void Operator::dodajDrona(Dron &d) {
    d.usunOperatora();
    usunDrona();

    m_dron = &d;
    m_dron->m_operatoor = this;
}

void Operator::usunDrona() {
    if (m_dron!=nullptr) {
        m_dron->m_operatoor = nullptr;
        m_dron = nullptr;
    }
}
