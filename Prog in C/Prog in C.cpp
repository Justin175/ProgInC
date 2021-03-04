#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

//Aufgabe 1

struct Steuerfeld {
	unsigned Adresse	: 7;
	unsigned NR			: 2;
	unsigned P			: 1;
	unsigned NW			: 2;
	unsigned S			: 1;
};

struct NachrichtenFormat {
	unsigned char Flag1;
	Steuerfeld steuerfeld;
	unsigned char Datenfeld[256];
	unsigned char FCS;
	unsigned char Flag2;
};

//Aufgabe 2

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define READ_CONSOLE_CHAR(var) scanf_s("%c", &var, 1)

#define OPTION_SHOW  '1'
#define OPTION_ADD   '2'
#define OPTION_SORT  '3'
#define OPTION_END   27

struct Buch {
	const char name[200];
	const char author[200];
};

int compareBuch(const void* v1, const void* v2) {
	//cast
	Buch* b1 = (Buch*) v1;
	Buch* b2 = (Buch*) v2;

	//compare names
	//0 : names are equal
	//>0 : b1 > b2
	//<0 : b1 < b2
	int comp = 0;
	size_t nameLengthB1 = strnlen_s(b1->author, 200);
	size_t nameLengthB2 = strnlen_s(b2->author, 200);

	//compare
	for (size_t i = 0; i != MIN(nameLengthB1, nameLengthB2); i++) {
		if (b1->author[i] < b2->author[i]) {
			comp = 1;
			break;
		}
		else if (b1->author[i] > b2->author[i]) {
			comp = -1;
			break;
		}
	}

	return comp != 0 ? comp : (nameLengthB1 < nameLengthB2 ? -comp : comp);
}

void printStart() {
	printf("%s\n\n", "* * * BUECHER-VERZEICHNIS * * *");

	printf("%s\n",		"1   = Katalogeintrag anzeigen.");
	printf("%s\n",		"2   = Katalogeintrag hinzufguegen.");
	printf("%s\n",		"3   = Katalogeintrag sortieren.");
	printf("%s\n\n\n",	"ESC = Program beenden.");
}

int main2()
{
	//Deklaration / Initialisation von Variablen
	char in;															// Speichert den gelesenen Character
	int sr;																// Speichert Rückgabewert von scanf_s
	struct Buch* buecher = (Buch*) malloc(sizeof(struct Buch) * 10000);	// Speichert die Bücher
	//struct Buch buecher[200] = {};
	size_t anzahlBuecher = 0;											// Anzahl der Buecher

	//Maske printen
	printStart();

	//Erstes einlesen
	printf("Ihre Wahl: ");
	in = _getche();
	//fflush(stdin);
	

	while (in != OPTION_END) {
		switch (in)
		{
		case OPTION_ADD:

		case OPTION_SHOW:

		case OPTION_SORT:
			if (anzahlBuecher != 0)
				qsort(buecher, anzahlBuecher, sizeof(struct Buch), compareBuch);
			break;
		case OPTION_END: //do nothing
			break;
		default:
			printf("Die von Ihnen gewaehle Option <%c> steht nicht zur verfuegung. Versuchen Sie es erneut.", in);
		}

		//read
		in = _getche();
	}

	free(buecher);

	return 2;
}

