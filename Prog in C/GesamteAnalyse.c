#include "Datenstrukturen.h"

Wort* gesamtAnalyse(Wort* woerter, unsigned long anzahlWoerter, unsigned long* neueGroesseDerWoerter) {
    unsigned long nAnzahlWoerter = 0;

    if (anzahlWoerter <= 0)
        return NULL;

    Wort* tempWoerter = malloc(sizeof(Wort) * anzahlWoerter);
    if (tempWoerter == NULL) {
        return NULL;
    }
    Wort* tempWort;
    for (unsigned long i = 0; i < anzahlWoerter; i++) {
        tempWort = suchen(woerter, nAnzahlWoerter, (*(woerter + i)).wort);
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

    while (nAnzahlWoerter > 0) {
        nAnzahlWoerter--;
        nWoerter[nAnzahlWoerter] = tempWoerter[nAnzahlWoerter];
    }

    free(tempWoerter);
    return nWoerter;
}