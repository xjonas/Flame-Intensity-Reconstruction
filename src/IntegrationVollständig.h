#pragma once

#include <iostream>
#include <cmath>
#include "Variablen.h"
#include "FunktionsWert.h"
#include "WriteData.h"
#include "Create_Delete_Matrix.h"
#include "Integration.h"
#include <math.h>
using namespace std;

void IntegrationVollständig() {
    cout << "\nDie Integration hat begonnen! Dies kann einen Moment dauern..." << endl;

    R = Symmetrieachse;
    ZeilenzahlIntegrationMatrix = ZeilenzahlPolynomKoeffizientenMatrix;
    SpaltenzahlIntegrationMatrix = R;
    IntegrationMatrix = CreateMatrixTypeDouble(ZeilenzahlIntegrationMatrix, SpaltenzahlIntegrationMatrix);
    for (int i = 0; i < ZeilenzahlPolynomKoeffizientenMatrix; i++) {
        for (int r = 0; r < R; r++) {
            IntegrationMatrix[i][r] = Integration(PolynomKoeffizientenMatrix[i], r, R);
        }
    }

    WriteDataArrayDouble("Integration", IntegrationMatrix, ZeilenzahlIntegrationMatrix, SpaltenzahlIntegrationMatrix);
    cout << "Die Integration wurde abgeschlossen!" << endl;
}