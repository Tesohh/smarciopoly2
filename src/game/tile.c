#include "tile.h"
#include "../utils/utils.h"
#include "raylib/raylib.h"
#include <stdint.h>
#include <stdio.h>
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
    Rectangle rect;

    switch (props.type) {
    case TileTypeStart:
    case TileTypePrison:
    case TileTypeAwards:
    case TileTypePolice:
        rect = (Rectangle){pos.x, pos.y, TILE_WIDTH * 2, TILE_HEIGHT};
        break;
    case TileTypeProperty:
    case TileTypeChance:
    case TileTypeProbability:
        rect = (Rectangle){pos.x, pos.y, TILE_WIDTH, TILE_HEIGHT};
        break;
    }

    rect = RotateRectangle(rect, pos.rotation);

    Tile tile = (Tile){.sprite = LoadImage(props.sprite_path),
                       .rect = rect,
                       .rotation = pos.rotation,
                       .cost = props.cost,
                       .zone = props.zone};

    Tile_update_texture(&tile);

    return tile;
}

void Tile_update_texture(Tile* tile) {
    // PERF: image and texture should be unlaoded
    Image editedImage = ImageCopy(tile->sprite);

    if (tile->tile_type == TileTypeProperty) {
        char str[64] = "$";
        sprintf(str + 1, "%d", tile->cost); // crazy cantarella-esque wizardry

        int textWidth = MeasureTextEx(GetFontDefault(), str, 110, 0).x;
        int textX = editedImage.width / 2 - textWidth / 2;

        ImageDrawTextEx(&editedImage, GetFontDefault(), str, (Vector2){(float)textX, 650}, 110, 0, BLACK);
    }

    tile->texture = LoadTextureFromImage(editedImage);
    SetTextureFilter(tile->texture, TEXTURE_FILTER_BILINEAR);
}

void Tile_draw(Tile* tile) {
    DrawTextureEx(tile->texture, (Vector2){.x = tile->rect.x, .y = tile->rect.y}, tile->rotation, 1.0, WHITE);
}

void Tile_destroy(Tile* tile) { UnloadImage(tile->sprite); }
