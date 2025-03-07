#include "raylib/raylib.h"
#include "ui.h"

void DrawCenteredText(Rectangle rect, const char* str, Font font, float fontSize, Color tint) {
    Vector2 size = MeasureTextEx(font, str, fontSize, DEFAULT_FONT_SPACING);
    float x = rect.width / 2 - size.x / 2 + rect.x;
    float y = rect.height / 2 - size.y / 2 + rect.y;

    DrawTextEx(font, str, (Vector2){x, y}, fontSize, DEFAULT_FONT_SPACING, tint);
}

void DrawVerticallyCenteredText(Rectangle rect, float x, const char* str, Font font, float fontSize, Color tint) {
    Vector2 size = MeasureTextEx(font, str, fontSize, DEFAULT_FONT_SPACING);
    float y = rect.height / 2 - size.y / 2 + rect.y;

    DrawTextEx(font, str, (Vector2){x, y}, fontSize, DEFAULT_FONT_SPACING, tint);
}

void DrawHorizontallyCenteredText(Rectangle rect, float y, const char* str, Font font, float fontSize, Color tint) {
    Vector2 size = MeasureTextEx(font, str, fontSize, DEFAULT_FONT_SPACING);
    float x = (rect.width / 2 - size.x / 2) + rect.x;

    DrawTextEx(font, str, (Vector2){x, y}, fontSize, DEFAULT_FONT_SPACING, tint);
}
