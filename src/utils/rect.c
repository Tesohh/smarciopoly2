#include "raylib/raylib.h"
#include "utils.h"
#include <math.h>

Rectangle RotateRectangle(Rectangle rectangle, float rotation) {
    float rad = rotation * DEG2RAD;
    float cosTheta = cosf(rad);
    float sinTheta = sinf(rad);

    // Top-left corner (original position)
    float x0 = rectangle.x;
    float y0 = rectangle.y;

    // Top-right corner
    float x1 = rectangle.x + rectangle.width * cosTheta;
    float y1 = rectangle.y + rectangle.width * sinTheta;

    // Bottom-left corner
    float x2 = rectangle.x - rectangle.height * sinTheta;
    float y2 = rectangle.y + rectangle.height * cosTheta;

    // Bottom-right corner
    float x3 = x1 - rectangle.height * sinTheta;
    float y3 = y1 + rectangle.height * cosTheta;

    float minX = fminf(fminf(x0, x1), fminf(x2, x3));
    float minY = fminf(fminf(y0, y1), fminf(y2, y3));
    float maxX = fmaxf(fmaxf(x0, x1), fmaxf(x2, x3));
    float maxY = fmaxf(fmaxf(y0, y1), fmaxf(y2, y3));

    float width = maxX - minX;
    float height = maxY - minY;

    Rectangle boundingRect = {roundf(minX), roundf(minY), roundf(width), roundf(height)};
    return boundingRect;
}

void DebugRectangle(Rectangle r, const char* prefix) {
    TraceLog(LOG_INFO, "%s x=%f y=%f width=%f height=%f", prefix, r.x, r.y, r.width, r.height);
}

void PrettyLogCallback(int msgType, const char* text, va_list args);
