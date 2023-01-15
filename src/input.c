#include "input.h"

static InputKeys keys;

InputKeys getInputKeys(void) {
	return keys;
}

void processInput(void) {
	keys.up    = IsKeyDown(KEY_UP);
	keys.down  = IsKeyDown(KEY_DOWN);
	keys.left  = IsKeyDown(KEY_LEFT);
	keys.right = IsKeyDown(KEY_RIGHT);
}
