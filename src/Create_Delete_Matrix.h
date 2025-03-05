#pragma once
#include <iostream>
using namespace std;

double** CreateMatrixTypeDouble(int Zeilenanzahl, int Spaltenanzahl) {

	double** Matrix = new double* [Zeilenanzahl];

	for (int i = 0;i < Zeilenanzahl;i++) {
		Matrix[i] = new double[Spaltenanzahl];
	}

	return Matrix;
}

void DeleteMatrixTypeDouble(double** &Matrix, int Zeilenanzahl){

	for (int i = 0; i < Zeilenanzahl;i++) {
		delete[] Matrix[i];
	}

	delete[] Matrix;
	Matrix = NULL;
}

long double** CreateMatrixTypeLongDouble(int Zeilenanzahl, int Spaltenanzahl) {

	long double** Matrix = new long double* [Zeilenanzahl];

	for (int i = 0;i < Zeilenanzahl;i++) {
		Matrix[i] = new long double[Spaltenanzahl];
	}

	return Matrix;
}

void DeleteMatrixTypeLongDouble(long double** &Matrix, int Zeilenanzahl) {

	for (int i = 0; i < Zeilenanzahl;i++) {
		delete[] Matrix[i];
	}

	delete[] Matrix;
	Matrix = NULL;
}