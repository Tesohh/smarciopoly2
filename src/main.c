#include "game/game.h"
#include "game/map.h"
#include "raylib/raylib.h"
#include <stdio.h>

int main(void) {
    TraceLog(LOG_INFO, "Making map..");
    Map map = Map_new();
    TraceLog(LOG_INFO, "Initialized new map");

    Map_destroy(&map);
    return 0;
}
