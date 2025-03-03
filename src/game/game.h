#ifndef GAME_H
#define GAME_H

#include "map.h"
#include <stdint.h>
#define GAME_TILE_COUNT 32

typedef struct {
    struct {
        Font ui;
    } fonts;

    struct {
        Sound bell;
    } sounds;

    struct {
        Texture2D bg;
    } sprites;

    Map map;
} Game;

void Game_init();

extern Game game;

#endif // !STATE_H
