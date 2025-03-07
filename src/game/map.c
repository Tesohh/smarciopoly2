#include "game.h"
#include "tile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Map Map_new(void) {

    Map map = {0};
    map.tiles = malloc(sizeof(Tile) * GAME_TILE_COUNT);

    TileProps props[GAME_TILE_COUNT] = {
        {.sprite_name = "resources/tiles/start.png", .type = TileTypeStart, .cost = 0, .zone = TileZoneNone},
        {.sprite_name = "resources/tiles/baraccopoli.png",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneSmarcio},
        {.sprite_name = "resources/tiles/ecomostro.png", .type = TileTypeProperty, .cost = 0, .zone = TileZoneSmarcio},
        {.sprite_name = "resources/tiles/viadeimulini.png",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneSmarcio},
        {.sprite_name = "resources/tiles/casanova.png", .type = TileTypeProperty, .cost = 0, .zone = TileZoneNone},
        {.sprite_name = "resources/tiles/k21.png", .type = TileTypeProperty, .cost = 0, .zone = TileZoneRestaurants},
        {.sprite_name = "resources/tiles/chickenhut.png",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneRestaurants},
        {.sprite_name = "resources/tiles/kebz.png", .type = TileTypeProperty, .cost = 0, .zone = TileZoneRestaurants},

        {.sprite_name = "resources/tiles/prison.png", .type = TileTypePrison, .cost = 0, .zone = TileZoneNone},
        {.sprite_name = "resources/tiles/probability.png",
         .type = TileTypeProbability,
         .cost = 0,
         .zone = TileZoneNone},
        {.sprite_name = "resources/tiles/acquarena.png", .type = TileTypeProperty, .cost = 0, .zone = TileZoneBrixen},
        {.sprite_name = "resources/tiles/acquarena.png", .type = TileTypeProperty, .cost = 0, .zone = TileZoneBrixen},
        {.sprite_name = "resources/tiles/bolzanosud.png", .type = TileTypeProperty, .cost = 0, .zone = TileZoneNone},
        {.sprite_name = "resources/tiles/max.png", .type = TileTypeProperty, .cost = 0, .zone = TileZoneClubs},
        {.sprite_name = "resources/tiles/life.png", .type = TileTypeProperty, .cost = 0, .zone = TileZoneClubs},
        {.sprite_name = "resources/tiles/baila.png", .type = TileTypeProperty, .cost = 0, .zone = TileZoneClubs},

        {.sprite_name = "resources/tiles/awards.png", .type = TileTypeAwards, .cost = 0, .zone = TileZoneNone},
        {.sprite_name = "resources/tiles/talvera.png",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneBolzanoCity},
        {.sprite_name = "resources/tiles/yogurteria.png",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneBolzanoCity},
        {.sprite_name = "resources/tiles/stationpark.png",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneBolzanoCity},
        {.sprite_name = "resources/tiles/brixtown.png", .type = TileTypeProperty, .cost = 0, .zone = TileZoneNone},
        {.sprite_name = "resources/tiles/chance.png", .type = TileTypeChance, .cost = 0, .zone = TileZoneNone},
        {.sprite_name = "resources/tiles/twenty.png", .type = TileTypeProperty, .cost = 0, .zone = TileZoneIndustry},
        {.sprite_name = "resources/tiles/noi.png", .type = TileTypeProperty, .cost = 0, .zone = TileZoneIndustry},

        {.sprite_name = "resources/tiles/police.png", .type = TileTypePolice, .cost = 0, .zone = TileZoneNone},
        {.sprite_name = "resources/tiles/baita.png", .type = TileTypeProperty, .cost = 0, .zone = TileZoneOutskirts},
        {.sprite_name = "resources/tiles/bronzolo.png", .type = TileTypeProperty, .cost = 0, .zone = TileZoneOutskirts},
        {.sprite_name = "resources/tiles/probability.png",
         .type = TileTypeProbability,
         .cost = 0,
         .zone = TileZoneNone},
        {.sprite_name = "resources/tiles/fortezza.png", .type = TileTypeProperty, .cost = 0, .zone = TileZoneNone},
        {.sprite_name = "resources/tiles/mino.png", .type = TileTypeProperty, .cost = 0, .zone = TileZoneLuxury},
        {.sprite_name = "resources/tiles/chance.png", .type = TileTypeChance, .cost = 0, .zone = TileZoneNone},
        {.sprite_name = "resources/tiles/rikilento.png",
         .type = TileTypeProperty,
         .cost = 100,
         .zone = TileZoneLuxury}};

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
