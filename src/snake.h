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

#ifndef SNAKE_H
#define SNAKE_H

#include "raylib.h"

#include "game.h"
#include "input.h"
#include "food.h"

// snake body maximum length
#define MAX_LENGTH 256

// snake's properties
typedef struct SnakeBody {
	Vector2 pos[MAX_LENGTH]; // body's cells position
	int dir; // snake's head direction
	int length; // current body length
} SnakeBody;

// returns SnakeBody pointer
SnakeBody* getSnakeBody();
// returns score value
int getScore();
// returns lost boolean
int getLost();

// sets score value
void setScore(int newScore);
// sets lost boolean
void setLost(int newLost);

// draws snake into the game. (drawing context must be open)
void snakeDraw(SnakeBody* snek);
void snakeControls(SnakeBody* snek);
void snakeMovement(SnakeBody* snek);

#endif // SNAKE_H
