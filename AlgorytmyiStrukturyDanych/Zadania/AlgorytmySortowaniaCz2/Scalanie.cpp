#include "Scalanie.h"
#include "Common.h"

// Funkcja "scal" - łączy dwie posortowane połówki w jedną całość
void scal(int* tab, int lewy, int srodek, int prawy) {
    // TU WPISZ SWÓJ KOD
    // Wskazówka: Będziesz potrzebował dynamicznej tablicy pomocniczej!
    int *temp = new int [prawy-lewy +1];
    int i = lewy , j = srodek +1 , k = 0;
    while (i <= srodek && j<=prawy) {
        if (tab[i]<tab[j]) {
            temp[k++] = tab[i++];
        }else {
            temp[k++] = tab[j++];
        }
    }
    while (i <= srodek) {
        temp[k++] = tab[i++];
    }
    while (j <= prawy) {
        temp[k++] = tab[j++];
    }

    k = 0;
    for (int iter = lewy ; iter <=prawy  ; iter++) {
        tab[iter] = temp[k++];
    }

    delete [] temp;

}

// Funkcja rekurencyjna dzieląca tablicę na pół
void sortowanieScalanieRek(int* tab, int lewy, int prawy) {
    // TU WPISZ SWÓJ KOD
    if (lewy >= prawy) return;
    int srodek = (lewy + prawy) / 2;
    sortowanieScalanieRek(tab, lewy,srodek);
    sortowanieScalanieRek(tab, srodek+1,prawy);
    scal(tab,lewy,srodek,prawy);
}

// Główna funkcja startowa
void sortowanieScalanie(int* tab, int size) {
    if (size > 1) {
        sortowanieScalanieRek(tab, 0, size - 1);
    }
}

void sortowanieScalanieTest() {
    std::cout << "--- TESTY: Sortowanie przez Scalanie ---\n";

    int tab1[] = {12, 11, 13, 5, 6, 7};
    int odp1[] = {5, 6, 7, 11, 12, 13};

    int tab2[] = {-5, 10, 0, -3, 8}; 
    int odp2[] = {-5, -3, 0, 8, 10};

    int tab3[] = {4, 4, 4, 1, 4}; 
    int odp3[] = {1, 4, 4, 4, 4};

    bool ok = true;

    sortowanieScalanie(tab1, 6);
    if(!porownajTablice(tab1, odp1, 6)) ok = false;

    sortowanieScalanie(tab2, 5);
    if(!porownajTablice(tab2, odp2, 5)) ok = false;

    sortowanieScalanie(tab3, 5);
    if(!porownajTablice(tab3, odp3, 5)) ok = false;

    if (ok) std::cout << "Wynik: OK\n\n";
    else std::cout << "Wynik: BLAD\n\n";
}