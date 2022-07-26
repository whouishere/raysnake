/* 
  Copyright © 2022 by Willian Vinagre

  This file is part of RaySnake.
  
  RaySnake is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  RaySnake is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with RaySnake. If not, see <https://www.gnu.org/licenses/>.
*/

#include "drawing.h"

int main() {
	InitWindow(WIN_SIZE, WIN_SIZE, "RaySnake");
	int current_monitor = GetCurrentMonitor();
	SetWindowPosition((GetMonitorWidth(current_monitor) / 2) - (WIN_SIZE / 2), 
					  (GetMonitorHeight(current_monitor) / 2) - (WIN_SIZE / 2));
	SetTargetFPS(60);

	init();
	while (!WindowShouldClose()) {
		// main loop
		update();
		draw();
	}
	CloseWindow();

	return 0;
}
