#include <iostream>
#include <cstdlib>
#include <random>
using namespace std;

constexpr int ROZMIAR = 1000;

enum class Stany {
    CzekamNaDane = 0,
    PobieranieDanych = 1,
    SprawdzDane = 2,
    Wypisz = 3,
    ZglosBlad = 4,
    Reset = 5
};

struct DaneSterujace {
    char bufor [ROZMIAR];
    Stany atualyStan;
    bool dziala;
};

using wskNaStan = void (*) (DaneSterujace&);
//funkcje Stanow
void StanCzekaniaNaDane (DaneSterujace& stan);
void StanPobieranieDanych (DaneSterujace& stan);
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
        StanPobieranieDanych,
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
    stan.atualyStan = Stany::PobieranieDanych;
}

void StanPobieranieDanych (DaneSterujace& stan) {

    // int n = pobierzDane();
    // if (n>0)
    stan.atualyStan = Stany::SprawdzDane;
}

void StanSprawdzDane (DaneSterujace& stan) {
    if (true) {
        stan.atualyStan = Stany::Wypisz;
    }else {
        stan.atualyStan = Stany::ZglosBlad;
    }

}
void StanZgloscBlad(DaneSterujace& stan) {

    stan.atualyStan= Stany::Reset;
}


void StanWypisz (DaneSterujace& stan) {


    stan.dziala = false;
}

void Reset (DaneSterujace& stan) {

}

int pobierzDane() {
}
