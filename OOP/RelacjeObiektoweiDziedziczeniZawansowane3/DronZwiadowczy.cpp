//
// Created by mf on 8/11/26.
//

#include "DronZwiadowczy.h"

void DronZwiadowczy::resetSystemowy() {
    Kamera::m_stanZasilania = 0;
    Nadajnik::m_stanZasilania = 0;
}
