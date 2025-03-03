#include "game/game.h"
#include "game/map.h"
#include "game/tile.h"
#include "raylib/raylib.h"
#include "utils/utils.h"
#include <stdio.h>

#define NOMINAL_WIDTH MAP_SIZE
#define NOMINAL_HEIGHT MAP_SIZE
#define NOMINAL_SIZE                                                                                                   \
    (Vector2) { NOMINAL_WIDTH, NOMINAL_HEIGHT }

#define MONOPOLY_COLOR GetColor(0xC2FFCCFF)

int main(void) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    SetTraceLogCallback(PrettyLogCallback);

    InitWindow(1080, 720, "Smarciopoly");
    InitAudioDevice();

    Game_init();

    Camera2D camera = {0};
    camera.zoom = 0.1f;
    camera.offset = (Vector2){.x = 200, .y = 200};

    SetTargetFPS(30);
    while (!WindowShouldClose()) {

        BeginDrawing();
        BeginMode2D(camera);
        {
            ClearBackground(MONOPOLY_COLOR);
            // PERF: smerdolox (unefficient background drawing)
            for (int y = -10800; y < 10800; y += game.sprites.bg.height) {
                for (int x = -10800; x < 10800; x += game.sprites.bg.width) {
                    DrawTexture(game.sprites.bg, x, y, WHITE);
                }
            }

            DrawRectangle(0, 0, MAP_SIZE, MAP_SIZE, MONOPOLY_COLOR);
            for (int i = 0; i < GAME_TILE_COUNT; i++) {
                Tile_draw(game.map.tiles + i);
            }
            DrawFPS(0, 0);
        }
        EndMode2D();
        EndDrawing();
    }

    Map_destroy(&game.map);
    TraceLog(LOG_INFO, "Destroyed map");
    return 0;
}
