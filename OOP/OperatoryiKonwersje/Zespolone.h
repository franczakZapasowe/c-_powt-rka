//
// Created by mf on 8/11/26.
//

#ifndef OPERATORYIKONWERSJE_ZESPOLONE_H
#define OPERATORYIKONWERSJE_ZESPOLONE_H
#include <stdexcept>
class Wektor;

class Zespolone {
    double m_rzeczywista;
    double m_urojona;
public:
    Zespolone(double rzeczywsita, double urojona):m_rzeczywista(rzeczywsita), m_urojona(urojona) {}
    double getRzeczywista()const {return m_rzeczywista;}
    double getUrojona()const {return m_urojona;}
    void setRzeczywista(double x) {m_rzeczywista = x;}
    void setUrojona(double x) {m_urojona = x;}
    // konwersja formalna
    Zespolone (double x ):m_rzeczywista(x),m_urojona(0){}
    operator double() const {return m_rzeczywista;}
    void ZwrocCala ();
    static Zespolone fromVector(Wektor &w);

    Zespolone operator+(const Zespolone &w){
        double rzeczywsita = (this->m_rzeczywista + w.m_rzeczywista);
        double urojona = (this->m_urojona + w.m_urojona);
        return Zespolone (rzeczywsita, urojona);
    }

    Zespolone operator-(const Zespolone &w) {
        double rzeczywsita = (this->m_rzeczywista - w.m_rzeczywista);
        double urojona = (this->m_urojona - w.m_urojona);
        return Zespolone (rzeczywsita, urojona);
    }

    Zespolone operator*(const Zespolone &w) {
        double rzeczywsita = (this->m_rzeczywista * w.m_rzeczywista) - (this->m_urojona * w.m_urojona);
        double urojona  = (this->m_rzeczywista *w.m_urojona) + (this->m_urojona *w.m_urojona);
        return Zespolone (rzeczywsita, urojona);
    }

    Zespolone operator/(const Zespolone &w) {
        double mianownik = (w.m_rzeczywista*w.m_urojona) + (w.m_urojona * w.m_urojona);
        if (mianownik < 1e-9 && mianownik > -1e-9) {
            throw std::invalid_argument("Blad: Proba dzielenia liczby zespolonej przez ZERO!");
        }
        double rzeczywsita = ((this->m_rzeczywista * w.m_rzeczywista) + (this->m_urojona * w.m_urojona))/mianownik;
        double urojona = ((this->m_urojona* w.m_rzeczywista) - (this->m_rzeczywista*w.m_urojona))/mianownik;
        return Zespolone (rzeczywsita, urojona);
    }


};


#endif //OPERATORYIKONWERSJE_ZESPOLONE_H
