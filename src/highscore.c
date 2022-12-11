/* 
  Copyright © 2022 by Willian Vinagre

  This file is part of RaySnake.
  
  RaySnake is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  RaySnake is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with RaySnake. If not, see <https://www.gnu.org/licenses/>.
*/

#include "highscore.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

unsigned int readHighScore() {
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
