#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Variablen.h"
#include <string>
using namespace std;

void WriteDataArrayDouble(string filenameOut, double** Array, int ZeilenanzahlArray, int SpaltenanzahlArray) {

	fstream File;
	filenameOut = filenameIn + "_" + filenameOut + "_GLT" + to_string(2*AnzahlNachbarElemente+1) + "_PG" + to_string(Polynomgrad) + "_DIFF" + to_string(int(-log10(h))) + "_INT" + to_string(int(AnzahlTeilintervalle)) + ".txt";
	filepathOut = "./Ergebnisse/" + filenameOut;
	File.open(filepathOut, ios::out);

	if (!File.is_open()) {
		cout << "File kann nicht gefunden oder erstellt werden!" << endl;
	}
	cout << filenameOut << " wurde gefunden/erstellt und enthält die Ergebnisse von dem aktuellen Schritt." << endl;
	for (int i = 0;i < ZeilenanzahlArray;i++) {
		for (int j = 0;j < SpaltenanzahlArray;j++) {
			File << Array[i][j] << " ";
		}
		File << "\n";
	}
	File.close();
}

void WriteDataArrayLongDouble(string filenameOut, long double** Array, int ZeilenanzahlArray, int SpaltenanzahlArray) {

	fstream File;
	filenameOut = filenameOut = filenameIn + "_" + filenameOut + "_GLT" + to_string(2 * AnzahlNachbarElemente + 1) + "_PG" + to_string(Polynomgrad) + "_DIFF" + to_string(int(-log10(h))) + "_INT" + to_string(int(AnzahlTeilintervalle)) + ".txt";
	filepathOut = "./Ergebnisse/" + filenameOut;
	File.open(filepathOut, ios::out);

	if (!File.is_open()) {
		cout << "File kann nicht gefunden oder erstellt werden!" << endl;
	}
	cout << filenameOut << " wurde gefunden/erstellt und enthält die Ergebnisse von dem aktuellen Schritt." << endl;
	for (int i = 0;i < ZeilenanzahlArray;i++) {
		for (int j = 0;j < SpaltenanzahlArray;j++) {
			File << Array[i][j] << " ";
		}
		File << "\n";
	}
	File.close();
}

