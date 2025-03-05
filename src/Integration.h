#pragma once

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "Variablen.h"
#include "FunktionsWert.h"
#include "Differentiation.h"
#include "WriteData.h"
#include "Create_Delete_Matrix.h"
#include <math.h>
using namespace std;


//Integration durch Mittelungsverfahren von den Grenzen r bis R
double Integration(long double* Polynom, double UntereGrenze, double ObereGrenze)
{
    TeilintervallBreite = (double(ObereGrenze) - double(UntereGrenze)) / double(AnzahlTeilintervalle); 
    long double sum = 0.0; //Variable zum aufsummieren

    //Berechnen des Flöcheninhalts jedes Teilintervalls/Rechtecks
    for (int i = 1; i <= AnzahlTeilintervalle; i++) //Intervall startet bei 1, da für x=r pow(q,-0.5) nicht existiert, bzw unendlich wird.
    {
        long double y = UntereGrenze - TeilintervallBreite / 2.0 + i * TeilintervallBreite;
        long double q = y*y - UntereGrenze*UntereGrenze; //q= (y^2 -r^2)
        sum += (Differentiation(Polynom,y))/(sqrt(q)) * TeilintervallBreite;
    }
    return -sum/M_PI;
}
