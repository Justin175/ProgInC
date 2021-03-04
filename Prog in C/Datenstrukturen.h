#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

FILE* ausgabeDatei;

#define MAX_WORD_LENGTH 500

typedef struct Wort {
	char wort[MAX_WORD_LENGTH + 1];
	char laengeWort;

	unsigned long anzahl;
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