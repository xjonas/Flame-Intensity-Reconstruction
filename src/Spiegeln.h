#pragma once

#include<iostream>
#include<string>
#include "Variablen.h"
#include "Create_Delete_Matrix.h"
#include "WriteData.h"
using namespace std;

void Spiegelung() {

	cout << "\nDie Spiegelung hat begonnen!" << endl;

	ZeilenanzahlSpiegelMatrix = ZeilenzahlIntegrationMatrix;
	SpaltenanzahlSpiegelMatrix = 2 * SpaltenzahlIntegrationMatrix;
	SpiegelMatrix = CreateMatrixTypeDouble(ZeilenanzahlSpiegelMatrix, SpaltenanzahlSpiegelMatrix);

	for (int i = 0; i < ZeilenanzahlSpiegelMatrix; i++) {
		for (int j = 0; j < SpaltenzahlIntegrationMatrix;j++) {

			SpiegelMatrix[i][SpaltenzahlIntegrationMatrix + j] = IntegrationMatrix[i][j];
			SpiegelMatrix[i][SpaltenzahlIntegrationMatrix-1 - j] = IntegrationMatrix[i][j];
		}
	}

	WriteDataArrayDouble("Spiegelung", SpiegelMatrix, ZeilenanzahlSpiegelMatrix, SpaltenanzahlSpiegelMatrix);
	cout << "Die Spiegelung ist abgeschlossen!" << endl;
}
