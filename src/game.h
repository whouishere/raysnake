#ifndef GAME_H
#define GAME_H

#include "raylib.h"

#include <stdbool.h>

#define GRID_SIZE   12
#define WIN_SIZE    600
#define SCALE       50
#define SNAKE_START (Vector2){ .x = GRID_SIZE / 2.0f, .y = GRID_SIZE / 2.0f }

#define BACKGROUND_COLOR RAYWHITE
#define WINDOW_BG_COLOR  GRAY
#define GRID_COLOR       BLACK
#define TEXT_COLOR       BLUE
#define LOST_COLOR       RED
#define RECORD_COLOR     GOLD
#define LOST_BOX_COLOR   BLACK
#define SNAKE_COLOR      GREEN
#define FOOD_COLOR       RED

#define LOST_TEXT        "You Lost!"
#define HIGHSCORE_TEXT   "High Score: "
#define RECORD_TEXT      "New Record!"

// returns current score value
unsigned int getScore(void);
// returns score as string
const char* getScoreStr(void);
// returns lost state boolean (if player has lost)
bool getLost(void);

// sets current score value
void setScore(unsigned int newScore);
// sets lost state boolean
void setLost(bool newLost);
// sets new record state boolean
void setNewRecord(bool isRecord);

// draws "you lost!" text. (draw context must be open)
void lostDraw(void);

#endif // GAME_H
