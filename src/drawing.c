#include "drawing.h"

#include "raylib.h"

#include "game.h"
#include "input.h"
#include "highscore.h"
#include "snake.h"
#include "food.h"

static SnakeBody* p_snake;
static int frameCount = 0;

void init(void) {
	p_snake = getSnakeBody();
	setHasFood(true);

	p_snake->length = 1;
	p_snake->pos[0] = SNAKE_START;
}

void update(void) {
	frameCount++;

	processInput();

	if (!getLost()) {
		snakeControls(p_snake);
		if (frameCount % 15 == 0) {
			snakeMovement(p_snake);
		}
	} else if (!isScoreLoaded()) {
		unsigned int highscore = readHighScore();
		unsigned int score = getScore();
		
		// save if there's a new record
		if (score > highscore) {
			saveHighScore(score);
			setNewRecord(true);
		}
	}
}

void draw(void) {
	BeginDrawing();
		ClearBackground(RAYWHITE);

		// drawing game grid lines
		for (int x = 0; x < GRID_SIZE; x++) {
			DrawLine(x * SCALE, 0, x * SCALE, GRID_SIZE * SCALE, GRID_COLOR);
		}
		for (int y = 0; y < GRID_SIZE; y++) {
			DrawLine(0, y * SCALE, GRID_SIZE * SCALE, y * SCALE, GRID_COLOR);
		}
	
		foodDraw(getFoodPosition());
		snakeDraw(getSnakeBody());

		DrawText(getScoreStr(), 0.25 * SCALE, 0.25 * SCALE, 1 * SCALE, TEXT_COLOR);
		
		if (getLost()) {
			lostDraw();

			EndDrawing();
			return;
		}
	EndDrawing();
}
