#include "Datenstrukturen.h"

Wort* gesamtAnalyse(Wort* woerter, unsigned long anzahlWoerter, unsigned long* neueGroesseDerWoerter) {
    unsigned long nAnzahlWoerter = 0;
    Wort* tempWoerter = malloc(sizeof(Wort) * anzahlWoerter);
    if (tempWoerter == NULL) {
        return NULL;
    }
    Wort* tempWort;
    for (unsigned long i = 0; i < anzahlWoerter; i++) {
        tempWort = suchen(tempWoerter, nAnzahlWoerter, (*(woerter + i)).wort);
        if (NULL == tempWort) {
            *(tempWoerter + nAnzahlWoerter) = *(woerter + i);
            nAnzahlWoerter++;
        }
        else {
            tempWort->anzahl++;
        }

    }


    Wort* nWoerter = malloc(sizeof(Wort) * nAnzahlWoerter);
    if (nWoerter == NULL) {
        return NULL;
    }

    *neueGroesseDerWoerter = nAnzahlWoerter;

    while (nAnzahlWoerter) {
        nWoerter[nAnzahlWoerter] = tempWoerter[nAnzahlWoerter];
        nAnzahlWoerter--;
    }
    free(tempWoerter);
    return nWoerter;
}