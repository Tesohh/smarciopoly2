#include "game.h"
#include "raylib/raylib.h"
#include "tile.h"
#include <stdlib.h>
#include <string.h>

Map Map_new(void) {

    Map map = {0};
    map.tiles = malloc(sizeof(Tile) * GAME_TILE_COUNT);

    TileProps props[GAME_TILE_COUNT] = {
        {.sprite_path = "resources/tiles/start.png", .type = TileTypeStart, .cost = 0, .zone = ""},
        {.sprite_path = "resources/tiles/baraccopoli.png", .type = TileTypeProperty, .cost = 0, .zone = "smarcio"},
        {.sprite_path = "resources/tiles/ecomostro.png", .type = TileTypeProperty, .cost = 0, .zone = "smarcio"},
        {.sprite_path = "resources/tiles/viadeimulini.png", .type = TileTypeProperty, .cost = 0, .zone = "smarcio"},
        {.sprite_path = "resources/tiles/casanova.png", .type = TileTypeProperty, .cost = 0, .zone = ""},
        {.sprite_path = "resources/tiles/k21.png", .type = TileTypeProperty, .cost = 0, .zone = "restaurants"},
        {.sprite_path = "resources/tiles/chickenhut.png", .type = TileTypeProperty, .cost = 0, .zone = "restaurants"},
        {.sprite_path = "resources/tiles/kebz.png", .type = TileTypeProperty, .cost = 0, .zone = "restaurants"},

        {.sprite_path = "resources/tiles/prison.png", .type = TileTypePrison, .cost = 0, .zone = ""},
        {.sprite_path = "resources/tiles/probability.png", .type = TileTypeProbability, .cost = 0, .zone = ""},
        {.sprite_path = "resources/tiles/acquarena.png", .type = TileTypeProperty, .cost = 0, .zone = "brixen"},
        {.sprite_path = "resources/tiles/acquarena.png", .type = TileTypeProperty, .cost = 0, .zone = "brixen"},
        {.sprite_path = "resources/tiles/bolzanosud.png", .type = TileTypeProperty, .cost = 0, .zone = ""},
        {.sprite_path = "resources/tiles/max.png", .type = TileTypeProperty, .cost = 0, .zone = "clubs"},
        {.sprite_path = "resources/tiles/life.png", .type = TileTypeProperty, .cost = 0, .zone = "clubs"},
        {.sprite_path = "resources/tiles/baila.png", .type = TileTypeProperty, .cost = 0, .zone = "clubs"},

        {.sprite_path = "resources/tiles/awards.png", .type = TileTypeAwards, .cost = 0, .zone = ""},
        {.sprite_path = "resources/tiles/talvera.png", .type = TileTypeProperty, .cost = 0, .zone = "bolzanocity"},
        {.sprite_path = "resources/tiles/yogurteria.png", .type = TileTypeProperty, .cost = 0, .zone = "bolzanocity"},
        {.sprite_path = "resources/tiles/stationpark.png", .type = TileTypeProperty, .cost = 0, .zone = "bolzanocity"},
        {.sprite_path = "resources/tiles/brixtown.png", .type = TileTypeProperty, .cost = 0, .zone = ""},
        {.sprite_path = "resources/tiles/chance.png", .type = TileTypeChance, .cost = 0, .zone = ""},
        {.sprite_path = "resources/tiles/twenty.png", .type = TileTypeProperty, .cost = 0, .zone = "industry"},
        {.sprite_path = "resources/tiles/noi.png", .type = TileTypeProperty, .cost = 0, .zone = "industry"},

        {.sprite_path = "resources/tiles/police.png", .type = TileTypePolice, .cost = 0, .zone = ""},
        {.sprite_path = "resources/tiles/baita.png", .type = TileTypeProperty, .cost = 0, .zone = "outskirts"},
        {.sprite_path = "resources/tiles/bronzolo.png", .type = TileTypeProperty, .cost = 0, .zone = "outskirts"},
        {.sprite_path = "resources/tiles/probability.png", .type = TileTypeProbability, .cost = 0, .zone = ""},
        {.sprite_path = "resources/tiles/fortezza.png", .type = TileTypeProperty, .cost = 0, .zone = ""},
        {.sprite_path = "resources/tiles/mino.png", .type = TileTypeProperty, .cost = 0, .zone = "luxury"},
        {.sprite_path = "resources/tiles/chance.png", .type = TileTypeChance, .cost = 0, .zone = ""},
        {.sprite_path = "resources/tiles/rikilento.png", .type = TileTypeProperty, .cost = 100, .zone = "luxury"}};

    for (int i = 0; i < GAME_TILE_COUNT; i++) {
        map.tiles[i] = Tile_new(props[i], i);
    }

    return map;
}

void Map_destroy(Map* map) {
    if (map && map->tiles) {
        for (int i = 0; i < GAME_TILE_COUNT; i++) {
            Tile_destroy(map->tiles + i);
        }
        free(map->tiles);
        map->tiles = NULL;
    }
};
