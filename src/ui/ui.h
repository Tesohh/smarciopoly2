#pragma once

#include "raylib/raylib.h"

#define RECTANGLE_DEFAULT_BORDER 16
#define DEFAULT_FONT_SPACING 1

void DrawBorderRect(Rectangle rect, Color border_color, Color rect_color, int border_width);
void ImageDrawBorderRect(Image* img, Rectangle rect, Color border_color, Color rect_color, int border_width);

void DrawVerticallyCenteredText(Rectangle rect, float x, const char* str, Font font, float fontSize, Color tint);
void DrawHorizontallyCenteredText(Rectangle rect, float y, const char* str, Font font, float fontSize, Color tint);
void DrawCenteredText(Rectangle rect, const char* str, Font font, float fontSize, Color tint);

void ImageDrawVerticallyCenteredText(Image* img, Rectangle rect, float x, const char* str, Font font, float fontSize,
                                     Color tint);
void ImageDrawHorizontallyCenteredText(Image* img, Rectangle rect, float y, const char* str, Font font, float fontSize,
                                       Color tint);
void ImageDrawCenteredText(Image* img, Rectangle rect, const char* str, Font font, float fontSize, Color tint);
