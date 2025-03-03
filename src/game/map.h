#ifndef MAP_H
#define MAP_H
#include "tile.h"
#define MAP_SIZE 4312

typedef struct {
    Tile* tiles;
} Map;

Map Map_new(void);
void Map_destroy(Map*);
#endif
