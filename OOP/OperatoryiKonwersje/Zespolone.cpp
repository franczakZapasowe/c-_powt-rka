//
// Created by mf on 8/11/26.
//

#include "Zespolone.h"

#include <iostream>
#include <ostream>

#include "Wektor.h"
Zespolone Zespolone::fromVector(Wektor &w) {
        return Zespolone(w.getX(),w.getY());

}

void Zespolone::ZwrocCala() {
        std::cout<<"Rzeczywsita: "<<m_rzeczywista<<std::endl;
        std::cout<<"Urojona: "<<m_urojona<<std::endl;
}
