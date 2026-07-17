#ifndef COMMON_H
#define COMMON_H

#include <iostream>

// Definicja wartości NaN (Not a Number) jako flagi błędu, zgodnie z instrukcją
const int NaN = -2147483648;

void wypiszTablice(int* tab, int size);
bool porownajTablice(int* tab1, int* tab2, int size);

#endif