#include "tile.h"
#include "../ui/ui.h"
#include "../utils/utils.h"
#include "game.h"
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
    TilePosition pos = {0};

    if (i < 8) { // Top row (left to right)
        pos.x = (TILE_WIDTH * (8 - i)) + TILE_WIDTH - BORDER_OVERHANG;
        pos.y = (TILE_WIDTH * (8)) + TILE_WIDTH - BORDER_OVERHANG;
        pos.rotation = 0;
    } else if (i < 16) {
        pos.x = TILE_HEIGHT + BORDER_OVERHANG;
        pos.y = (TILE_WIDTH * (i - 7)) - BORDER_OVERHANG;
        pos.rotation = 90;
    } else if (i < 24) {
        pos.x = (TILE_WIDTH * (i - 15)) + (TILE_WIDTH * 2) + BORDER_OVERHANG;
        pos.y = TILE_HEIGHT + BORDER_OVERHANG;
        pos.rotation = 180;
    } else if (i < 32) {
        // (TILE_WIDTH * 8) + (TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH * 1) + (TILE_WIDTH * 2) + BORDER_OVERHANG, 270
        pos.x = (TILE_WIDTH * 8) + (TILE_WIDTH)-BORDER_OVERHANG;
        pos.y = (TILE_WIDTH * (i - 23)) + (TILE_WIDTH * 2) + BORDER_OVERHANG;
        pos.rotation = 270;
    }

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
    case TileTypeStation:
        rect = (Rectangle){pos.x, pos.y, TILE_WIDTH, TILE_HEIGHT};
        break;
    }

    rect = RotateRectangle(rect, pos.rotation);

    char buf[128] = "resources/tiles/";
    strncat(buf, props.sprite_name, 128 - 1);

    if (props.bgcolor == 0) {
        props.bgcolor = 0xFFFFFFFF;
    }

    Picture picture = {.sprite = LoadImage(buf),
                       .bgcolor = GetColor(props.bgcolor),
                       .render_borders = !props.hide_borders,
                       .render_cost = !props.hide_cost,
                       .render_name = !props.hide_name};

    Tile tile = (Tile){.picture = picture,
                       .pos = Vector2_new(pos.x, pos.y),
                       .rotation = pos.rotation,
                       .cost = props.cost,
                       .zone = props.zone,
                       .name = props.name,
                       ._rect = rect};

    Tile_update_texture(&tile);

    return tile;
}

void Tile_update_texture(Tile* tile) {
    // TODO: use larger width if prison tile
    ColorDebugTraceLog(LOG_INFO, tile->picture.bgcolor);
    Image target = GenImageColor(TILE_WIDTH, TILE_HEIGHT, tile->picture.bgcolor);
    ImageDrawBorderRect(&target, (Rectangle){0, 0, TILE_WIDTH, TILE_HEIGHT}, BLACK, tile->picture.bgcolor, 16);

    Rectangle src_rect = {0, 0, TILE_PICTURE_WIDTH, TILE_PICTURE_HEIGHT};
    Rectangle dest_rect = {28 + 16, 232 + 16, TILE_PICTURE_WIDTH - 32, TILE_PICTURE_HEIGHT - 32};

    if (tile->picture.render_borders) {
        Rectangle bg_rect = {28, 232, TILE_PICTURE_WIDTH, TILE_PICTURE_HEIGHT};
        ImageDrawRectangleRec(&target, bg_rect, BLACK);
    }
    ImageDraw(&target, tile->picture.sprite, src_rect, dest_rect, WHITE);

    if (tile->picture.render_cost) {
        char cost_str[64] = "$";
        sprintf(cost_str + 1, "%d", tile->cost);

        Rectangle cost_rect = {28, 656, 340, 100};
        ImageDrawBorderRect(&target, cost_rect, BLACK, WHITE, 0);
        ImageDrawHorizontallyCenteredText(&target, cost_rect, 680, cost_str, game.fonts.ui, 110, BLACK);
    }

    if (tile->picture.render_name) {
        Rectangle name_rect = {28, 28, 340, 180};
        if (tile->picture.render_borders)
            ImageDrawBorderRect(&target, name_rect, BLACK, WHITE, 0);
        ImageDrawCenteredText(&target, name_rect, tile->name, game.fonts.ui, 110, BLACK);
    }

    tile->_texture = LoadTextureFromImage(target);

    UnloadImage(target);
}

void Tile_draw(Tile* tile) { DrawTextureEx(tile->_texture, tile->pos, tile->rotation, 1.0, WHITE); }

void Tile_destroy(Tile* tile) {
    UnloadTexture(tile->_texture);
    UnloadImage(tile->picture.sprite);
}
