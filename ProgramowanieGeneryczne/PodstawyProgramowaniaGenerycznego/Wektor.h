//
// Created by mf on 8/15/26.
//

#ifndef ZADANIE0_WEKTOR_H
#define ZADANIE0_WEKTOR_H
#include <iostream>
#include <ostream>
template<typename T>
class Wektor {
    T x;
    T y;
public:
    Wektor(T x, T y);
    void setX(T x);
    void setY(T y);
    void setWektor(T x, T y);
    T getX()const;
    T getY()const;
    void wypisz();
};
template<typename T>
Wektor<T>::Wektor(T x, T y) {
    this->x = x;
    this->y = y;
}

template<typename T>
void Wektor<T>::setX(T x) {
    this->x = x;
}

template<typename T>
void Wektor<T>::setY(T y) {
    this->y = y;
}

template<typename T>
void Wektor<T>::setWektor(T x, T y) {
    setX(x);
    setY(y);
}

template<typename T>
T Wektor<T>::getX() const {
    return x;
}

template<typename T>
T Wektor<T>::getY() const {
    return y;
}

template<typename T>
void Wektor<T>::wypisz() {
    std::cout<<"X: "<<x<<" Y: "<<y<<std::endl;
}

#endif //ZADANIE0_WEKTOR_H
