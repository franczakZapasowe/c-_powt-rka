//
// Created by mf on 8/8/26.
//

#ifndef ZADANIE_DRON_H
#define ZADANIE_DRON_H


class Dron {
    const int m_nrIdentyfikacyjny;
    static int ileDronow;
    int m_zdjecie;
    mutable int m_licznikOdczytow;
public:
    Dron(int nrIdentyfikacyjny):m_nrIdentyfikacyjny(nrIdentyfikacyjny) { ileDronow++;}
    Dron(Dron &dron) = delete;
    Dron(Dron &&dron) = delete;
    Dron &operator=(Dron &dron) = delete;
    Dron &operator=(Dron &&dron) = delete;
    ~Dron() {ileDronow--;}
    int getZdjecie()const;
    int getNrIdentyfikacyjny()const;
    int getLicznikOdczytow()const {return m_licznikOdczytow;}
    static int getIleDronow() {
        return ileDronow;
    }
};


#endif //ZADANIE_DRON_H
