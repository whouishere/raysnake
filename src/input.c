#include "input.h"

#include <stdbool.h>

#include "raylib.h"

static InputKeys keys;

InputKeys getInputKeys(void) {
	return keys;
}

void processInput(void) {
	keys.up    = IsKeyDown(KEY_UP);
	keys.down  = IsKeyDown(KEY_DOWN);
	keys.left  = IsKeyDown(KEY_LEFT);
	keys.right = IsKeyDown(KEY_RIGHT);

	const int gesture = GetGestureDetected();
	switch (gesture) {
		case GESTURE_SWIPE_UP:    keys.up    = true; break;
		case GESTURE_SWIPE_DOWN:  keys.down  = true; break;
		case GESTURE_SWIPE_LEFT:  keys.left  = true; break;
		case GESTURE_SWIPE_RIGHT: keys.right = true; break;
	}
}
