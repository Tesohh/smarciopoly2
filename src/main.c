#include "game/game.h"
#include <stdio.h>

int main(void) {
    Map map = Map_new();

    Map_destroy(&map);
    return 0;
}
