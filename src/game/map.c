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
        {.sprite_name = "large_go.png", .name = "VIA", .type = TileTypeStart, .zone = TileZoneNone},
        {.sprite_name = "baraccopoli.png",
         .name = "Baraccopoli",
         .name_font_size = 95,
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneSmarcio,
         .name_rect_bgcolor = 0x2D9CDBFF},
        {.sprite_name = "ecomostro.png",
         .name = "Ecomostro",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneSmarcio,
         .name_rect_bgcolor = 0x2D9CDBFF},
        {.sprite_name = "viadeimulini16.png",
         .name = "Via dei\nMulini 16",
         .name_font_size = 100,
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneSmarcio,
         .name_rect_bgcolor = 0x2D9CDBFF},
        {.sprite_name = "station.png",
         .name = "Stazione\nCasanova",
         .name_font_size = 90,
         .type = TileTypeStation,
         .cost = 0,
         .zone = TileZoneNone,
         .hide_borders = true,
         .name_text_color = 0x000000FF},
        {.sprite_name = "k21.png",
         .name = "K21",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneRestaurants,
         .name_rect_bgcolor = 0xFF2424FF},
        {.sprite_name = "chickenhut.png",
         .name = "Chicken Hut",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneRestaurants,
         .name_rect_bgcolor = 0xFF2424FF,
         .name_font_size = 90},
        {.sprite_name = "kebz.png",
         .name = "KeBZ",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneRestaurants,
         .name_rect_bgcolor = 0xFF2424FF},

        {.sprite_name = "large_go.png", .name = "VIA", .type = TileTypeStart, .zone = TileZoneNone},
        {.sprite_name = "probability.png",
         .name = "Probabilita",
         .type = TileTypeProbability,
         .cost = 0,
         .zone = TileZoneNone,
         .bgcolor = 0xF2994AFF,
         .hide_borders = true,
         .hide_cost = true,
         .name_text_color = 0x000000FF},
        {.sprite_name = "acquarena.png",
         .name = "Acquarena",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneBrixen,
         .name_rect_bgcolor = 0x1F6008FF},
        {.sprite_name = "acquarena.png",
         .name = "Acquarena",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneBrixen,
         .name_rect_bgcolor = 0x1F6008FF},
        {.sprite_name = "station.png",
         .name = "Stazione\nBrixtown",
         .name_font_size = 90,
         .type = TileTypeStation,
         .cost = 0,
         .zone = TileZoneNone,
         .hide_borders = true,
         .name_text_color = 0x000000FF},
        {.sprite_name = "max.png",
         .name = "Max",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneClubs,
         .name_rect_bgcolor = 0xE82ED5FF},
        {.sprite_name = "life.png",
         .name = "Life",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneClubs,
         .name_rect_bgcolor = 0xE82ED5FF},
        {.sprite_name = "baila.png",
         .name = "Baila",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneClubs,
         .name_rect_bgcolor = 0xE82ED5FF},

        {.sprite_name = "large_go.png", .name = "VIA", .type = TileTypeStart, .zone = TileZoneNone},
        {.sprite_name = "talvera.png",
         .name = "Talvera",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneBolzanoCity,
         .name_rect_bgcolor = 0xFFE500FF,
         .name_text_color = 0x000000FF},
        {.sprite_name = "yogurteria.png",
         .name = "Yogurteria",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneBolzanoCity,
         .name_rect_bgcolor = 0xFFE500FF,
         .name_text_color = 0x000000FF},
        {.sprite_name = "stationpark.png",
         .name = "Parco\nStazione",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneBolzanoCity,
         .name_rect_bgcolor = 0xFFE500FF,
         .name_text_color = 0x000000FF},
        {.sprite_name = "station.png",
         .name = "Stazione\nBolzano Sud",
         .name_font_size = 90,
         .type = TileTypeStation,
         .cost = 0,
         .zone = TileZoneNone,
         .hide_borders = true,
         .name_text_color = 0x000000FF},
        {.sprite_name = "chance.png",
         .name = "Chance",
         .type = TileTypeChance,
         .cost = 0,
         .zone = TileZoneNone,
         .bgcolor = 0x2F80EDFF,
         .hide_borders = true,
         .hide_cost = true,
         .name_text_color = 0x000000FF},
        {.sprite_name = "twenty.png",
         .name = "Twenty",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneIndustry,
         .name_rect_bgcolor = 0xFA7601FF},
        {.sprite_name = "noi.png",
         .name = "NOI",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneIndustry,
         .name_rect_bgcolor = 0xFA7601FF},

        {.sprite_name = "large_go.png", .name = "VIA", .type = TileTypeStart, .zone = TileZoneNone},
        {.sprite_name = "baita.png",
         .name = "Baita",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneOutskirts,
         .name_rect_bgcolor = 0xAEE70CFF,
         .name_text_color = 0x000000FF},
        {.sprite_name = "bronzolo.png",
         .name = "Bronzolo",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneOutskirts,
         .name_rect_bgcolor = 0xAEE70CFF,
         .name_text_color = 0x000000FF},
        {.sprite_name = "probability.png",
         .name = "Probability",
         .type = TileTypeProbability,
         .cost = 0,
         .zone = TileZoneNone,
         .bgcolor = 0xF2994AFF,
         .hide_borders = true,
         .hide_cost = true,
         .name_text_color = 0x000000FF},
        {.sprite_name = "station.png",
         .name = "Stazione\nFortezza",
         .name_font_size = 90,
         .type = TileTypeStation,
         .cost = 0,
         .zone = TileZoneNone,
         .hide_borders = true,
         .name_text_color = 0x000000FF},
        {.sprite_name = "mino.png",
         .name = "Mino",
         .type = TileTypeProperty,
         .cost = 0,
         .zone = TileZoneLuxury,
         .name_rect_bgcolor = 0x703BA1FF},
        {.sprite_name = "chance.png",
         .name = "Chance",
         .type = TileTypeChance,
         .cost = 0,
         .zone = TileZoneNone,
         .bgcolor = 0x2F80EDFF,
         .hide_borders = true,
         .hide_cost = true,
         .name_text_color = 0x000000FF},
        {.sprite_name = "rikilento.png",
         .name = "Rikilento",
         .type = TileTypeProperty,
         .cost = 100,
         .zone = TileZoneLuxury,
         .name_rect_bgcolor = 0x703BA1FF}};

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
