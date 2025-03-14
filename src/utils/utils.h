#ifndef UTILS_H
#define UTILS_H

#include "raylib/raylib.h"

Rectangle RotateRectangle(Rectangle rectangle, float rotation);
void DebugRectangle(Rectangle r, const char* prefix);

void PrettyLogCallback(int msgType, const char* text, va_list args);

Vector2 Vector2_new(int x, int y);

void ColorDebugTraceLog(int log_level, Color color);
#endif
