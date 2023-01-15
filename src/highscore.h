#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#define SAVE_FILE "score.sav"

#include <stdbool.h>

bool isScoreLoaded(void);
unsigned int readHighScore(void);
void saveHighScore(unsigned int score);

#endif // HIGHSCORE_H
