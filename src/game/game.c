#include "game.h"
#include "map.h"
#include "raylib/raylib.h"
#include "tile.h"
#include <stdlib.h>

Game game;

void Game_init() {
    game = (Game){0};

    game.fonts.ui = LoadFont("resources/fonts/karantina.ttf");
    game.sounds.bell = LoadSound("resources/sounds/bell.wav");
    game.sprites.bg = LoadTexture("resources/bg.png");

    // game.map = Map_new();
    game.map = (Map){0};
    game.map.tiles = malloc(sizeof(Tile) * GAME_TILE_COUNT);
    game.map.tiles[0] = Tile_new((TileProps){.sprite_name = "chance.png",
                                             .name = "Chance",
                                             .type = TileTypeChance,
                                             .cost = 0,
                                             .zone = TileZoneNone,
                                             .bgcolor = 0x2F80EDFF,
                                             .hide_borders = true,
                                             .hide_cost = true},
                                 0);
}
