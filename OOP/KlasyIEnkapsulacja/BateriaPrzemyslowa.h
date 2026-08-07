//
// Created by mf on 8/7/26.
//

#ifndef KLASYIENKAPSULACJA_BATERIAPRZEMYSLOWA_H
#define KLASYIENKAPSULACJA_BATERIAPRZEMYSLOWA_H

class BateriaPrzemyslowa {
private:
    int m_poziomNaldaowania;
    int m_temperatura;
    int m_limitNapiecia;


public:
    int getPoziomNaldaowania()const{return m_poziomNaldaowania;};
    int getTemperatura()const {return m_temperatura;};
    int getLimitNapiecia()const {return m_limitNapiecia;};

    void setPoziomNaladowania(int p);
    void setTemperatura(int t);
    void setLimitNapiecia(int l);
    void setterZbiorczy(int,int,int);

    int skorygowanyPoziomNaladowania(int x, int y);
    int skorygowanyPoziomNaladowania(int );

};

#endif //KLASYIENKAPSULACJA_BATERIAPRZEMYSLOWA_H
