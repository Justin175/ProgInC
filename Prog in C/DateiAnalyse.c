//DateiAnalyse.c
//Erstellt	am 04.03.2021
//			von Justin Treulieb

#include "Datenstrukturen.h"

#define MAX_PATH_LENGTH 500

#define OPTION_ANALYSE 1
#define OPTION_SORTIEREN 2
#define OPTION_SUCHEN 3
#define OPTION_BEENDEN 4

#define IS_NULL(x) ((x) == NULL)
#define PRINT_IF_NULL_ERROR(x, error_msg_str) if(IS_NULL(x)) \
{\
	fprintf(stderr, "Ein Fehler beim %s ist aufgetreten.\n -> Kein Speicherplatz mehr vorhanden.\n", error_msg_str);\
	break;\
}

int readOption() {
	printf("\n\nGeben Sie eine Verarbeitungs-Option an:\n");
	printf("   %d: Gesamte Analyse der Woerter\n", OPTION_ANALYSE);
	printf("   %d: Woerter sortieren\n", OPTION_SORTIEREN);
	printf("   %d: Woerter suchen\n", OPTION_SUCHEN);
	printf("   %d: Program beenden\n", OPTION_BEENDEN);
	printf("Ihre Wahl: ");

	char input = _getche();
	int option = -1;

	//Zeilenumbruch nach Eingabe ausgeben
	printf("\n");

	//convert input
	switch (input)
	{
	case '1': option = OPTION_ANALYSE; break;
	case '2': option = OPTION_SORTIEREN; break;
	case '3': option = OPTION_SUCHEN; break;
	case '4': option = OPTION_BEENDEN; break;
	default: //unbekannte ID, erneut einlesen
		printf("Die von Ihnen angegebene Option <%c> ist unbekannt.\n", input);
		option = readOption();
		break;
	}

	return option;
}

int main() {
	unsigned long anzahlWoerter = 0;
	Wort* woerter = NULL;
	int option; //<optionen: analyse 1, sortieren 2, suchen 3, ende 4>

	//Eingabe Datei Input
	printf("Geben Sie den Namen der Eingabe-Datei an (maximal %d Zeichen werden gelesen):\n", MAX_PATH_LENGTH);

	//eingabedatei lesen und verarbeiten
	{
		char path[MAX_PATH_LENGTH + 1];
		path[MAX_PATH_LENGTH] = 0; //aus sicherheitsgründen letztes byte auf 0 setzen (-> String ende)

		//string lesen
		gets_s(path, MAX_PATH_LENGTH);
		fflush(stdin);

		//datei verarbeiten
		woerter = einlesen(path, &anzahlWoerter);

		//wörter überprüen
		if (woerter == NULL) {
			fprintf(stderr, "[FEHLER] Ein Fehler beim einlesen der Datei ist aufgetreten.\n");
			return -1;
		}
	}

	printf("Die Datei enthaelt %lu Woerter.\n", anzahlWoerter);
	//Ausgabe wäörter
	for (unsigned long i = 0; i < anzahlWoerter; i++) {
		printf("%lu: '%s'\n", i, woerter[i].wort);
	}

	//Eingabe Datei Output
	printf("\n\nGeben Sie den Namen der Ausgabe-Datei an (maximal %d Zeichen werden gelesen):\n", MAX_PATH_LENGTH);
	//eingabedatei lesen und verarbeiten
	{
		char path[MAX_PATH_LENGTH + 1];
		path[MAX_PATH_LENGTH] = 0; //aus sicherheitsgründen letztes byte auf 0 setzen (-> String ende)

		//string lesen
		gets_s(path, MAX_PATH_LENGTH);
		fflush(stdin);

		//datei verarbeiten
		ausgabeDatei = fopen(path, "a"); //Mode Appends  -> Schreibe etwas ans ende der Datei

		if (ausgabeDatei == NULL) { //Datei existiert nicht, datei mit anderem Mode öffnen
			ausgabeDatei = fopen(path, "w");
		}

		//wörter überprüen
		if (ausgabeDatei == NULL) {
			fprintf(stderr, "[FEHLER] Die Datei konnte nicht geoeffnet werden.\n");
			return -2;
		}
	}

	//option einlesen
	option = readOption();

	//Schleifen Variablen
	unsigned long neueWoerterLaenge;
	Wort* neueWoerter = NULL;
	int doOutput = 0;
	static char* error_msg[] = { "analysieren", "sortieren", "suchen" };

	while (option != OPTION_BEENDEN) {
		neueWoerterLaenge = 0;
		doOutput = 1;

		switch (option)
		{
		case OPTION_ANALYSE: {
			neueWoerter = gesamtAnalyse(woerter, anzahlWoerter, &neueWoerterLaenge);
			break;
		}
		case OPTION_SUCHEN: {
			doOutput = 0;
			fflush(stdin); //Puffer löschen

			printf("Geben Sie das Wort an, nach dem gesucht werden soll (maximal %d Zeichen werden gelesen): ", MAX_PATH_LENGTH);
			
			//Wort lesen
			char suchenStr[MAX_PATH_LENGTH + 1];
			suchenStr[MAX_PATH_LENGTH] = 0; //String ende zeichen setzen
			gets_s(suchenStr, MAX_PATH_LENGTH);

			//Suche nach dem Wort
			printf("Suche nach dem Wort '%s'.\n", suchenStr);
			Wort* wort = suchen(woerter, anzahlWoerter, suchenStr);

			printf("'%s': L=%d V=%d", wort->wort, wort->laengeWort, wort->anzahl);

			//ausgeben des Worts
			ausgabe(wort, 1);
			break;
		}
		case OPTION_SORTIEREN: {
			int error = 0;/*
			Wort* neueWoerterAnalysed = gesamtAnalyse(woerter, anzahlWoerter, &neueWoerterLaenge);
			PRINT_IF_NULL_ERROR(neueWoerterAnalysed, "sortieren")
			else {
				error = 1; 
				doOutput = 1;
				break;
			}*/

			
			neueWoerter = sortieren(woerter, anzahlWoerter);
			neueWoerterLaenge = anzahlWoerter;
			break;
		}
		default:
			doOutput = 0;
			break;
		}

		if (doOutput) {
			PRINT_IF_NULL_ERROR(neueWoerter, error_msg[option - 1])
			else {
				ausgabe(neueWoerter, neueWoerterLaenge);
				free(neueWoerter);
			}
		}

		option = readOption();
	}

	//Ausgabe-Datei schließen
	fclose(ausgabeDatei);
}