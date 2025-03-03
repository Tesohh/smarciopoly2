#ifndef UTILS_H
#define UTILS_H

#include "raylib/raylib.h"

Rectangle RotateRectangle(Rectangle rectangle, float rotation);
void DebugRectangle(Rectangle r, const char* prefix);

#endif
