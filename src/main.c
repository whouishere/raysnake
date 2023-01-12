#include "raylib.h"

#include "drawing.h"
#include "game.h"

int main(void) {
	InitWindow(WIN_SIZE, WIN_SIZE, "RaySnake");
	int current_monitor = GetCurrentMonitor();
	SetWindowPosition((GetMonitorWidth(current_monitor) / 2) - (WIN_SIZE / 2), 
					  (GetMonitorHeight(current_monitor) / 2) - (WIN_SIZE / 2));
	SetTargetFPS(60);

	#if !DEBUG
	SetTraceLogLevel(LOG_NONE);
	#endif
	
	init();
	while (!WindowShouldClose()) {
		// main loop
		update();
		draw();
	}
	CloseWindow();

	return 0;
}
