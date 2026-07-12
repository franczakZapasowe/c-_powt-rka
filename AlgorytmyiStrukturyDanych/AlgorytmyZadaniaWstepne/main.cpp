#include <iostream>
#include <sstream>
#include <cctype>
#include <cstring>
#define ZADANIE 2
#if ZADANIE == 1
// Zaproponuj algorytm łączący dwie posortowane
// tablice w nową tablicę zawierającą posortowane
// elementy.

//Algorytm scalania z dwoma wksaznikami
void posortuj(int *tab1, int rozmiar1, int *tab2, int rozmiar2, int *tab3) {
    int i =0;
    int j = 0;
    int k = 0;

    while (i < rozmiar1 && j < rozmiar2) {
        if ( tab1[i] <= tab2[j]) {
            tab3[k++] = tab1[i++];
        }else {
            tab3[k++] = tab2[j++];
        }
    }
    while (i < rozmiar1) {
        tab3[k++] = tab1[i++];
    }
    while (j < rozmiar2) {
        tab3[k++] = tab2[j++];
    }
}

int main() {
    int tab1[]={3,5,6,8,9};
    int tab2[]={1,2,4,7,9};
    int rozmiar = (sizeof(tab1)/sizeof(int)) + (sizeof(tab2)/sizeof(int));
    int tab3 [rozmiar];

    posortuj(tab1,5,tab2,5,tab3);

    for (int i = 0; i < rozmiar; i++) {
        std::cout<<tab3[i]<<std::endl;
    }
}

#elif ZADANIE == 2

// Znaleźć k najbardziej podobnych obiektów do
//     wskazanego wzorca
//     Rozwiązanie 1: przeszukiwanie (zaproponuj algorytm
//     do rozwiązania tego problemu, gdzie „k” to liczba
//     obiektów podobnych które chcemy znaleźć, D(a,b) to
//     funkcja wyznaczająca podobieństwo między
//     dokumentem a i b)
//     Dla naszego zadania k to bedzie slowo i bedziemy przeszukiwac w ktorym slowie jest wiecej takich samych lister

void porownanie(const char *tab1, const char *tab2, const char *tab3, int rozmiar1, int rozmiar2, int rozmiar3) {
    int iloscZnakowWZdaniu1 = 0;
    int iloscZnakowWZdaniu2 = 0;

    char wzorzec [rozmiar1];
    char zdanie1 [rozmiar2];;
    char zdanie2 [rozmiar3];

    //wzorzec
    for (int i = 0; i < rozmiar1; i++) {
        wzorzec[i] = tab1[i];
    }
    for (int i = 0; i < rozmiar1; i++) {
        wzorzec[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(wzorzec[i])));
    }

    //zdanie 1
    for (int i = 0; i < rozmiar2; i++) {
        zdanie1[i] = tab2[i];
    }
    for (int i = 0; i < rozmiar2; i++) {
        zdanie1[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(zdanie1[i])));
    }

    //zdanie 2
    for (int i = 0; i < rozmiar3; i++) {
        zdanie2[i] = tab3[i];
    }
    for (int i = 0; i < rozmiar3; i++) {
        zdanie2[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(zdanie2[i])));
    }


    // porowanianie ze zdaniem 1
    for (int i = 0; i < rozmiar1-1; i++) {
        if (wzorzec[i] == ' ') {
            continue;
        }
        for (int j = 0; j < rozmiar2-1; j++) {
            if (wzorzec[i] == zdanie1[j]) {
                iloscZnakowWZdaniu1++;
                zdanie1[j] = ' ';
                break;
            }
        }
    }


    // porownanie ze zdaniem 2
    for (int i = 0; i < rozmiar1-1; i++) {
        if (wzorzec[i] == ' ') {
            continue;
        }
        for (int j = 0; j < rozmiar3-1; j++) {
            if (wzorzec[i] == zdanie2[j]) {
                iloscZnakowWZdaniu2++;
                zdanie2[j] = ' ';
                break;
            }
        }
    }

    std::cout<<"Zdanie 1 ma: "<<iloscZnakowWZdaniu1<<" takich samych liter jak zdanie wzorcowe"<<std::endl;
    std::cout<<"Zdanie 2 ma: "<<iloscZnakowWZdaniu2<<" takich samych liter jak zdanie wzorcowe"<<std::endl;
}


void porownanie2(const char **tab1, int iloscTablic, const char*wzor) {
    int ktoreZdanie = 0;
    int najbardziejPodobne = -100;

    const int rozmiarWzorca = std::strlen(wzor);
    char wzorzec [rozmiarWzorca + 1];

    for (int j = 0; j < rozmiarWzorca; j++) {
        wzorzec[j] = wzor[j];
    }
    for (int l = 0; l < rozmiarWzorca; l++) {
        wzorzec[l] = static_cast<char>(std::toupper(static_cast<unsigned char>(wzorzec[l])));
    }

    int i = 0;
    for (i = 0; i < iloscTablic; i++) {
        int iloscZnakowWZdaniu = 0;
        // rozmiar naszego zdania
        int rozmiar = std::strlen(tab1[i]);
        // zmienna do ktorej kopiujemy zdanie
        char zdanie [rozmiar + 1];

        //zdanie
        for (int j = 0; j < rozmiar; j++) {
            zdanie[j] = tab1[i][j];
        }
        for (int l = 0; l < rozmiar; l++) {
            zdanie[l] = static_cast<char>(std::toupper(static_cast<unsigned char>(zdanie[l])));
        }

        // porowanianie zdania ze zworcem
        for (int k = 0; k < rozmiarWzorca; k++) {
            if (wzorzec[k] == ' ') {
                continue;
            }
            for (int j = 0; j < rozmiar; j++) {
                if (wzorzec[k] == zdanie[j]) {
                    iloscZnakowWZdaniu++;
                    zdanie[j] = ' ';
                    break;
                }
            }
        }

        if (iloscZnakowWZdaniu >= najbardziejPodobne) {
            najbardziejPodobne = iloscZnakowWZdaniu;
            ktoreZdanie = i;
        }
    }
    std::cout<<"Najbardziej podobne jest zdanie: "<<ktoreZdanie+1<<" ilosc podbnych znakow to: "<<najbardziejPodobne<<std::endl;
}

int main() {

    const char wzor [] = "Ala ma kota";
    const char zdanie0 [] = "Lubie jesc nalesniki";
    const char zdanie1 [] = "Gram w pilke";
    const char zdanie2 [] = "Jade na rowerze";

    std::cout<<"Funkcja testowa: "<<std::endl;
    porownanie(wzor,zdanie1,zdanie2,sizeof(wzor),sizeof(zdanie1),sizeof(zdanie2));
    const char *tablica [3] = {
        zdanie0,zdanie1,zdanie2,
    };
    std::cout<<"\n\n"<<"Wynik testu:\n";
    porownanie2(tablica,3,wzor);
}

#endif
