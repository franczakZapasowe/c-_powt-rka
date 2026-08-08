#include <iostream>
#include "dron.h"
#include "Testy.h"

int main() {
    Dron d (10);
    Testy::testDrona(&Dron::getZdjecie,d);

}