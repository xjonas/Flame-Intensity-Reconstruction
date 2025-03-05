#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#include "Variablen.h"
#include "FunktionsWert.h"
using namespace std;

//Steigung des �bergebenen Polynoms an Stelle x wird berechnet und zur�ckgegeben
double Differentiation(long double* Polynom, double x) {

    double dy = FunktionsWert(Polynom, (x + h)) - FunktionsWert(Polynom, (x - h));
    ZentralerDifferenzenquotient = dy / (2 * h);

    return ZentralerDifferenzenquotient;
}


