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

unsigned int score;
bool lost;

unsigned int getScore() {
	return score;
}

bool getLost() {
	return lost;
}

void drawLost() {
	Vector2 text;
	text.x = MeasureText(LOST_TEXT, 1 * SCALE);
	text.y = 1 * SCALE;
	
	DrawText(LOST_TEXT, 
			 (WIN_SIZE / 2.0) - (text.x / 2), 
			 (WIN_SIZE / 2.0) - (text.y / 2), 
			 1 * SCALE, LOST_COLOR);
}

void setScore(unsigned int newScore) {
	score = newScore;
}

void setLost(bool newLost) {
	lost = newLost;
}
