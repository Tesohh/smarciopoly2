#ifndef TILE_H
#define TILE_H
#include "raylib/raylib.h"
#include <stdbool.h>
#include <stdint.h>
#define BORDER_OVERHANG 8 // extra border in each direction

#define TILE_WIDTH 392  // without 2 * BORDER_OVERHANG
#define TILE_HEIGHT 784 // without 2 * BORDER_OVERHANG

#define TILE_PICTURE_WIDTH 340
#define TILE_PICTURE_HEIGHT 400

typedef enum {
    TileTypeStart,
    TileTypeProperty,
    TileTypePrison,
    TileTypeAwards,
    TileTypePolice,
    TileTypeChance,
    TileTypeProbability,
    TileTypeStation,
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

// defines how to render a tile
typedef struct {
    Image sprite;
    Color bgcolor;
    Color name_text_color;
    Color name_rect_bgcolor;
    uint32_t name_font_size;
    bool render_borders;
    bool render_cost;
    bool render_name;
} Picture;

typedef struct {
    Vector2 pos;
    uint32_t rotation;
    Picture picture;

    TileType type;

    const char* name;
    uint32_t cost;
    TileZone zone;

    // Generated fields
    Texture _texture;
    Rectangle _rect;
} Tile;

typedef struct {
    const char* sprite_name;
    TileType type;
    const char* name;
    uint32_t cost;
    TileZone zone;

    uint32_t name_font_size;

    uint32_t bgcolor;
    uint32_t name_rect_bgcolor;
    uint32_t name_text_color;
    bool hide_borders;
    bool hide_cost;
    bool hide_name;
} TileProps;

Tile Tile_new(TileProps, int);
void Tile_destroy(Tile*);
void Tile_draw(Tile*);
void Tile_update_texture(Tile*, bool);
void Tile_debug(void);
#endif
