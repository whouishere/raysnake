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

#include "food.h"
#include "raylib.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Vector2 food;
bool hasFood;

// utility function, used only on foodDraw
static int random(int min, int max) {
	srand(time(NULL));
	return min + rand() % (max - min);
}

Vector2* getFoodPosition() {
	return &food;
}

bool getHasFood() {
	return hasFood;
}

void setHasFood(bool newFoodState) {
	hasFood = newFoodState;
}

void foodDraw(Vector2* food) {
	if (hasFood) {
		Vector2 newFood;
		newFood.x = random(1, GRID_SIZE - 2);
		newFood.y = random(1, GRID_SIZE - 2);
		
		// avoids spawning the food at the last position again
		if (newFood.x == food->x && newFood.y == food->y) {
			// it returns without drawing nor unsetting hasFood, until it gets a different position
			printf("same food position as before!");
			return;
		}

		*food = newFood;
	}

	DrawRectangle(food->x * SCALE, 
				  food->y * SCALE, 
				  1 * SCALE - 1, 
				  1 * SCALE - 1, 
				  FOOD_COLOR);
	
	hasFood = false;
}
