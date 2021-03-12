#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define MAX_WORD_LENGTH 500

#define ISO_C

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

FILE* ausgabeDatei;

typedef struct Wort {
	char wort[MAX_WORD_LENGTH + 1];
	int laengeWort;

	unsigned long anzahl;
	//Wort* next;
} Wort;

//NULL -> Datei existiert nicht
Wort* einlesen(char* datei_name, unsigned long* anzahlWoerter);

Wort* gesamtAnalyse(Wort* woerter, unsigned long anzahlWoerter, unsigned long* neueGroesse);

// Funktion zum Suchen eines Wortes
// Rückgabewert ist ein Pointer auf das erste gefundene Wort
// Falls das gesuchte Wort nicht vorhanden ist, wird ein NULL-Pointer zurückgegeben
Wort* sortieren(Wort* woerter, unsigned long anzahlWoerter);

Wort* suchen(Wort* woerter, unsigned long anzahlWoerter, char* wort);

int ausgabe(Wort* woerter, unsigned long anzahlWoerter);