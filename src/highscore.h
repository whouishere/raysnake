#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#define SAVE_FILE "score.sav"

unsigned int readHighScore(void);
void saveHighScore(unsigned int score);

#endif // HIGHSCORE_H
