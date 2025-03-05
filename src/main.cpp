#include <iostream>
#include <fstream>
#include <string>
#include "Variablen.h"
#include "Mittelung.h"
#include "Create_Delete_Matrix.h"
#include "GetData.h"
#include "WriteData.h"
#include "Glaettung.h"
#include "Differentiation.h"
#include "PolynomFit.h"
#include "IntegrationVollständig.h"
#include "Spiegeln.h"
#include "Plotten.h"
using namespace std;


int main() {

    cout << "Programm initialisiert!" << endl;

    flametype();

    fileimport();
    
    Mittelung();

    Glaetten();

    //Polynomfit:

    ZeilenzahlPolynomKoeffizientenMatrix = ZeilenanzahlGlaettungMatrix;
    SpaltenzahlPolynomKoeffizientenMatrix = Polynomgrad + 1;

    TemporaereKoeffizientenMatrixEinfach = new long double[Polynomgrad + 1]; //Eindimensionales dynamisches Feld
    PolynomKoeffizientenMatrix = CreateMatrixTypeLongDouble(ZeilenzahlPolynomKoeffizientenMatrix, SpaltenzahlPolynomKoeffizientenMatrix);

    cout << "\nPolynomFit hat begonnen!" << endl;

    //Führt den Fit für jede Zeile durch und schreibt die Koeeffizienten für das Polynom der jeweiligen
    //Zeile in eine neue Matrix.
    for (int i = 0; i < ZeilenzahlPolynomKoeffizientenMatrix; i++) {
        PolynomFit(GlaettungMatrix, SpaltenanzahlGlaettungMatrix, i, TemporaereKoeffizientenMatrixEinfach);

        for (int j = 0; j < Polynomgrad + 1; j++) {
            PolynomKoeffizientenMatrix[i][j] = TemporaereKoeffizientenMatrixEinfach[j];
        }
    }
    WriteDataArrayLongDouble("PolynomFit", PolynomKoeffizientenMatrix, ZeilenzahlPolynomKoeffizientenMatrix, SpaltenzahlPolynomKoeffizientenMatrix);
    cout << "Polynomfit abgeschlossen!" << endl;

    IntegrationVollständig();

    Spiegelung();

    DeleteMatrixTypeDouble(ImportMatrix, ZeilenanzahlImportMatrix);
    DeleteMatrixTypeDouble(MittelungMatrix, ZeilenanzahlMittelungMatrix);
    DeleteMatrixTypeDouble(GlaettungMatrix, ZeilenanzahlGlaettungMatrix);
    DeleteMatrixTypeLongDouble(PolynomKoeffizientenMatrix, ZeilenzahlPolynomKoeffizientenMatrix);
    DeleteMatrixTypeDouble(IntegrationMatrix, ZeilenzahlIntegrationMatrix);
    DeleteMatrixTypeDouble(SpiegelMatrix, ZeilenanzahlSpiegelMatrix);

    cout << "\n\nProgramm abgeschlossen!";

    return 0;
}
