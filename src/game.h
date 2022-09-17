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

#ifndef GAME_H
#define GAME_H

#define GRID_SIZE 12
#define WIN_SIZE 600
#define SCALE 50

#define BACKGROUND_COLOR RAYWHITE
#define WINDOW_BG_COLOR  GRAY
#define GRID_COLOR       BLACK
#define TEXT_COLOR       BLUE
#define LOST_COLOR       RED
#define SNAKE_COLOR      GREEN
#define FOOD_COLOR       RED

#define LOST_TEXT    "You Lost!"

#include "raylib.h"

#include <stdbool.h>

// returns current score value
unsigned int getScore();
// returns lost state boolean (if player has lost)
bool getLost();

// sets current score value
void setScore(unsigned int newScore);
// sets lost state boolean
void setLost(bool newLost);

void drawLost();

#endif // GAME_H
