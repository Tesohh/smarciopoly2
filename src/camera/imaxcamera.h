#ifndef IMAXCAMERA_H
#define IMAXCAMERA_H
#include "raylib/raylib.h"

#define CAMERA_MOVE_ACCELERATION 0.8f
#define CAMERA_ZOOM_ACCELERATION 0.8f
#define CAMERA_ROTATION_ACCELERATION 1
#define CAMERA_MOVE_MIN 2
#define CAMERA_ZOOM_MIN 0.5f
#define CAMERA_ROTATION_MIN 0.5f
#define CAMERA_ROTATION_MAX 1.5f
#define CAMERA_DEFAULT_SPEED 10
#define CAMERA_MAP_SIZE 4312

typedef enum {
    IMAXCAMERA_MODE_NORMAL,
    IMAXCAMERA_MODE_DRAMATIC_FOLLOW,
} ImaxCameraMode;

typedef enum {
    IMAXCAMERA_ROTATION_CLOCKWISE = 1,
    IMAXCAMERA_ROTATION_ANTICLOCKWISE,
} ImaxCameraRotation;

typedef struct {
    Vector2 offset; // Camera offset (displacement from origin)
    Vector2 origin; // Camera origin (FORMERLY TARGET) (rotation and zoom origin)
    float rotation; // Camera rotation in degrees
    float zoom;     // Camera zoom (scaling), should be 1.0f by default

    ImaxCameraMode mode;
    Vector2 nominal_size;
    Vector2 scale_factor;
    Vector2 target_origin;
    float target_zoom;
    float target_rotation;
    float speed;
    int current_rotation_direction;
} ImaxCamera;

ImaxCamera ImaxCamera_new(Camera2D cam, Vector2 nominal_size);
float ImaxCamera_GetNormalizedZoom(ImaxCamera*);
void ImaxCamera_Normalize(ImaxCamera*);
void ImaxCamera_Rotate(ImaxCamera*, int direction);
void ImaxCamera_Update(ImaxCamera*, float delta);
Camera2D ImaxCamera_AsCamera2D(ImaxCamera*);
#endif
