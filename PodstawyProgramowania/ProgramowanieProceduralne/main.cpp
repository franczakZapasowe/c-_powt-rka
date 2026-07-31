#include <iostream>
#include <cstdlib>
#include <random>
using namespace std;

constexpr int ROZMIAR = 1000;
int iloscElementowGlobal = 0;
int nGlobal = 0;
int licznikWywolanPetli;

enum class Stany {
    CzekamNaDane = 0,
    SprawdzDane = 1,
    Wypisz = 2,
    ZglosBlad = 3,
    Reset = 4
};

enum class KodBledu {
    ZaMaloArgumentow,ZaDuzaWartosc,BrakBedu
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
void wypisz();

/*
 * WYMYŚLIŁEM TAKIE ZASADY DZIALANIA PROGRAMU ZE PROGRAM DZIALA GDY ARGC > 1 I WYNIK
 * PRZY MNOZENIU ARGV * LICZBE 0-5 <5000
 */
int main(int argc, char  *argv[]) {

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 5);

    iloscElementowGlobal = argc;
    cout<<"Podano: "<<argc<<" parametrow\n";
    for (int i =0; i<argc; i++) cout<<i<<": "<<argv[i]<<endl;
    cout<<"n:\n";
    int suma = 0;
    if (argc>1) {
        for (int i =0; i<argc ;i++) {
            nGlobal+= atoi(argv[i]);
        }
    }
    nGlobal *= dist(gen);

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

    // z racji na zalozenia zadania - dane zganriam z argumentow main - czyli to dzieje sie raz tylko to jezeli obliczona wartosc bedzie wieksza niz 5000 to petla bedzie dzialacc w nieskonczosc
    // wiec rbie zabespieczenie ze 100
    while (sterowanie.dziala && licznikWywolanPetli<100) {
        dane [(int)sterowanie.atualyStan] (sterowanie);
        licznikWywolanPetli++;
    }
    return 0;
}

void StanCzekaniaNaDane (DaneSterujace& stan) {
    cout<<"STAN CZEKANIA NA DANE Z SYSTEMU:\n";
    stan.atualyStan = Stany::SprawdzDane;
}

void StanSprawdzDane (DaneSterujace& stan) {
    cout<<"STAN SPRWADZANIA DANYCH:\n";
    int n  = iloscElementowGlobal;
    int x = nGlobal;

    if (n > 1 && x < 1000)  {
        stan.atualyStan = Stany::Wypisz;
    } else if (n >1 && x > 1000) {
        stan.blad = KodBledu::ZaDuzaWartosc;
        stan.atualyStan = Stany::ZglosBlad;
    }
    else if (n < 1 && x < 1000) {
        stan.blad = KodBledu::ZaMaloArgumentow;
        stan.atualyStan = Stany::ZglosBlad;
    }
}

void StanZgloscBlad(DaneSterujace& stan) {
    cout<<"STAN SPRAWDZANIA BLEDOW:\n";
    cout<<"Blad\n";
    switch (stan.blad) {
        case KodBledu::ZaMaloArgumentow:
            cout<<"Podano za malo arguemtnow\n";
            break;
        case KodBledu::ZaDuzaWartosc:
            cout<<"Z obliczen wyszla za duza wartosc(n>5000)\n";
            break;
    }
    stan.atualyStan = Stany::Reset;
}

void StanWypisz (DaneSterujace& stan) {
    cout<<"STAN WYPISYWANIA DANYCH:\n";
    wypisz();
    stan.dziala = false;
}

void Reset (DaneSterujace& stan) {
    cout<<"STAN RESET\n";
    stan.blad = KodBledu::BrakBedu;
    stan.atualyStan = Stany::CzekamNaDane;
}

void wypisz() {
    cout<<"Ilosc elementow podanych: "<<iloscElementowGlobal<<endl;
    cout<<"Wynik: "<<nGlobal<<endl;
}

