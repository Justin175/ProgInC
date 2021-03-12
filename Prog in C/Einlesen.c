#include "Datenstrukturen.h"

Wort* einlesen(char* dateiname, unsigned long* sizeofWortPtr) {
    int size = 1000;
    Wort* woerter = (Wort*)malloc(size * sizeof(Wort));  // erstmal Platz für 1000 Wörter
    char wort[501];

    int posInWort = 0;
    unsigned long countWords = 0;
    int zeichen;

    // Öffnen der Datei
    FILE* file = fopen(dateiname, "r");

    //Prüfen ob Datei existiert
    if (file == NULL) {
        fprintf(stderr, "Datei kann nicht geöffnet werden.\n");
        return NULL;
    }

    while ((zeichen = fgetc(file)) != EOF) {
        // Semikolon eingelesen -> neues Wort beginnt
        if (zeichen == ';')
        {
            // Speicherbreich vergrößern
            if (countWords >= size) {
                size = size * 10;
                woerter = (Wort*) realloc(woerter, size * sizeof(Wort));
            }



            Wort* tempWort = (woerter + countWords);
            countWords++;
            tempWort->laengeWort = posInWort;
            memcpy(tempWort->wort, wort, posInWort);
            //strcpy_s(tempWort->wort, posInWort, wort);

            //HAllo
            //dullo\0

            posInWort = 0;
        }
        else {
            wort[posInWort++] = zeichen;
        }



    }
    //Schließen der Datei
    fclose(file);



    // Anzahl der Wörter setzen
    *sizeofWortPtr = countWords;



    return woerter;
}