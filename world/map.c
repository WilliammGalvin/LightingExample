//
// Created by Willam Galvin on 2025-05-14.
//

#include "map.h"

#include <math.h>

MapRenderData get_map_render_data(int screen_size) {
    const double tile_size_d = floor(screen_size / MAP_SIZE);
    const float buffer = screen_size - tile_size_d * MAP_SIZE;
    const MapRenderData data = { (int) tile_size_d, buffer / 2.0f };
    return data;
}
