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

#ifndef INPUT_H
#define INPUT_H

#include "raylib.h"

#include <stdbool.h>

// input keys booleans
typedef struct InputKeys {
	bool up, down, left, right;
} InputKeys;

InputKeys getInputKeys(void);

void processInput(void);

#endif // INPUT_H
