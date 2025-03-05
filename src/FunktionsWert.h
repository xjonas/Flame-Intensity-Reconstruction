#pragma once
#include <iostream>
#include <cmath>
#include "Variablen.h"


//einzelnen Koeffizienten müssen mit x-Wert multipliziert und zusammengesetzt werden. Summe enspricht dann dem Funktionswert an Stelle x = f(x)
long double FunktionsWert(long double* Polynom, double x)
{
    long double sum = 0;

    for (int i = 0; i <= Polynomgrad; i++) {
        sum += Polynom[i] * pow(x, i);
    }

    return sum;
}
