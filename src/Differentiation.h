#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#include "Variablen.h"
#include "FunktionsWert.h"
using namespace std;

//Steigung des übergebenen Polynoms an Stelle x wird berechnet und zurückgegeben
double Differentiation(long double* Polynom, double x) {

    double dy = FunktionsWert(Polynom, (x + h)) - FunktionsWert(Polynom, (x - h));
    ZentralerDifferenzenquotient = dy / (2 * h);

    return ZentralerDifferenzenquotient;
}


