#include <iostream>
#include "Operator.h"
#include "Dron.h"
#include "ModulKryptograficzny.h"
#include "Eskadra.h"

int main() {

    {
        Dron dron(1,2);
        dron.wyslijRaport(123213);
    }

    {
        Dron dron(1,2);
        Dron dron2(2,2);
        Operator o1;
        Operator o2;
        dron.przypiszOperatora(o1);
        dron.przypiszOperatora(o2);
        Dron *dron3= new Dron(1,1);
    }


    return 0;
}