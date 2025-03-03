#ifndef TILE_H
#define TILE_H
#include "raylib/raylib.h"
#include <stdint.h>
#define BORDER_OVERHANG 8 // extra border in each direction

#define TILE_WIDTH 392  // without 2 * BORDER_OVERHANG
#define TILE_HEIGHT 784 // without 2 * BORDER_OVERHANG

typedef enum {
    TileTypeStart,
    TileTypeProperty,
    TileTypePrison,
    TileTypeAwards,
    TileTypePolice,
    TileTypeChance,
    TileTypeProbability
} TileType;

typedef enum {
    TileZoneNone,
    TileZoneSmarcio,
    TileZoneRestaurants,
    TileZoneBrixen,
    TileZoneClubs,
    TileZoneBolzanoCity,
    TileZoneIndustry,
    TileZoneOutskirts,
    TileZoneLuxury,
} TileZone;

typedef struct {
    Rectangle rect;
    uint32_t rotation;
    Image sprite;

    TileType tile_type;

    uint32_t cost;
    TileZone zone;

    // Generated fields
    Texture texture;
} Tile;

typedef struct {
    const char* sprite_path;
    TileType type;
    uint32_t cost;
    TileZone zone;
} TileProps;

Tile Tile_new(TileProps, int);
void Tile_destroy(Tile*);
void Tile_draw(Tile*);
void Tile_update_texture(Tile*);
void Tile_debug(void);
#endif
