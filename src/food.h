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

#ifndef FOOD_H
#define FOOD_H

#include "raylib.h"

#include <stdbool.h>

#include "game.h"

// draws and updates food position. (drawing context must be open)
void foodDraw(Vector2* food);

// returns a pointer to the Vector2 food position
Vector2* getFoodPosition(void);
// returns hasFood boolean. (if food was eaten)
bool getHasFood(void);
// sets a new state for hasFood boolean
void setHasFood(bool newFoodState);

#endif // FOOD_H
