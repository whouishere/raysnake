#include "snake.h"

#include <stdbool.h>

#include "game.h"
#include "input.h"
#include "food.h"

static SnakeBody snake;

typedef enum Direction {
	UP = 1, 
	DOWN = -1, 
	LEFT = -2, 
	RIGHT = 2
} Direction;

SnakeBody* getSnakeBody(void) {
	return &snake;
}

void snakeDraw(SnakeBody* snek) {
	for (int i = 0; i < snek->length; i++) {
		DrawRectangle(snek->pos[i].x * SCALE, 
					  snek->pos[i].y * SCALE, 
					  1 * SCALE - 1, 
					  1 * SCALE - 1, 
					  SNAKE_COLOR);
	}
}

void snakeControls(SnakeBody* snek) {
	InputKeys snekControlKeys = getInputKeys();

	if (snekControlKeys.up && snek->dir != DOWN)
		snek->dir = UP;
	
	if (snekControlKeys.down && snek->dir != UP)
		snek->dir = DOWN;
	
	if (snekControlKeys.left && snek->dir != RIGHT)
		snek->dir = LEFT;
	
	if (snekControlKeys.right && snek->dir != LEFT)
		snek->dir = RIGHT;
}

void snakeMovement(SnakeBody* snek) {
	Vector2* food = getFoodPosition();

	// check if head is inside food
	if (snek->pos[0].x == food->x && snek->pos[0].y == food->y) {
		setHasFood(true);
		setScore(getScore() + 1);
		snek->length++;
	}
	
	// move snake body
	for (int i = snek->length - 1; i > 0; i--) {
		snek->pos[i].x = snek->pos[i - 1].x;
		snek->pos[i].y = snek->pos[i - 1].y;
		
		// if food is somewhere inside the snake body, make it roll the food again (but not eat it)
		if (snek->pos[i].x == food->x && snek->pos[i].y == food->y)
			setHasFood(true);
	}
	
	// move snake head
	switch (snek->dir)
	{
		case UP:
			if (snek->pos[0].y != -1)
				snek->pos[0].y--;
			break;
		case DOWN:
			if (snek->pos[0].y != GRID_SIZE)
				snek->pos[0].y++;
			break;
		case LEFT:
			if (snek->pos[0].x != -1)
				snek->pos[0].x--;
			break;
		case RIGHT:
			if (snek->pos[0].x != GRID_SIZE)
				snek->pos[0].x++;
			break;
	}

	// if head hit wall
	if (snek->pos[0].x == GRID_SIZE || 
		snek->pos[0].x == -1 || 
		snek->pos[0].y == GRID_SIZE || 
		snek->pos[0].y == -1) {
		setLost(true);
	}
}
