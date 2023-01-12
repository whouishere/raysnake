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

Vector2* getFoodPosition(void) {
	return &food;
}

bool getHasFood(void) {
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
