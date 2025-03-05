#pragma once
#include <iostream>
#include <cmath>
using namespace std;


//Allgemein
string control; // Y/N f�r Kontrollen


//Einlesen
double** ImportMatrix; //Importmatrix deklariert
int ZeilenanzahlImportMatrix;
int SpaltenanzahlImportMatrix;
string filenameIn; //Flammentyp
string filepathIn; //Dateipfad

//Schreiben
string filepathOut;


//Mittelung
double** MittelungMatrix;
int Symmetrieachse;
int ZeilenanzahlMittelungMatrix;
int SpaltenanzahlMittelungMatrix;

//Gl�ttung
double** GlaettungMatrix;
int ZeilenanzahlGlaettungMatrix;
int SpaltenanzahlGlaettungMatrix;
int AnzahlNachbarElemente = 5; //Intervallbreite ist dann 2*e +1		-> GLT, f�r ParameterUntersuchung (IntervallBreite wird angegeben)
int IntervallBreite; //													
double SummeIntervallElemente;
double IntervallMittelwert;


//Polynomfit
long double** PolynomKoeffizientenMatrix; //Polynome
const int Polynomgrad = 5; //											->PG, f�r ParameterUntersuchung
int ZeilenPolynomfit;
long double* TemporaereKoeffizientenMatrixEinfach; //a
double* xWerte;
double* yWerte;
int ZeilenzahlPolynomKoeffizientenMatrix;
int SpaltenzahlPolynomKoeffizientenMatrix;


//Differentiation als Lokale Steigung
const double h = pow(10, -5); //Potenz Ausprobieren						->DIFF, f�r ParameterUntersuchung (nur pos. Potenz wird angegeben)
// double x -> "y"- Koordiante
double ZentralerDifferenzenquotient; 


//Integration
const double AnzahlTeilintervalle = pow(10,3); //Potenz Ausprobieren	->INTG, f�r ParameterUntersuchung
double TeilintervallBreite;
double** IntegrationMatrix; //matrix mit Werten f�rs Plotten
int ZeilenzahlIntegrationMatrix; 
int SpaltenzahlIntegrationMatrix; 
int R; //Obere Grenze R ->Symmetrieachse. Muss noch in Code geschrieben werden

//Plotten/Fertigstellung
double** Plotmatrix;
int PlotElemente;

//Spiegeln
double** SpiegelMatrix;
int ZeilenanzahlSpiegelMatrix;
int SpaltenanzahlSpiegelMatrix;


