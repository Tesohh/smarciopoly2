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

typedef struct {
    Vector2 pos;
    uint32_t rotation;
    Image sprite;

    TileType tile_type;

    uint32_t cost;
    char* zone;
} Tile;

typedef struct {
    const char* sprite_path;
    TileType type;
    uint32_t cost;
    const char* zone;
} TileProps;

Tile Tile_new(TileProps, int);
void Tile_destroy(Tile*);
void Tile_draw(void);
void Tile_debug(void);
#endif
