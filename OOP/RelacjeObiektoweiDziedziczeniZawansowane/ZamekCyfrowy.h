//
// Created by mf on 8/10/26.
//

#ifndef RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE_ZAMEKCYFROWY_H
#define RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE_ZAMEKCYFROWY_H
#include <cstring>
#include "Osoba.h"

class ZamekCyfrowy {
public:
    ZamekCyfrowy(const Osoba &os) {
        if (m_licznikOsob<3)
            m_osoby[m_licznikOsob++] = &os;
    }
    ZamekCyfrowy(const Osoba* osoby[3]) {
       std::memcpy(m_osoby, osoby, sizeof(m_osoby));
        for (int i = 0; i < 3; i++) {
            if (m_osoby[i]!=nullptr)
                m_licznikOsob++;
        }
    }
    ZamekCyfrowy(){}

    bool weryfikuj(Osoba &os);
    void zmianaOsobyUprawnionej(Osoba &os);
    void usuniecieOsoby(Osoba &os);
private:
    const Osoba *m_osoby[3]= {nullptr, nullptr, nullptr};
    int m_licznikOsob = 0;
    bool czyPusta()const;
};


#endif //RELACJEOBIEKTOWEIDZIEDZICZENIZAWANSOWANE_ZAMEKCYFROWY_H
