#include "stdio.h"
#include "stdlib.h"

char* strncpy(char* dest, char* src, int size) {
	for (int i = 0; i < size - 1; i++)
		*(dest + i) = *(src + i);

	*(dest + size - 1) = (char) 0;
	return dest;
}

//length or -1 if max reached
int strnlength(const char* str, size_t max) {
	int length = 0;
	for (; length != max; length++) {
		if (*(str + length) == 0)
			break;
	}

	return length == max ? -1 : length;
}

char* addstr(const char* str1, const char* str2) {
	int str1Length = strnlength(str1, 0xFFFF);
	int str2Length = strnlength(str2, 0xFFFF);

	if (str1Length == -1 || str2Length == -1)
		return (char*) NULL;

	//create new string (size = str1Length + str2Length + 1 -> +1 for string end character)
	char* nString = malloc(sizeof(char) * (str1Length + str2Length + 1));
	char* nStringPosition = nString;

	//adding first string into nString
	for (size_t i = 0; i < str1Length; i++, nStringPosition++) {
		*(nStringPosition) = *(str1 + i);
	}

	//adding second string into nString
	for (size_t i = 0; i < str2Length; i++, nStringPosition++) {
		*(nStringPosition) = *(str2 + i);
	}

	//set string end
	*(nStringPosition) = (char) 0;

	return nString;
}

int main2() {
	char* s1 = "AAAA";
	char* s2 = "BBB";

	char* sa = addstr(s1, s2);
	printf("%s", sa);

	free(sa);

	return 0;
}