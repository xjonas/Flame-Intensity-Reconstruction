#pragma once
#include <iostream>
#include <string>
#include "Variablen.h"

//Welche Flammendaten sollen eingelesen werden? Dateipfad wird eigelesen.
void flametype() {

    cout << "\nDas Erfassen des Dateipfad hat begonnen!" << endl;

    cout << "Fuer welchen Datensatz soll die Intensitaetsverteilung berechnet werden?" << endl;
    cin >> filenameIn;  //Nutzer muss Dateiname angeben
    filepathIn = "./Rohdaten/" + filenameIn + ".txt";  //dateipfad jeweils anpassen ("./" falls alle dateien sowie code im selben ordner sind)

    cout << "Der Dateipfad wurde erfasst!" << endl;
}

//Funktion zum Öffnen und Import der Datei, Datei wieder schließen.
//Funktion zum einlesen der Datensätze und Speicherungs dieses in einer Matrix
void fileimport() {

    cout <<"\nDas Einlesen der Daten hat begonnen!" << endl;

    fstream readfile;
    readfile.open(filepathIn);
    if (readfile.is_open()) {   //Überprüfen ob angegebene Datei verwendbar ist.

        double k1; //Nonsense-double
        string k2; //Nonsense-string
        int ElementanzahlInputFile = 0;
        ZeilenanzahlImportMatrix = 0;
        SpaltenanzahlImportMatrix = 0;

        while (readfile >> k1) ElementanzahlInputFile++; //jedes einlesbare Element wird gezählt
        cout << "Es existieren " << ElementanzahlInputFile << " Elemente in der Datei." << endl;
        readfile.close();

        readfile.open(filepathIn);
        while (getline(readfile, k2)) {
            if (k2 != "")ZeilenanzahlImportMatrix++; //jede einlesbare Zeile wird gezählt. Gleichbedeutend mit der entgültigen Zeilenanzahl der Matrix
        }
        readfile.close();

        SpaltenanzahlImportMatrix = ElementanzahlInputFile / ZeilenanzahlImportMatrix;

        ImportMatrix = CreateMatrixTypeDouble(ZeilenanzahlImportMatrix, SpaltenanzahlImportMatrix); //Matrix der passenden Größe zur Speicherung der Daten wird erstellt

        readfile.open(filepathIn);
        for (int i = 0; i < ZeilenanzahlImportMatrix; i++) {    //Werte werden in Matrix gespeichert
            for (int j = 0; j < SpaltenanzahlImportMatrix; j++) {
                readfile >> ImportMatrix[i][j];
            }
        }
        readfile.close();
        cout << "Datei wurde erfolgreich eingelesen" << endl;
        cout << "ImportMatrix der Groesse [" << ZeilenanzahlImportMatrix << "]x[" << SpaltenanzahlImportMatrix << "] wurde erstellt und enthaelt die eingelesenen Daten." << endl;
    }

    else {
        cout << "Error! Datei konnte nicht eingelesen werden! Bitte Programm neustarten!" << endl;
    }


    cout << "Das Einlesen der Daten ist abgeschlossen!" << endl;
}