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

#include "game.h"
#include "raylib.h"

#include <stdio.h>

unsigned int score;
char scoreStr[5];
bool lost;

unsigned int getScore() {
	return score;
}

const char* getScoreStr() {
	return scoreStr;
}

bool getLost() {
	return lost;
}

void setScore(unsigned int newScore) {
	score = newScore;
	sprintf(scoreStr, "%u", getScore());
}

void setLost(bool newLost) {
	lost = newLost;
}

void lostDraw() {
	Vector2 text;
	text.x = MeasureText(LOST_TEXT, 1 * SCALE);
	text.y = 1 * SCALE;
	
	const Vector2 rectSize = { .x = 5 * SCALE, .y = 2 * SCALE };
	DrawRectangle((WIN_SIZE / 2.0f) - (rectSize.x / 2), (WIN_SIZE / 2.0f) - (rectSize.y / 2), 
				  rectSize.x, rectSize.y, 
				  ColorAlpha(LOST_BOX_COLOR, 0.85f));
	
	DrawText(LOST_TEXT, 
			 (WIN_SIZE / 2.0f) - (text.x / 2), 
			 (WIN_SIZE / 2.0f) - (text.y / 2), 
			 1 * SCALE, LOST_COLOR);
}
