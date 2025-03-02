#ifndef MAP_H
#define MAP_H
#include "tile.h"
typedef struct {
    Tile* tiles;
} Map;

Map Map_new(void);
void Map_destroy(Map*);
#endif
