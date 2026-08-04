#include <iostream>
#include <cstdlib>
#include <random>
#include "modul.h"
using namespace std;


//#define ZADANIE1
//#define ZADANIE2
#define ZADANIE3
#ifdef ZADANIE1
constexpr int ROZMIAR = 1000;

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
    char* bufor [ROZMIAR];
    Stany atualyStan;
    bool dziala;
    KodBledu blad;
    int iloscArgumentow;
};

using wskNaStan = void (*) (DaneSterujace&);
//funkcje Stanow
void StanCzekaniaNaDane (DaneSterujace& stan);
void StanSprawdzDane (DaneSterujace& stan);
void StanWypisz (DaneSterujace& stan);
void StanZgloscBlad(DaneSterujace& stan);
void Reset (DaneSterujace& stan);
//funkcje pomocnicze
int ileArguemntow(DaneSterujace&stan);
void wypisz(DaneSterujace&stan);
int pasowanie(DaneSterujace&stan);


random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dist(0, 5);
/*
 * WYMYŚLIŁEM TAKIE ZASADY DZIALANIA PROGRAMU ZE PROGRAM DZIALA GDY zwracana wartosc
 * PRZY MNOZENIU ARGV * LICZBE 0-5 <5000
 */
int main(int argc, char  *argv[]) {


    DaneSterujace sterowanie;
    sterowanie.atualyStan = Stany::CzekamNaDane;
    sterowanie.dziala = true;
    sterowanie.iloscArgumentow = argc;

    if (argc>1) {
        for (int i =0; i < argc ;i++) {
            sterowanie.bufor[i] = argv[i];
        }
    }

    wskNaStan dane [] = {
        StanCzekaniaNaDane,
        StanSprawdzDane,
        StanWypisz,
        StanZgloscBlad,
        Reset
    };

    // z racji na zalozenia zadania - dane zganriam z argumentow main - czyli to dzieje sie raz tylko to jezeli obliczona wartosc bedzie wieksza niz 5000 to petla bedzie dzialacc w nieskonczosc
    // wiec rbie zabespieczenie ze 100
    while (sterowanie.dziala ) {
        dane [(int)sterowanie.atualyStan] (sterowanie);
    }
    return 0;
}

void StanCzekaniaNaDane (DaneSterujace& stan) {
    cout<<"STAN CZEKANIA NA DANE Z SYSTEMU:\n";
    stan.atualyStan = Stany::SprawdzDane;
}

void StanSprawdzDane (DaneSterujace& stan) {
    cout<<"STAN SPRWADZANIA DANYCH:\n";
    int n = pasowanie(stan);
    int x = ileArguemntow(stan);
    if ( n< 1000 && x>2)  {
        stan.atualyStan = Stany::Wypisz;
    } else if (n>1000 && x >2) {
        stan.blad = KodBledu::ZaDuzaWartosc;
        stan.atualyStan = Stany::ZglosBlad;
    } else if (x < 2) {
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
    wypisz(stan);
    stan.dziala = false;
}

void Reset (DaneSterujace& stan) {
    cout<<"STAN RESET DANYCH, KOIEC PRACY SYSTEMU\n";
    stan.blad = KodBledu::BrakBedu;
    stan.dziala = false;
}

int ileArguemntow(DaneSterujace&stan) {
    return stan.iloscArgumentow;
}

void wypisz(DaneSterujace&stan) {
    cout<<"Ilosc arguemntow: "<<stan.iloscArgumentow<<endl;
    cout<<"dane:\n";
    for (int i = 0 ; i < stan.iloscArgumentow ; i++) {
        cout<<i<<": "<<stan.bufor[i]<<"\n";
    }
    cout<<"Koniec pracy programu\n";
}

int pasowanie(DaneSterujace&stan) {
    int n  = 0;
    for (int i = 1; i < stan.iloscArgumentow; i++) {
        n += atoi(stan.bufor[i]);
    }
    return n * dist(gen) ;
}






#else
#ifdef ZADANIE2
constexpr int NUM_ROWS = 3, NUM_COLS = 3;



void wypelnij(double (*tab)[NUM_COLS],int rozmiar);
void analizujDane(double (&tab)[NUM_ROWS][NUM_COLS],bool zeruj = false) ;
void analizujDane(double (*tab) [NUM_COLS],const  int rows, bool zeruj = false);
void wypisz (double (*tab)[NUM_COLS], const int rozmiar);



int main() {
    double tab2D[NUM_ROWS][NUM_COLS];
    wypelnij(tab2D, NUM_ROWS);
    wypisz(tab2D, NUM_ROWS);
    cout<<"Wywoalnie funkcji przekazyujacej tablice przez refrencje z arguemtnem domylsnym\n";
    analizujDane(tab2D);
    wypisz(tab2D, NUM_ROWS);
    cout<<"Wywoalnie funkcji przekazyujacej tablice przez wwskaznik z arguemtnem domylsnym\n";
    analizujDane(tab2D, NUM_ROWS);
    wypisz(tab2D, NUM_ROWS);
    cout<<"Wywoalnie funkcji przekazyujacej tablice przez refrencje z naszym arugmentem \n";
    analizujDane(tab2D,true);
    wypisz(tab2D, NUM_ROWS);
    cout<<"Wywoalnie funkcji przekazyujacej tablice przez wwskaznik z arguemtnem domylsnym\n";
    analizujDane(tab2D, NUM_ROWS,false);
    wypisz(tab2D, NUM_ROWS);


}


void wypelnij(double (*tab)[NUM_COLS],int rozmiar) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(0, 1000.0);

    for (int i =0 ; i < rozmiar; i++) {
        for (int j = 0 ; j < NUM_COLS; j++) {
            tab[i][j] = dist(gen);
        }
    }
}


void analizujDane(double (&tab)[NUM_ROWS][NUM_COLS],bool zeruj) {
    if (zeruj) {
        for (int i =0; i < NUM_ROWS; i++) {
            for (int j = 0; j < NUM_COLS; j++) {
                tab[i][j] *=0.0;
            }
        }
    }else {
        for (int i =0; i < NUM_ROWS; i++) {
            for (int j = 0; j < NUM_COLS; j++) {
                tab[i][j] +=10.0;
            }
        }
    }

};

void analizujDane(double (*tab) [NUM_COLS],const  int rows, bool zeruj) {
    if (zeruj) {
        for (int i =0; i < rows; i++) {
            for (int j = 0; j < NUM_COLS; j++) {
                tab[i][j] *= 0;
            }
        }
    }
    else {
        for (int i =0; i < rows; i++) {
            for (int j = 0; j < NUM_COLS; j++) {
                tab[i][j] +=10.0;
            }
        }
    }
}

void wypisz (double (*tab)[NUM_COLS], const int rozmiar) {
    for (int i =0; i < rozmiar; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }
}
#else
#ifdef ZADANIE3
int main () {

    modul::generatorLiczb();
    modul::generatorLiczb();
    modul::generatorLiczb();
}

#endif

#endif
#endif
