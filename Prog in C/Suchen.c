#pragma once

#include "Datenstrukturen.h"

// Funktion zum Suchen eines Wortes
// Rückgabewert ist ein Pointer auf das erste gefundene Wort
// Falls das gesuchte Wort nicht vorhanden ist, wird ein NULL-Pointer zurückgegeben
struct Wort* suchen(Wort* woerter, unsigned long anzahlWoerter, char* wort) {
    int i;
    Wort* gefunden = 0;
    // Fall: Es ist kein Wort in der Datei vorhanden
    if (anzahlWoerter == 0) {
        printf("Es gibt keine Wörter in der Datei.");
        return gefunden;
    }
    // Fall: Es wurde kein Wort zum Suchen eingegeben
    if (strlen(wort) == 0) {
        printf("Es wurde kein Wort zum Suchen eingegeben.");
        return gefunden;
    }
    // Lineare Suche nach dem Wort
    for (i = 0; i < anzahlWoerter; i++) {
        woerter += i;
        if (!strcmp(woerter->wort, wort)) {
            gefunden = &woerter;
        }
    }
    return gefunden;
}