#ifndef FOOD_H
#define FOOD_H

#include "raylib.h"

#include <stdbool.h>

// draws and updates food position. (drawing context must be open)
void foodDraw(Vector2* food);

// returns a pointer to the Vector2 food position
Vector2* getFoodPosition(void);
// returns hasFood boolean. (if food was eaten)
bool getHasFood(void);
// sets a new state for hasFood boolean
void setHasFood(bool newFoodState);

#endif // FOOD_H
