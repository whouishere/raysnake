#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>

// input keys booleans
typedef struct InputKeys {
	bool up, down, left, right;
} InputKeys;

InputKeys getInputKeys(void);

void processInput(void);

#endif // INPUT_H
