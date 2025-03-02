#include "tile.h"
#include "game.h"
#include "raylib/raylib.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
    int rotation;
} TilePosition;

TilePosition _get_tile_pos(int i) {
    int row, col;
    TilePosition pos;

    if (i < 8) { // Top row (left to right)
        col = 8 - i;
        row = 8;
        pos.rotation = 0;
    } else if (i < 16) { // Left column (top to bottom)
        col = 0;
        row = 15 - i;
        pos.rotation = 90;
    } else if (i < 24) { // Bottom row (right to left)
        col = i - 16;
        row = 0;
        pos.rotation = 180;
    } else { // Right column (bottom to top)
        col = 8;
        row = i - 24;
        pos.rotation = 270;
    }

    pos.x = (TILE_WIDTH * col) + TILE_WIDTH - BORDER_OVERHANG;
    pos.y = (TILE_WIDTH * row) + TILE_WIDTH - BORDER_OVERHANG;

    return pos;
}

Tile Tile_new(TileProps props, int i) {
    TilePosition pos = _get_tile_pos(i);
    Tile tile = (Tile){.sprite = LoadImage(props.sprite_path),
                       .pos.x = pos.x,
                       .pos.y = pos.y,
                       .rotation = pos.rotation,
                       .cost = props.cost,
                       .zone = (char*)props.zone};

    return tile;
}

void Tile_destroy(Tile* tile) { UnloadImage(tile->sprite); }
