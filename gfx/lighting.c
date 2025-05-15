//
// Created by Willam Galvin on 2025-05-14.
//

#include "lighting.h"
#include "../world/map.h"

#include <math.h>
#include <stdio.h>

fVec2D cast_ray(fVec2D starting_pos, float angle, int tile_size) {
    const float d_x = cosf(angle);
    const float d_y = sinf(angle);
    const float map_size = tile_size * MAP_SIZE;

    int tile_x = (int)floor(starting_pos.x / tile_size);
    int tile_y = (int)floor(starting_pos.y / tile_size);

    printf("Player tile: (%i,%i)\n", tile_x, tile_y);
}
