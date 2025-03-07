#include "raylib/raylib.h"
#include "ui.h"

void ImageDrawCenteredText(Image* img, Rectangle rect, const char* str, Font font, float fontSize, Color tint) {
    Vector2 size = MeasureTextEx(font, str, fontSize, DEFAULT_FONT_SPACING);
    float x = rect.width / 2 - size.x / 2 + rect.x;
    float y = rect.height / 2 - size.y / 2 + rect.y;

    ImageDrawTextEx(img, font, str, (Vector2){x, y}, fontSize, DEFAULT_FONT_SPACING, tint);
}

void ImageDrawVerticallyCenteredText(Image* img, Rectangle rect, float x, const char* str, Font font, float fontSize,
                                     Color tint) {
    Vector2 size = MeasureTextEx(font, str, fontSize, DEFAULT_FONT_SPACING);
    float y = rect.height / 2 - size.y / 2 + rect.y;

    ImageDrawTextEx(img, font, str, (Vector2){x, y}, fontSize, DEFAULT_FONT_SPACING, tint);
}

void ImageDrawHorizontallyCenteredText(Image* img, Rectangle rect, float y, const char* str, Font font, float fontSize,
                                       Color tint) {
    Vector2 size = MeasureTextEx(font, str, fontSize, DEFAULT_FONT_SPACING);
    float x = (rect.width / 2 - size.x / 2) + rect.x;

    ImageDrawTextEx(img, font, str, (Vector2){x, y}, fontSize, DEFAULT_FONT_SPACING, tint);
}
