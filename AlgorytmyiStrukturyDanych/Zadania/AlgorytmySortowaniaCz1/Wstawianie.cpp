#include "Wstawianie.h"
#include "Common.h"

// UWAGA - w tym pliku umieść swoją implementację funkcji sortującej
void sortowanieWstawianie(int* tab, int size) {
    // TU WPISZ SWÓJ KOD
    for (int i = 1; i <size; i++) {
        int v = tab[i];
        int lewy = 0, prawy = i - 1;
        while (lewy <= prawy) {
            int srodek = (lewy + prawy) / 2;
            if (v < tab[srodek])
                prawy = srodek - 1;
            else lewy = srodek+1;
        }
        for (int j = i - 1; j >= lewy; j--) {
            tab[j+1] = tab[j];
        }
        tab[lewy] = v;
    }
}

void sortowanieWstawianieTest() {
    std::cout << "--- TESTY: Sortowanie przez Wstawianie ---\n";

    int tab1[] = {12, 11, 13, 5, 6};
    int odp1[] = {5, 6, 11, 12, 13};

    int tab2[] = {-5, -10, 0, 3, -1}; // Liczby ujemne
    int odp2[] = {-10, -5, -1, 0, 3};

    int tab3[] = {7, 7, 7, 7}; // Same duplikaty
    int odp3[] = {7, 7, 7, 7};

    bool ok = true;

    sortowanieWstawianie(tab1, 5);
    if(!porownajTablice(tab1, odp1, 5)) ok = false;

    sortowanieWstawianie(tab2, 5);
    if(!porownajTablice(tab2, odp2, 5)) ok = false;

    sortowanieWstawianie(tab3, 4);
    if(!porownajTablice(tab3, odp3, 4)) ok = false;

    // Wynikiem każdego testu ma być wartość OK[cite: 1]
    if (ok) std::cout << "Wynik: OK\n\n";
    else std::cout << "Wynik: BLAD\n\n";
}
