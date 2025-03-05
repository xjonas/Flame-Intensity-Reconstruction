#pragma once
#include <iostream>
#include <cmath>
using namespace std;


//Allgemein
string control; // Y/N für Kontrollen


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

//Glättung
double** GlaettungMatrix;
int ZeilenanzahlGlaettungMatrix;
int SpaltenanzahlGlaettungMatrix;
int AnzahlNachbarElemente = 5; //Intervallbreite ist dann 2*e +1		-> GLT, für ParameterUntersuchung (IntervallBreite wird angegeben)
int IntervallBreite; //													
double SummeIntervallElemente;
double IntervallMittelwert;


//Polynomfit
long double** PolynomKoeffizientenMatrix; //Polynome
const int Polynomgrad = 5; //											->PG, für ParameterUntersuchung
int ZeilenPolynomfit;
long double* TemporaereKoeffizientenMatrixEinfach; //a
double* xWerte;
double* yWerte;
int ZeilenzahlPolynomKoeffizientenMatrix;
int SpaltenzahlPolynomKoeffizientenMatrix;


//Differentiation als Lokale Steigung
const double h = pow(10, -5); //Potenz Ausprobieren						->DIFF, für ParameterUntersuchung (nur pos. Potenz wird angegeben)
// double x -> "y"- Koordiante
double ZentralerDifferenzenquotient; 


//Integration
const double AnzahlTeilintervalle = pow(10,3); //Potenz Ausprobieren	->INTG, für ParameterUntersuchung
double TeilintervallBreite;
double** IntegrationMatrix; //matrix mit Werten fürs Plotten
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


