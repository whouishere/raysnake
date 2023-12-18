#include "raylib.h"

#include "drawing.h"
#include "game.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

#if defined(PLATFORM_DESKTOP)
#include "icon.h"
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

#if defined(PLATFORM_DESKTOP)
	// desktop specific window setup
	{
		Image icon = {
			.data = ICON_DATA,
			.width = ICON_WIDTH,
			.height = ICON_HEIGHT,
			.mipmaps = 1,
			.format = ICON_FORMAT
		};
		SetWindowIcon(icon);

		const int current_monitor = GetCurrentMonitor();
		SetWindowPosition((GetMonitorWidth(current_monitor) / 2) - (WIN_SIZE / 2), 
						(GetMonitorHeight(current_monitor) / 2) - (WIN_SIZE / 2));
		SetTargetFPS(60);
	}
#endif

	while (!WindowShouldClose()) {
		// main loop
		UpdateDrawFrame();
	}
#endif

	CloseWindow();
	return 0;
}
