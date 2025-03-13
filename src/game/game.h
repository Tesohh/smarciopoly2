#ifndef GAME_H
#define GAME_H

#include "../camera/imaxcamera.h"
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
    ImaxCamera camera;
} Game;

void Game_init();

extern Game game;

#endif // !STATE_H
