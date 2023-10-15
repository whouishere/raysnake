#include "raylib.h"

#include <stdio.h>

#include "game.h"
#include "highscore.h"

#define SCORE_BUFFER 5

static unsigned int score;
static char scoreStr[SCORE_BUFFER];
static bool lost = false;
static bool newRecord = false;

unsigned int getScore(void) {
	return score;
}

const char* getScoreStr(void) {
	return scoreStr;
}

bool getLost(void) {
	return lost;
}

void setScore(unsigned int newScore) {
	score = newScore;
	snprintf(scoreStr, SCORE_BUFFER, "%u", getScore());
}

void setLost(bool newLost) {
	lost = newLost;
}

void setNewRecord(bool isRecord) {
	newRecord = isRecord;
}

void lostDraw(void) {
	Vector2 lostText;
	Vector2 recordText;
	const int lostFont = 1 * SCALE;
	const int recordFont = 0.5f * SCALE;
	lostText.x = MeasureText(LOST_TEXT, lostFont);
	lostText.y = lostFont;

	const Vector2 rectSize = { .x = 5 * SCALE, .y = 2 * SCALE };
	DrawRectangle((WIN_SIZE / 2.0f) - (rectSize.x / 2), (WIN_SIZE / 2.0f) - (rectSize.y / 2), 
				  rectSize.x, rectSize.y, 
				  ColorAlpha(LOST_BOX_COLOR, 0.85f));
	
	DrawText(LOST_TEXT, 
			 (WIN_SIZE / 2.0f) - (lostText.x / 2), 
			 (WIN_SIZE / 2.0f) - (lostText.y / 2), 
			 lostFont, LOST_COLOR);
	
	if (newRecord) {
		recordText.x = MeasureText(RECORD_TEXT, recordFont);
		recordText.y = recordFont;
		DrawText(RECORD_TEXT, 
				 (WIN_SIZE / 2.0f) - (recordText.x / 2), 
				 (WIN_SIZE / 2.0f) + recordText.y, 
				 recordFont, RECORD_COLOR);
	}
}