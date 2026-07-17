#include "Babelkowe.h"
#include "Common.h"
#include <algorithm>
// UWAGA - w tym pliku umieść swoją implementację funkcji sortującej[cite: 1]
void sortowanieBabelkowe(int* tab, int size) {
    // TU WPISZ SWÓJ KOD
    int ilosc_potrzebnych = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size - ilosc_potrzebnych; j++) {
            if (tab[j-1]>tab[j]) {
                std::swap(tab[j-1], tab[j]);
            }
        }
        ilosc_potrzebnych++;
    }
}

void sortowanieBabelkoweTest() {
    std::cout << "--- TESTY: Sortowanie Babelkowe ---\n";

    int tab1[] = {5, 2, 9, 1, 5, 6};
    int odp1[] = {1, 2, 5, 5, 6, 9};

    int tab2[] = {100, 90, 80, 70, 60}; // Odwrotnie posortowana
    int odp2[] = {60, 70, 80, 90, 100};

    int tab3[] = {1, 2, 3, 4, 5}; // Juz posortowana (test wczesnego wyjscia)
    int odp3[] = {1, 2, 3, 4, 5};

    int tab4[] = {42}; // Jeden element
    int odp4[] = {42};

    bool ok = true;

    sortowanieBabelkowe(tab1, 6);
    if(!porownajTablice(tab1, odp1, 6)) ok = false;

    sortowanieBabelkowe(tab2, 5);
    if(!porownajTablice(tab2, odp2, 5)) ok = false;

    sortowanieBabelkowe(tab3, 5);
    if(!porownajTablice(tab3, odp3, 5)) ok = false;

    sortowanieBabelkowe(tab4, 1);
    if(!porownajTablice(tab4, odp4, 1)) ok = false;

    // Zgodnie z wytycznymi, poprawny test ma wyrzucić wartość OK[cite: 1]
    if (ok) std::cout << "Wynik: OK\n\n";
    else std::cout << "Wynik: BLAD\n\n";
}