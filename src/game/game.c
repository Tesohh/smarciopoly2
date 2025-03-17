#include "game.h"
#include "map.h"
#include "raylib/raylib.h"
#include <stdlib.h>

Game game;

void Game_init() {
    game = (Game){0};

    game.fonts.ui = LoadFontEx("resources/fonts/karantina.ttf", 110, 0, 100);
    SetTextureFilter(game.fonts.ui.texture, TEXTURE_FILTER_TRILINEAR);
    game.sounds.bell = LoadSound("resources/sounds/bell.wav");
    game.sprites.bg = LoadTexture("resources/bg.png");

    game.map = Map_new();
}
