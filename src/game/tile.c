#include "tile.h"
#include "../ui/ui.h"
#include "../utils/utils.h"
#include "game.h"
#include "raylib/raylib.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
    int rotation;
    int width;
    int height;
} TilePosition;

TilePosition _get_tile_pos(int i) {
    TilePosition pos = {.width = TILE_WIDTH, .height = TILE_HEIGHT};

    if (i == 0) {
        pos.x = (TILE_WIDTH * 8) + (TILE_WIDTH)-BORDER_OVERHANG;
        pos.y = (TILE_WIDTH * 8) + (TILE_WIDTH)-BORDER_OVERHANG;
        pos.width = TILE_WIDTH * 2;
    } else if (i < 8) { // Top row (left to right)
        pos.x = (TILE_WIDTH * (8 - i)) + TILE_WIDTH - BORDER_OVERHANG;
        pos.y = (TILE_WIDTH * (8)) + TILE_WIDTH - BORDER_OVERHANG;
        pos.rotation = 0;
    } else if (i == 8) {
        // 0 - BORDER_OVERHANG, (TILE_WIDTH * 8) + (TILE_WIDTH)-BORDER_OVERHANG, 0
        pos.x = 0 - BORDER_OVERHANG;
        pos.y = (TILE_WIDTH * 8) + (TILE_WIDTH)-BORDER_OVERHANG;
        pos.width = TILE_WIDTH * 2;
    } else if (i < 16) {
        pos.x = TILE_HEIGHT + BORDER_OVERHANG;
        pos.y = (TILE_WIDTH * (i - 7)) - BORDER_OVERHANG;
        pos.rotation = 90;
    } else if (i == 16) {
        pos.x = 0 - BORDER_OVERHANG;
        pos.y = 0 - BORDER_OVERHANG;
        pos.width = TILE_WIDTH * 2;
    } else if (i < 24) {
        pos.x = (TILE_WIDTH * (i - 16)) + (TILE_WIDTH * 2) + BORDER_OVERHANG;
        pos.y = TILE_HEIGHT + BORDER_OVERHANG;
        pos.rotation = 180;
    } else if (i == 24) {
        pos.x = (TILE_WIDTH * 8) + (TILE_WIDTH)-BORDER_OVERHANG;
        pos.y = 0 - BORDER_OVERHANG;
        pos.width = TILE_WIDTH * 2;
    } else if (i < 32) {
        // (TILE_WIDTH * 8) + (TILE_WIDTH)-BORDER_OVERHANG, (TILE_WIDTH * 1) + (TILE_WIDTH * 2) + BORDER_OVERHANG, 270
        pos.x = (TILE_WIDTH * 8) + (TILE_WIDTH)-BORDER_OVERHANG;
        pos.y = (TILE_WIDTH * (i - 24)) + (TILE_WIDTH * 2) + BORDER_OVERHANG;
        pos.rotation = 270;
    }

    return pos;
}

Tile Tile_new(TileProps props, int i) {
    TilePosition pos = _get_tile_pos(i);
    Rectangle rect;

    rect = (Rectangle){pos.x, pos.y, pos.width, pos.height};
    rect = RotateRectangle(rect, pos.rotation);

    char buf[128] = "resources/tiles/";
    strncat(buf, props.sprite_name, 128 - 1);

    if (props.bgcolor == 0) {
        props.bgcolor = 0xFFFFFFFF;
    }
    if (props.name_font_size == 0) {
        props.name_font_size = 110;
    }

    Picture picture = {.sprite = LoadImage(buf),
                       .bgcolor = GetColor(props.bgcolor),
                       .name_font_size = props.name_font_size,
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

    Tile_update_texture(&tile, i % 8 == 0);

    return tile;
}

void Tile_update_texture(Tile* tile, bool skip_generation) {
    // TODO: use larger width if prison tile
    if (!skip_generation) {
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
            Rectangle border_rect = {28, 28, 340, 180};
            if (tile->picture.render_borders)
                ImageDrawBorderRect(&target, border_rect, BLACK, WHITE, 0);

            int newline_index = -1;
            int len = strlen(tile->name);
            for (int i = 0; i < len; i++) {
                if (tile->name[i] == '\n') {
                    newline_index = i;
                }
            }

            uint32_t font_size = tile->picture.name_font_size;

            if (newline_index == -1) {
                Rectangle name_rect = {24, 28, 330, 180};
                ImageDrawCenteredText(&target, name_rect, tile->name, game.fonts.ui, font_size, BLACK);
            } else {
                Rectangle name_rect_top = {24, 28, 330, 96};
                Rectangle name_rect_bottom = {24, 105, 330, 96};

                char name_str_top[newline_index];
                strncpy(name_str_top, tile->name, newline_index);
                name_str_top[newline_index] = '\0';
                char* name_str_bottom = (char*)tile->name + newline_index + 1;

                ImageDrawCenteredText(&target, name_rect_top, name_str_top, game.fonts.ui, font_size, BLACK);
                ImageDrawCenteredText(&target, name_rect_bottom, name_str_bottom, game.fonts.ui, font_size, BLACK);
            }
        }

        tile->_texture = LoadTextureFromImage(target);

        UnloadImage(target);
    } else {
        tile->_texture = LoadTextureFromImage(tile->picture.sprite);
    }
}

void Tile_draw(Tile* tile) { DrawTextureEx(tile->_texture, tile->pos, tile->rotation, 1.0, WHITE); }

void Tile_destroy(Tile* tile) {
    UnloadTexture(tile->_texture);
    UnloadImage(tile->picture.sprite);
}
