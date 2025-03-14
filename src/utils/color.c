#include "raylib/raylib.h"
void ColorDebugTraceLog(int log_level, Color color) {
    TraceLog(log_level, "\033[48;2;%d;%d;%dm\033[38;2;255;255;255m#%02x%02x%02x%02x\033[0m", color.r, color.g, color.b,
             color.r, color.g, color.b, color.a);
}
