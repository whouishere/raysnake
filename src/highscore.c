#include "highscore.h"

#include <errno.h>
#include <stdio.h>
#include <string.h>

unsigned int readHighScore(void) {
	FILE *fptr;
	fptr = fopen(SAVE_FILE, "r");
	if (!fptr) {
		fprintf(stderr, "Couldn't open \"%s\": %s\n", SAVE_FILE, strerror(errno));
		return 0;
	}

	unsigned int score;
	fscanf(fptr, "%u", &score);
	fclose(fptr);

	return score;
}

void saveHighScore(unsigned int score) {
	FILE *fptr;
	// TODO: save on the games' directory, and not where the user is executing it from.
	fptr = fopen(SAVE_FILE, "w");
	if (!fptr) {
		fprintf(stderr, "Couldn't open \"%s\": %s\n", SAVE_FILE, strerror(errno));
		return;
	}

	fprintf(fptr, "%u", score);
	fclose(fptr);
}
