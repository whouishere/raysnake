#include "raylib.h"

#include "drawing.h"
#include "game.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

// used for emscripten integration
void UpdateDrawFrame(void) {
	update();
	draw();
}

int main(void) {
	InitWindow(WIN_SIZE, WIN_SIZE, "RaySnake");

	#if !DEBUG
	SetTraceLogLevel(LOG_NONE);
	#endif

	init();

#if defined(PLATFORM_WEB)
	// browsers don't like blocking loops that much...
	emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
	// desktop specific window setup
	int current_monitor = GetCurrentMonitor();
	SetWindowPosition((GetMonitorWidth(current_monitor) / 2) - (WIN_SIZE / 2), 
					  (GetMonitorHeight(current_monitor) / 2) - (WIN_SIZE / 2));
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		// main loop
		UpdateDrawFrame();
	}
#endif

	CloseWindow();
	return 0;
}
