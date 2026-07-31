#include <iostream>
#include <cstdlib>
#include <random>
using namespace std;

constexpr int ROZMIAR = 1000;

enum class Stany {
    CzekamNaDane = 0,
    SprawdzDane = 1,
    Wypisz = 2,
    ZglosBlad = 3,
    Reset = 4
};

enum class KodBledu {
    ZaMaloArgumentow,ZaDuzaWartosc,ObaBledy
};

struct DaneSterujace {
    char bufor [ROZMIAR];
    Stany atualyStan;
    bool dziala;
    KodBledu blad;
};

using wskNaStan = void (*) (DaneSterujace&);
//funkcje Stanow
void StanCzekaniaNaDane (DaneSterujace& stan);
void StanSprawdzDane (DaneSterujace& stan);
void StanWypisz (DaneSterujace& stan);
void StanZgloscBlad(DaneSterujace& stan);
void Reset (DaneSterujace& stan);
//funkcje pomocnicze
int pobierzDane();



int main(int argc, char  *argv[]) {

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 10);

    cout<<"Podano: "<<argc<<" parametrow\n";
    for (int i =0; i<argc; i++) cout<<i<<": "<<argv[i]<<endl;
    cout<<"n:\n";
    if (argc>1) {
        int n = atoi(argv[1]);
        cout<<n*dist(gen)<<endl;
    }

    DaneSterujace sterowanie;
    sterowanie.atualyStan = Stany::CzekamNaDane;
    sterowanie.dziala = true;

    wskNaStan dane [] = {
        StanCzekaniaNaDane,
        StanSprawdzDane,
        StanWypisz,
        StanZgloscBlad,
        Reset
    };

    while (sterowanie.dziala) {
        dane [(int)sterowanie.atualyStan] (sterowanie);

    }

    return 0;
}



void StanCzekaniaNaDane (DaneSterujace& stan) {
    cout<<"Czkeam na dane z systemu:\n";
    stan.atualyStan = Stany::SprawdzDane;
}

void StanSprawdzDane (DaneSterujace& stan) {
    if (true) {
        stan.atualyStan = Stany::Wypisz;
    }else {
        if (n < 1 && x > 1000) {
            stan.blad = KodBledu::ObaBledy;
            stan.atualyStan = Stany::ZglosBlad;
        }else if (n<1 && x<1000) {
            stan.blad = KodBledu::ZaMaloArgumentow;
            stan.atualyStan = Stany::ZglosBlad;
        }
        else if (n>1 && x>1000) {
            stan.blad = KodBledu::ZaDuzaWartosc;
            stan.atualyStan = Stany::ZglosBlad;
        }
    }
}
void StanZgloscBlad(DaneSterujace& stan) {
    cout<<"Blad\n";
    switch (stan.blad) {
        case KodBledu::ZaMaloArgumentow:
            cout<<"Podano za malo arguemtnow\n";
            break;
        case KodBledu::ZaDuzaWartosc:
            cout<<"Z obliczen wyszla za duza wartosc\n";
            break;
        case KodBledu::ObaBledy:
            cout<<"Oba bledy\n";
            break;
    }
    stan.atualyStan= Stany::Reset;
}

void StanWypisz (DaneSterujace& stan) {


    stan.dziala = false;
}

void Reset (DaneSterujace& stan) {

}

int pobierzDane() {
}
