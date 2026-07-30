#include <iostream>

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

void StanCzekaniaNaDane (DaneSterujace& stan);
void StanPobieranieDanych (DaneSterujace& stan);
void StanSprawdzDane (DaneSterujace& stan);
void StanWypisz (DaneSterujace& stan);
void StanZgloscBlad(DaneSterujace& stan);
void Reset (DaneSterujace& stan);


int main(int argc, char const *argv[]) {

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

void StanPobieranieDanych (DaneSterujace& stan) {

}

void StanZgloscBlad(DaneSterujace& stan) {

}

void StanCzekaniaNaDane (DaneSterujace& stan) {

}

void StanWypisz (DaneSterujace& stan) {

}

void StanSprawdzDane (DaneSterujace& stan) {

}