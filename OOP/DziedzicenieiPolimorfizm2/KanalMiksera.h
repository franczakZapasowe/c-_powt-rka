//
// Created by mf on 8/10/26.
//

#ifndef DZIEDZICENIEIPOLIMORFIZM2_KANALMIKSERA_H
#define DZIEDZICENIEIPOLIMORFIZM2_KANALMIKSERA_H
#include <cstring>
#include <iostream>
#include <ostream>


class KanalMiksera {
protected:
    char m_nazwa[30];
    KanalMiksera(const char *nazwa) {
        std::strncpy(m_nazwa, nazwa,29);
        m_nazwa[29] = '\0';
    }

public:
    virtual void przetwarzaj() = 0;
    virtual ~KanalMiksera() {std::cout<<"Destruktor KanalMiksera"<<std::endl;}
};


#endif //DZIEDZICENIEIPOLIMORFIZM2_KANALMIKSERA_H
