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
#include "highscore.h"
#include "raylib.h"

#include <stdio.h>

unsigned int score;
char scoreStr[5];
bool lost;
bool newRecord = false;

unsigned int getScore(void) {
	return score;
}

const char* getScoreStr(void) {
	return scoreStr;
}

bool getLost(void) {
	return lost;
}

void setScore(unsigned int newScore) {
	score = newScore;
	sprintf(scoreStr, "%u", getScore());
}

void setLost(bool newLost) {
	lost = newLost;
}

void lostDraw(void) {
	Vector2 lostText;
	Vector2 recordText;
	const int lostFont = 1 * SCALE;
	const int recordFont = 0.5f * SCALE;
	lostText.x = MeasureText(LOST_TEXT, lostFont);
	lostText.y = lostFont;

	if (!newRecord) {
		if (FileExists(SAVE_FILE)) {
			unsigned int highscore = readHighScore();
			if (score > highscore) {
				saveHighScore(score);
				newRecord = true;
			}
		} else {
			saveHighScore(score);
			newRecord = true;
		}
	}

	const Vector2 rectSize = { .x = 5 * SCALE, .y = 2 * SCALE };
	DrawRectangle((WIN_SIZE / 2.0f) - (rectSize.x / 2), (WIN_SIZE / 2.0f) - (rectSize.y / 2), 
				  rectSize.x, rectSize.y, 
				  ColorAlpha(LOST_BOX_COLOR, 0.85f));
	
	DrawText(LOST_TEXT, 
			 (WIN_SIZE / 2.0f) - (lostText.x / 2), 
			 (WIN_SIZE / 2.0f) - (lostText.y / 2), 
			 lostFont, LOST_COLOR);
	
	if (newRecord) {
		recordText.x = MeasureText(RECORD_TEXT, recordFont);
		recordText.y = recordFont;
		DrawText(RECORD_TEXT, 
				 (WIN_SIZE / 2.0f) - (recordText.x / 2), 
				 (WIN_SIZE / 2.0f) + recordText.y, 
				 recordFont, RECORD_COLOR);
	}
}
