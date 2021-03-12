#include "Datenstrukturen.h"
#include <limits.h>

#ifdef ISO_C
#define ITOA(x, y, z) _itoa((x), (y), (z))
#else
#define ITOA(x, y, z) itoa((x), (y), (z))
#endif

int ausgabe(Wort* woerter, unsigned long anzahlWoerter) {
	unsigned long zaehler = 0;
	//längsmögliche Zeile: längstes Wort + "\t" + laengeWort braucht maximal 3 Stellen + "\t" + anzahl braucht maximal 20 Stellen + "\n" + "\0"
	char ausgabeZeile[MAX_WORD_LENGTH + 1 + 3 + 1 + 20 + 1 + 1];
	char bufferLaengeWortToString[4];
	char bufferAnzahlToString[21];

	if (ausgabeDatei == NULL)
		return (-1);

	fputs("Wort\tLänge des Wortes\tAnzahl Vorkommen\n", ausgabeDatei);
	while (zaehler < anzahlWoerter) {
		strcpy(ausgabeZeile, (woerter + zaehler)->wort);
		strcat(ausgabeZeile, "\t");
		ITOA((woerter + zaehler)->laengeWort, bufferLaengeWortToString, 10);
		strcat(ausgabeZeile, bufferLaengeWortToString);
		strcat(ausgabeZeile, "\t");
		ITOA((woerter + zaehler)->anzahl, bufferAnzahlToString, 10);
		strcat(ausgabeZeile, bufferAnzahlToString);
		strcat(ausgabeZeile, "\n");
		fputs(ausgabeZeile, ausgabeDatei);

		zaehler++;
	}
	return 0;
}