//
// Created by mf on 8/10/26.
//

#ifndef DZIEDZICENIEIPOLIMORFIZM2_KANALBEBNOW_H
#define DZIEDZICENIEIPOLIMORFIZM2_KANALBEBNOW_H
#include "KanalMiksera.h"

class KanalBebnow: public KanalMiksera {
public:
    KanalBebnow(const char*t):KanalMiksera(t){};
    void przetwarzaj() override {std::cout<<"Kompresja na bebnach\n";}
   ~KanalBebnow(){std::cout<<"Destruktor KanalBebnow"<<std::endl;}
};
#endif //DZIEDZICENIEIPOLIMORFIZM2_KANALBEBNOW_H
