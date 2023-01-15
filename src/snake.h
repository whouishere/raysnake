#ifndef SNAKE_H
#define SNAKE_H

#include "raylib.h"

// snake body maximum length
#define MAX_LENGTH 256

// snake's properties
typedef struct SnakeBody {
	Vector2 pos[MAX_LENGTH]; // body's cells position
	int dir; // snake's head direction
	int length; // current body length
} SnakeBody;

// returns SnakeBody pointer
SnakeBody* getSnakeBody(void);

// draws snake into the game. (drawing context must be open)
void snakeDraw(void);
void snakeControls(void);
void snakeMovement(void);

#endif // SNAKE_H
