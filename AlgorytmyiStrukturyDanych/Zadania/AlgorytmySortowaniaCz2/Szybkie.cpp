#include "Szybkie.h"
#include "Common.h"
#include <iomanip>
// Funkcja "split" (często nazywana partition) - wybiera pivota i przerzuca mniejsze na lewo, większe na prawo
int split(int* tab, int lewy, int prawy) {
    // TU WPISZ SWÓJ KOD
    int pivot = tab[prawy] ;
    int i = lewy-1;
    for (int j  = lewy; j <=prawy; j++) {
        if (tab[j] < pivot) {
            i++;
            std::swap(tab[i], tab[j]);
        }
    }
    i++;
    std::swap(tab[i], tab[prawy]);

    // 1 3 13 231 12 2
    return i;// Pamiętaj o zwróceniu ostatecznego indeksu, na którym wylądował pivot!
}

// Funkcja rekurencyjna dla QuickSorta
void sortowanieSzybkieRek(int* tab, int lewy, int prawy) {
    // TU WPISZ SWÓJ KOD
    if (lewy >= prawy) return;
    int pivot  = split(tab, lewy, prawy);
    sortowanieSzybkieRek(tab,lewy,pivot-1);
    sortowanieSzybkieRek(tab,pivot+1, prawy);
}

// Główna funkcja startowa
void sortowanieSzybkie(int* tab, int size) {
    if (size > 1) {
        sortowanieSzybkieRek(tab, 0, size - 1);
    }
}

void sortowanieSzybkieTest() {
    std::cout << "--- TESTY: Sortowanie Szybkie ---\n";

    int tab1[] = {10, 7, 8, 9, 1, 5};
    int odp1[] = {1, 5, 7, 8, 9, 10};

    int tab2[] = {-2, -10, 5, 0, 3}; 
    int odp2[] = {-10, -2, 0, 3, 5};

    int tab3[] = {9, 1, 9, 1, 9}; 
    int odp3[] = {1, 1, 9, 9, 9};

    bool ok = true;

    sortowanieSzybkie(tab1, 6);
    if(!porownajTablice(tab1, odp1, 6)) ok = false;

    sortowanieSzybkie(tab2, 5);
    if(!porownajTablice(tab2, odp2, 5)) ok = false;

    sortowanieSzybkie(tab3, 5);
    if(!porownajTablice(tab3, odp3, 5)) ok = false;

    if (ok) std::cout << "Wynik: OK\n\n";
    else std::cout << "Wynik: BLAD\n\n";
}