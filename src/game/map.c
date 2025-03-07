#include "game.h"
#include "tile.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Map Map_new(void) {

    Map map = {0};
    map.tiles = malloc(sizeof(Tile) * GAME_TILE_COUNT);

    TileProps props[GAME_TILE_COUNT] = {
        {.sprite_name = "life.png", .name = "VIA", .type = TileTypeStart, .zone = TileZoneNone},
        {.sprite_name = "baraccopoli.png",
         .name = "Baraccopoli",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneSmarcio},
        {.sprite_name = "ecomostro.png",
         .name = "Ecomostro",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneSmarcio},
        {.sprite_name = "viadeimulini16.png",
         .name = "Via dei Mulini 16",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneSmarcio},
        {.sprite_name = "station.png",
         .name = "Stazione\nCasanova",
         .type = TileTypeStation,
         .cost = 0,
         .zone = TileZoneNone},
        {.sprite_name = "k21.png", .name = "K21", .type = TileTypeProperty, .cost = 0, .zone = TileZoneRestaurants},
        {.sprite_name = "chickenhut.png",
         .name = "Chicken\nHut",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneRestaurants},
        {.sprite_name = "kebz.png", .name = "KeBZ", .type = TileTypeProperty, .cost = 0, .zone = TileZoneRestaurants},

        {.sprite_name = "life.png", .name = "PRIGIONE", .type = TileTypePrison, .zone = TileZoneNone},
        {.sprite_name = "probability.png",
         .name = "Probabilita",
         .type = TileTypeProbability,
         .cost = 0,
         .zone = TileZoneNone,
         .bgcolor = 0xF2994AFF,
         .hide_borders = true,
         .hide_cost = true},
        {.sprite_name = "acquarena.png",
         .name = "Acquarena",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneBrixen},
        {.sprite_name = "acquarena.png",
         .name = "Acquarena",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneBrixen},
        {.sprite_name = "station.png",
         .name = "Stazione\nBolzano Sud",
         .type = TileTypeStation,
         .cost = 0,
         .zone = TileZoneNone},
        {.sprite_name = "max.png", .name = "Max", .type = TileTypeProperty, .cost = 0, .zone = TileZoneClubs},
        {.sprite_name = "life.png", .name = "Life", .type = TileTypeProperty, .cost = 0, .zone = TileZoneClubs},
        {.sprite_name = "baila.png", .name = "Baila", .type = TileTypeProperty, .cost = 0, .zone = TileZoneClubs},

        {.sprite_name = "life.png", .name = "Awards", .type = TileTypeAwards, .cost = 0, .zone = TileZoneNone},
        {.sprite_name = "talvera.png",
         .name = "Talvera",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneBolzanoCity},
        {.sprite_name = "yogurteria.png",
         .name = "Yogurteria",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneBolzanoCity},
        {.sprite_name = "stationpark.png",
         .name = "Parco Stazione",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneBolzanoCity},
        {.sprite_name = "station.png",
         .name = "Stazione\nBrixtown",
         .type = TileTypeStation,
         .cost = 0,
         .zone = TileZoneNone},
        {.sprite_name = "chance.png",
         .name = "Chance",
         .type = TileTypeChance,
         .cost = 0,
         .zone = TileZoneNone,
         .bgcolor = 0x2F80EDFF,
         .hide_borders = true,
         .hide_cost = true},
        {.sprite_name = "twenty.png", .name = "Twenty", .type = TileTypeProperty, .cost = 0, .zone = TileZoneIndustry},
        {.sprite_name = "noi.png", .name = "NOI", .type = TileTypeProperty, .cost = 0, .zone = TileZoneIndustry},

        {.sprite_name = "life.png", .name = "Police", .type = TileTypePolice, .cost = 0, .zone = TileZoneNone},
        {.sprite_name = "baita.png", .name = "Baita", .type = TileTypeProperty, .cost = 0, .zone = TileZoneOutskirts},
        {.sprite_name = "bronzolo.png",
         .name = "Bronzolo",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneOutskirts},
        {.sprite_name = "probability.png",
         .name = "Probability",
         .type = TileTypeProbability,
         .cost = 0,
         .zone = TileZoneNone,
         .bgcolor = 0xF2994AFF,
         .hide_borders = true,
         .hide_cost = true},
        {.sprite_name = "station.png",
         .name = "Stazione\nFortezza",
         .type = TileTypeStation,
         .cost = 0,
         .zone = TileZoneNone},
        {.sprite_name = "mino.png", .name = "Mino", .type = TileTypeProperty, .cost = 0, .zone = TileZoneLuxury},
        {.sprite_name = "chance.png",
         .name = "Chance",
         .type = TileTypeChance,
         .cost = 0,
         .zone = TileZoneNone,
         .bgcolor = 0x2F80EDFF,
         .hide_borders = true,
         .hide_cost = true},
        {.sprite_name = "rikilento.png",
         .name = "Rikilento",
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
