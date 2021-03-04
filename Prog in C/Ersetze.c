#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_REPLACE_COUNT 100

int main20(int argc, char* argv[]) {
	int exitCode = 0;

	if (argc < 3) {
		exitCode = -1;
	}
	else {
		//check input
		const char* toReplace = argv[1];
		const char* replaceTo = argv[2];

		const size_t replaceLength = strnlen_s(toReplace, MAX_REPLACE_COUNT);
		const size_t replaceToLength = strnlen_s(replaceTo, MAX_REPLACE_COUNT);

		//create buffer
		char* buffer = (char*) malloc(replaceLength);
		int matching = 0;

		//überprüfe ob buffer NUllzeiger ist
		if (buffer == NULL) {
			return -2;
		}

		//Start reading
		char currentChar = getchar();

		while (currentChar != EOF) {
			if (currentChar == toReplace[matching]) {
				buffer[matching] = currentChar;
				matching++;
			}
			else {
				if (matching != 0) {
					for (int i = 0; i < matching; i++)
						putchar(buffer[i]);

					matching = 0;
				}

				putchar(currentChar);
			} 

			if (matching >= replaceLength) { //found match
				matching = 0;

				//write replacing string
				for (size_t i = 0; i < replaceToLength; i++)
					putchar(replaceTo[i]);
			}

			//read next
			currentChar = getchar();
		}

		// write last buffer
		if (matching != 0) {
			for (int i = 0; i < matching; i++)
				putchar(buffer[i]);

			matching = 0;
		}

		free(buffer);
	}

	return exitCode;
}