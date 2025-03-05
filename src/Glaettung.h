#pragma once
#include <iostream>
#include "Variablen.h"
#include "Create_Delete_Matrix.h"
using namespace std;

//Glätten der MatrixWerte

void Glaetten() {

    cout << "\nDie Glaettung hat begonnen!" << endl;
    ZeilenanzahlGlaettungMatrix = ZeilenanzahlMittelungMatrix;
    SpaltenanzahlGlaettungMatrix = SpaltenanzahlMittelungMatrix;

    GlaettungMatrix = CreateMatrixTypeDouble(ZeilenanzahlGlaettungMatrix, SpaltenanzahlGlaettungMatrix);
    cout << "GlaettungsMatrix der Groesse [" << ZeilenanzahlGlaettungMatrix << "][" << SpaltenanzahlGlaettungMatrix << "] wurde erstell." << endl;

    IntervallBreite = 2 * AnzahlNachbarElemente + 1;
    cout << "Die GlaettungsIntervalle besitzen eine Breite von: " << IntervallBreite << endl;

    for (int i = 0; i < ZeilenanzahlMittelungMatrix;i++) {
        for (int j = 0;j < SpaltenanzahlMittelungMatrix;j++) { //Grenzen Müssen so gewählt werden, da es für j=0 e>0 keine Werte links gibt->Error.Analog am rechten rand j=letzeSpalte;VERBESSERUNG!!!
            for (int k = j - AnzahlNachbarElemente; k <= j + AnzahlNachbarElemente;k++) {
                if (k < 0) {
                    SummeIntervallElemente += MittelungMatrix[i][0];
                }
                else {
                    if (k > SpaltenanzahlMittelungMatrix - 1) {
                        SummeIntervallElemente += MittelungMatrix[i][SpaltenanzahlMittelungMatrix - 1];
                    }
                    else {
                        SummeIntervallElemente += MittelungMatrix[i][k];
                    }
                }
            }
            IntervallMittelwert = SummeIntervallElemente / (double(IntervallBreite)); //TypeCast zur Sicherheit, dass nicht auf ein Interger gerundet wird

            GlaettungMatrix[i][j] = IntervallMittelwert;
            SummeIntervallElemente = 0;
            IntervallMittelwert = 0;
        }
    }

    WriteDataArrayDouble("Glaettung", GlaettungMatrix, ZeilenanzahlGlaettungMatrix, SpaltenanzahlGlaettungMatrix);
    cout <<"Die Glaettung ist abgeschlossen!" << endl;
}
