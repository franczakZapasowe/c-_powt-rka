#include <iostream>
#include "Wektor.h"
#include "Zespolone.h"

int main() {


    {
        std::cout<<"Zespolona formalna konwersja powinna byc rzeczywista 10 urojona 0\n";
        Zespolone konwersjaFomalna(10);
        std::cout<<"rzeczywsita: "<<konwersjaFomalna.getRzeczywista();
        std::cout<<"\nurojona: "<<konwersjaFomalna.getUrojona();
    }
    {
        Zespolone zespolona3 (10,2);
        double ZespolonaToDouble = static_cast<double>(zespolona3);
        std::cout<<"\nPowinno byc 10: "<<ZespolonaToDouble<<"\n";
    }

    {
        Wektor wektor;
        Zespolone zespolona(100,100);
        std::cout<<"Przed konwersja nieformalna z klasa Wetkro:\n";
        std::cout<<"rzeczywsita: "<<zespolona.getRzeczywista();
        std::cout<<"\nurojona: "<<zespolona.getUrojona();
        std::cout<<"\nPo oczekiwana wynik to 0 , 0\n";
        zespolona = zespolona.fromVector(wektor);
        std::cout<<"rzeczywsita: "<<zespolona.getRzeczywista();
        std::cout<<"\nurojona: "<<zespolona.getUrojona();
    }

    {
        std::cout<<"\n\nopreratoror + oczekiwany wynik 20 20 :\n";
        Zespolone A (10,10);
        Zespolone B (10,10);
        Zespolone C = A+B;
        C.ZwrocCala();
        std::cout<<"opreratoror - oczekiwany wynik 10 10 :\n";
        Zespolone D = C - A;
        D.ZwrocCala();
        Zespolone E = A*B;
        std::cout<<"opreratoror * oczekiwany wynik 0 200 :\n";
        E.ZwrocCala();
        Zespolone F = A/B;
        std::cout<<"opreratoror / oczekiwany wynik 1 0 :\n";
        F.ZwrocCala();
        std::cout<<"F = -A:\n";
        F = -A;
        F.ZwrocCala();

    }

    return 0;
}