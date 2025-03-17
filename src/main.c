#include "camera/imaxcamera.h"
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

    InitWindow(720, 720, "Smarciopoly");
    InitAudioDevice();

    Game_init();

    game.camera = ImaxCamera_new((Camera2D){0}, NOMINAL_SIZE);
    game.camera.mode = IMAXCAMERA_MODE_DRAMATIC_FOLLOW;
    game.camera.offset = (Vector2){GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    game.camera.zoom = ImaxCamera_GetNormalizedZoom(&game.camera);
    ImaxCamera_Normalize(&game.camera);

    SetTargetFPS(30);
    while (!WindowShouldClose()) {
        if (IsWindowResized())
            ImaxCamera_Normalize(&game.camera);
        ImaxCamera_Update(&game.camera, GetFrameTime());

        if (IsKeyPressed(KEY_DOWN))
            game.camera.target_zoom -= 0.1;
        if (IsKeyPressed(KEY_UP))
            game.camera.target_zoom += 0.1;

        if (IsKeyDown(KEY_W))
            game.camera.target_origin.y -= 50;
        if (IsKeyDown(KEY_A))
            game.camera.target_origin.x -= 50;
        if (IsKeyDown(KEY_S))
            game.camera.target_origin.y += 50;
        if (IsKeyDown(KEY_D))
            game.camera.target_origin.x += 50;

        BeginDrawing();
        BeginMode2D(ImaxCamera_AsCamera2D(&game.camera));
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
