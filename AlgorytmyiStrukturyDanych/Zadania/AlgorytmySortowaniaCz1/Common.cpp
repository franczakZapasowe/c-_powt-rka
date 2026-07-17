#include "Common.h"

void wypiszTablice(int* tab, int size) {
    if (size <= 0) {
        std::cout << "[]\n";
        return;
    }
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << tab[i] << (i == size - 1 ? "" : ", ");
    }
    std::cout << "]\n";
}

bool porownajTablice(int* tab1, int* tab2, int size) {
    for (int i = 0; i < size; ++i) {
        if (tab1[i] != tab2[i]) return false;
    }
    return true;
}