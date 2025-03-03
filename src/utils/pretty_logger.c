#include "raylib/raylib.h"
#include "utils.h"
#include <stdio.h>
void PrettyLogCallback(int msgType, const char* text, va_list args) {
    switch (msgType) {
    case LOG_INFO:
        printf("\e[1;32m[INFO]\e[0m : ");
        break;
    case LOG_ERROR:
        printf("\e[1;31m[ERROR]\e[0m: ");
        break;
    case LOG_WARNING:
        printf("\e[1;33m[WARN]\e[0m : ");
        break;
    case LOG_DEBUG:
        printf("[DEBUG]: ");
        break;
    default:
        break;
    }

    vprintf(text, args);
    printf("\n");
}
