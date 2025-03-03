#include "game.h"
#include "map.h"
#include "raylib/raylib.h"

Game game;

void Game_init() {
    game = (Game){0};

    game.fonts.ui = LoadFont("resources/fonts/karantina.ttf");
    game.sounds.bell = LoadSound("resources/sounds/bell.wav");
    game.sprites.bg = LoadTexture("resources/bg.png");

    game.map = Map_new();
}
