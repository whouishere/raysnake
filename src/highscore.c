#include "highscore.h"

#include "raylib.h"

#include <stdio.h>
#include <stdlib.h>

static bool scoreLoaded = false;

bool isScoreLoaded(void) {
	return scoreLoaded;
}

unsigned int readHighScore(void) {
	scoreLoaded = true;

	if (!FileExists(SAVE_FILE)) {
		return 0;
	}

	const char* file_str = LoadFileText(SAVE_FILE);

	return (strtoul(file_str, NULL, 10));
}

void saveHighScore(unsigned int score) {
	const int len = snprintf(NULL, 0, "%u", score);
	char data_buffer[len + 1];

	const int written = snprintf(data_buffer, len + 1, "%u", score);
	if (written != len) {
		TraceLog(LOG_ERROR, "Couldn't convert score to string.");
	}

	// TODO: save on the games' directory, and not where the user is executing it from.
	// <https://stackoverflow.com/a/34271901/13959383>
	if (!SaveFileText(SAVE_FILE, data_buffer)) {
		TraceLog(LOG_ERROR, "Failed to write to save file.");
	}
}
