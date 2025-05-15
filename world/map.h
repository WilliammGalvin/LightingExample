//
// Created by Willam Galvin on 2025-05-14.
//

#ifndef MAP_H
#define MAP_H

#define MAP_SIZE 8

static const int MAP_DATA[] = {
    1, 1, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 2, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};

typedef struct MapRenderData {
    int tile_size;
    float screen_buffer;
} MapRenderData;

MapRenderData get_map_render_data(int screen_size);

#endif //MAP_H
