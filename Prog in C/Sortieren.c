#include "Datenstrukturen.h"

int vergleicheWort(const void* w1, const void* w2)
{
    Wort wort1 = *(Wort*) w1;
    Wort wort2 = *(Wort*) w2;

    return strcmp(wort1.wort, wort2.wort);
}

Wort* sortieren(Wort* woerter, unsigned long anzahlWoerter)
{
    if (anzahlWoerter == 0)
        return NULL;

    Wort* ret = (Wort*) malloc((size_t) (anzahlWoerter * sizeof(Wort)));

    if (ret != NULL)
    {
        int count;

        // Inhalt des Dateiinhaltsvektor in ret rüberkopieren
        for (count = 0; count < anzahlWoerter; count++)
        {
            *(ret + count) = *(woerter + count);
        }

        qsort(ret, (size_t)anzahlWoerter, (size_t) (sizeof(Wort)), vergleicheWort);
    }

    return ret;
}