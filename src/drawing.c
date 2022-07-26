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

#include "drawing.h"

static SnakeBody* p_snake;
static int frameCount = 0;
static char scoreStr[5];

void init() {
	p_snake = getSnakeBody();
	setHasFood(1);

	p_snake->length = 1;
	p_snake->pos[0].x = GRID_SIZE / 2.0;
	p_snake->pos[0].y = GRID_SIZE / 2.0;
}

void update() {
	frameCount++;

	processInput();

	if (!getLost()) {
		snakeControls(p_snake);
		if (frameCount % 15 == 0) {
			snakeMovement(p_snake);
		}
	}
}

void draw() {
	BeginDrawing();
		ClearBackground(RAYWHITE);

		// drawing game grid lines
		for (int x = 0; x < GRID_SIZE; x++) {
			DrawLine(x * SCALE, 0, x * SCALE, GRID_SIZE * SCALE, GRID_COLOR);
		}
		for (int y = 0; y < GRID_SIZE; y++) {
			DrawLine(0, y * SCALE, GRID_SIZE * SCALE, y * SCALE, GRID_COLOR);
		}
	
		foodDraw(getFoodPosition());
		snakeDraw(getSnakeBody());

		sprintf(scoreStr, "%d", getScore());
		DrawText(scoreStr, 0.25 * SCALE, 0.25 * SCALE, 1 * SCALE, TEXT_COLOR);
		
		if (getLost()) {
			EndDrawing();
			return;
		}
	EndDrawing();
}
