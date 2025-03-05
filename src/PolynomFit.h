#pragma once

#include<iostream>
#include<iomanip>
#include<cmath>
#include "Variablen.h"
#include "Create_Delete_Matrix.h"
using namespace std;


//ZeilenPolynomfit = Spalten Glaettungsmatrix
void PolynomFit(double** Startmatrix, int ZeilenPolynomfit, /*int PolynomgradPolynomfit ,*/ int ZeilenzahlStartmatrix, long double* MatrixKoeffizientenPolynomfit)
{
    cout.precision(15);  //set precision/decimals -> auf 15 decimals genau
    cout.setf(ios::fixed);

    int n = Polynomgrad;
    int N = ZeilenPolynomfit;

    //Arrays für Wertepaare
    xWerte = new double[ZeilenPolynomfit];
    yWerte = new double[ZeilenPolynomfit];

    //Schreiben der Wertepaare, also es werden die gegebenen x und y Werte eingelesen, wobei die x-Werte hierbei natürliche Zahlen sind
    for (int i = 0;i < ZeilenPolynomfit;i++)
        xWerte[i] = i;
    for (int i = 0;i < ZeilenPolynomfit;i++)
        yWerte[i] = Startmatrix[ZeilenzahlStartmatrix][i];

    long double X[2 * Polynomgrad + 1]; //Array that will store the values of sigma(xi),sigma(xi^2),sigma(xi^3)....sigma(xi^2n), also Summen

    for (int i = 0;i < 2 * n + 1;i++)
    {
        X[i] = 0;
        for (int j = 0;j < N;j++)
            X[i] = X[i] + pow(xWerte[j], i);  //consecutive positions of the array will store N,sigma(xi),sigma(xi^2),sigma(xi^3)....sigma(xi^2n)
    }

    long double B[Polynomgrad + 1][Polynomgrad + 2]; //B is the Normal matrix(erweitert) that will store the equations
    for (int i = 0;i <= n;i++)
        for (int j = 0;j <= n;j++)
            B[i][j] = X[i + j]; //Build the Normal matrix by storing the corresponding coefficients at the right positions except the last column of the matrix


    long double Y[Polynomgrad + 1];  //Array to store the values of sigma(yi),sigma(xi*yi),sigma(xi^2*yi)...sigma(xi^n*yi)
    for (int i = 0;i < n + 1;i++)
    {
        Y[i] = 0;
        for (int j = 0;j < N;j++)
            Y[i] = Y[i] + pow(xWerte[j], i) * yWerte[j];  //consecutive positions will store sigma(yi),sigma(xi*yi),sigma(xi^2*yi)...sigma(xi^n*yi)
    }

    for (int i = 0;i <= n;i++)
        B[i][n + 1] = Y[i];  //load the values of Y as the last column of B(Normal Matrix but augmented)

    n = n + 1; //n is made n+1 because the Gaussian Elimination part below was for n equations, but here n is the degree of polynomial and for n degree we get n+1 equations

    //Gauss
    for (int i = 0;i < n;i++) //Gaussian Elimination starts to solve the set of linear equations (Pivotisation) -> Zeilen werden getauscht
        for (int k = i + 1;k < n;k++) //fängt bei der Zeile darunter an
            if (B[i][i] < B[k][i]) //Zeilen werden getauscht, sodass Pivotelement das größte ist
                for (int j = 0;j <= n;j++)
                {
                    long double temp = B[i][j];
                    B[i][j] = B[k][j];
                    B[k][j] = temp;
                }

    for (int i = 0;i < n - 1;i++)  //loop to perform the gauss elimination, n-1 weil erweiterte matrix mit "Lösung" in letzter Spalte
        for (int k = i + 1;k < n;k++)
        {
            long double t = B[k][i] / B[i][i];
            for (int j = 0;j <= n;j++)
                B[k][j] = B[k][j] - t * B[i][j];    //make the elements below the pivot elements equal to zero or elimnate the variables
        }


    for (int i = n - 1;i >= 0;i--)   //back-substitution ,also bei der letzten Zeile anfangen
    {
        MatrixKoeffizientenPolynomfit[i] = B[i][n];    //make the variable to be calculated equal to the rhs of the last equation -
        for (int j = 0;j < n;j++)
            if (j != i)   //then subtract all the lhs values except the coefficient of the variable whose value is being calculated, jeweils die diagonalwerte werden also nicht abgezogen
                MatrixKoeffizientenPolynomfit[i] = MatrixKoeffizientenPolynomfit[i] - B[i][j] * MatrixKoeffizientenPolynomfit[j]; //[j] ist also der Wert eine Zeile in der Matrix drunter den wir davor ausgerechnet haben
        MatrixKoeffizientenPolynomfit[i] = MatrixKoeffizientenPolynomfit[i] / B[i][i];    //now finally divide the rhs by the coefficient of the variable to be calculated, den haben wir durch die x schleife stehen gelassen
    }

    delete[] xWerte;
    delete[] yWerte;

}