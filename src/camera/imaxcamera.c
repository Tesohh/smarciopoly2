#include "imaxcamera.h"
#include "raylib/raylib.h"
#include "raylib/raymath.h"

ImaxCamera ImaxCamera_new(Camera2D cam, Vector2 nominal_size) {
    return (ImaxCamera){.offset = cam.offset,
                        .origin = cam.target,
                        .rotation = cam.rotation,
                        .zoom = cam.zoom,
                        .nominal_size = nominal_size,
                        .target_zoom = cam.zoom,
                        .speed = CAMERA_DEFAULT_SPEED};
}

float ImaxCamera_GetNormalizedZoom(ImaxCamera* cam) {
    Vector2 actual_size = {(float)GetScreenWidth(), (float)GetScreenHeight()};

    cam->scale_factor.x = actual_size.x / (cam->scale_factor.x);
    cam->scale_factor.y = actual_size.y / (cam->nominal_size.y);

    if (actual_size.x > actual_size.y)
        return cam->scale_factor.y;
    else
        return cam->scale_factor.x;
}

void ImaxCamera_Normalize(ImaxCamera* cam) {
    cam->speed = 20;

    Vector2 mapCenter = (Vector2){CAMERA_MAP_SIZE / 2.0f, CAMERA_MAP_SIZE / 2.0f};
    Vector2 screenCenter = (Vector2){GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};

    cam->offset = screenCenter;
    cam->target_origin = mapCenter;

    cam->target_zoom = ImaxCamera_GetNormalizedZoom(cam);
}

void ImaxCamera_Rotate(ImaxCamera* cam, int direction) {
    switch (direction) {
    case IMAXCAMERA_ROTATION_CLOCKWISE:
        cam->current_rotation_direction = IMAXCAMERA_ROTATION_CLOCKWISE;
        cam->target_rotation += 90;
        break;
    case IMAXCAMERA_ROTATION_ANTICLOCKWISE:
        cam->current_rotation_direction = IMAXCAMERA_ROTATION_ANTICLOCKWISE;
        cam->target_rotation -= 90;
        break;
    default:
        cam->current_rotation_direction = 0;
        break;
    }
}

void ImaxCamera_Update(ImaxCamera* cam, float delta) {
    switch (cam->mode) {
    case IMAXCAMERA_MODE_NORMAL:
        break;
    case IMAXCAMERA_MODE_DRAMATIC_FOLLOW:
        // THE MYSTERIOUS SEMICOLON...
        ;
        Vector2 pos_diff = Vector2Subtract(cam->target_origin, cam->origin);
        float pos_distance = Vector2Length(pos_diff);

        float zoom_diff = cam->target_zoom - cam->zoom;
        float rot_diff = cam->target_rotation - cam->rotation;

        if (pos_distance > 0) {
            float pos_speed = fmaxf(CAMERA_MOVE_ACCELERATION * pos_distance, CAMERA_MOVE_MIN) * delta * cam->speed;
            cam->origin = Vector2Add(cam->origin, Vector2Scale(pos_diff, pos_speed / pos_distance));
            if (pos_distance < 1)
                cam->origin = cam->target_origin;
        }

        if (zoom_diff != 0) {
            float zoom_speed = fmaxf(CAMERA_ZOOM_ACCELERATION * zoom_diff, CAMERA_ZOOM_MIN) * delta * cam->speed;
            cam->zoom += zoom_diff * zoom_speed;
        }

        // TODO: Figure out why rotating CLOCKWISE makes the camera kind of turn twice
        // my guess is it has something to do with the fact that rotDiff is negative or positive
        // after the animation the camera is in the right rotation but it still looks weird you know
        if (rot_diff != 0) {
            float rot_speed =
                Clamp((CAMERA_ROTATION_ACCELERATION * rot_diff) / 100, CAMERA_ROTATION_MIN, CAMERA_ROTATION_MAX) *
                delta * cam->speed;
            cam->rotation += rot_diff * rot_speed;
        }
        break;
    }
}

Camera2D ImaxCamera_AsCamera2D(ImaxCamera* cam) {
    return (Camera2D){
        .offset = cam->offset,
        .target = cam->origin,
        .rotation = cam->rotation,
        .zoom = cam->zoom,
    };
}
