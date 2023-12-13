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

void snakeDraw(void) {
	for (int i = 0; i < snake.length; i++) {
		DrawRectangle(snake.pos[i].x * SCALE, 
					  snake.pos[i].y * SCALE + 1, // off-by-one graphical bug
					  1 * SCALE - 1, 
					  1 * SCALE - 1, 
					  SNAKE_COLOR);
	}
}

void snakeControls(void) {
	InputKeys snekControlKeys = getInputKeys();

	if (snekControlKeys.up && snake.dir != DOWN)
		snake.dir = UP;
	
	if (snekControlKeys.down && snake.dir != UP)
		snake.dir = DOWN;
	
	if (snekControlKeys.left && snake.dir != RIGHT)
		snake.dir = LEFT;
	
	if (snekControlKeys.right && snake.dir != LEFT)
		snake.dir = RIGHT;
}

void snakeMovement(void) {
	Vector2* food = getFoodPosition();

	// check if head is inside food
	if (snake.pos[0].x == food->x && snake.pos[0].y == food->y) {
		setHasFood(true);
		setScore(getScore() + 1);
		snake.length++;
	}
	
	// move snake body (but not the head, yet)
	for (int i = snake.length - 1; i > 0; i--) {
		// since we are already looping through the snake body, check collision with itself
		if (snake.pos[0].x == snake.pos[i].x && snake.pos[0].y == snake.pos[i].y) {
			setLost(true);
			return; // stop moving
		}

		snake.pos[i].x = snake.pos[i - 1].x;
		snake.pos[i].y = snake.pos[i - 1].y;
		
		// if food is somewhere inside the snake body, make it roll the food again (but not eat it)
		if (snake.pos[i].x == food->x && snake.pos[i].y == food->y) {
			setHasFood(true);
		}
	}
	
	// move snake head
	switch (snake.dir)
	{
		case UP:
			if (snake.pos[0].y != -1)
				snake.pos[0].y--;
			break;
		case DOWN:
			if (snake.pos[0].y != GRID_SIZE)
				snake.pos[0].y++;
			break;
		case LEFT:
			if (snake.pos[0].x != -1)
				snake.pos[0].x--;
			break;
		case RIGHT:
			if (snake.pos[0].x != GRID_SIZE)
				snake.pos[0].x++;
			break;
	}

	// if head hit wall
	if (snake.pos[0].x == GRID_SIZE || 
		snake.pos[0].x == -1 || 
		snake.pos[0].y == GRID_SIZE || 
		snake.pos[0].y == -1) {
		setLost(true);
	}
}
