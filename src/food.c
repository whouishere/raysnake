#include "food.h"

#include "raylib.h"

#include "game.h"

Vector2 food;
bool hasFood;

#if DEBUG
// maybe find a better name/implementation?
static unsigned int pos_repeat_count = 0;
#endif

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
		newFood.x = GetRandomValue(1, GRID_SIZE - 2);
		newFood.y = GetRandomValue(1, GRID_SIZE - 2);
		
		// TODO: write test on how many times this happens
		// if food is found at the same spot as before, randomize it again.
		if (newFood.x == food->x && newFood.y == food->y) {
			foodDraw(food);
			return;
		}

		#if DEBUG
		if (pos_repeat_count > 0) {
			TraceLog(LOG_INFO, "Food spawned at the same position %u times!", pos_repeat_count);
			pos_repeat_count = 0;
		}
		#endif

		*food = newFood;
	}

	DrawRectangle(food->x * SCALE, 
				  food->y * SCALE, 
				  1 * SCALE - 1, 
				  1 * SCALE - 1, 
				  FOOD_COLOR);
	
	hasFood = false;
}
