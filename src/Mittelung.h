#pragma once

#include<iostream>
#include<string>
#include "Variablen.h"
#include "Create_Delete_Matrix.h"
#include "WriteData.h"
using namespace std;

void Mittelung() {

	cout << "\nDie Mittelung hat begonnen!" << endl;
	cout << "Wo liegt die Symmetrieachse?" << endl;
	cin >> Symmetrieachse;
	ZeilenanzahlMittelungMatrix = ZeilenanzahlImportMatrix;

	if (SpaltenanzahlImportMatrix / 2 < Symmetrieachse) {

		SpaltenanzahlMittelungMatrix = SpaltenanzahlImportMatrix - Symmetrieachse + 1;
	}
	else {

		SpaltenanzahlMittelungMatrix = Symmetrieachse;
	}

	MittelungMatrix = CreateMatrixTypeDouble(ZeilenanzahlMittelungMatrix, SpaltenanzahlMittelungMatrix);
	cout << "MittelungMatrix der Groesse [" << ZeilenanzahlMittelungMatrix << "][" << SpaltenanzahlMittelungMatrix << "] wurde erstellt." << endl;

		Symmetrieachse -= 1; //da erste Spalte index 0 hat und nicht 1

	for (int i = 0; i < ZeilenanzahlMittelungMatrix; i++) {

		for (int j = 0; j < SpaltenanzahlMittelungMatrix; j++) {

			MittelungMatrix[i][j] = (ImportMatrix[i][Symmetrieachse + j] + ImportMatrix[i][Symmetrieachse - j]) / 2;

		}
	}

	WriteDataArrayDouble("Mittelung", MittelungMatrix, ZeilenanzahlMittelungMatrix, SpaltenanzahlMittelungMatrix);
	cout << "Die Mittelung ist abgeschlossen!" << endl;

}
