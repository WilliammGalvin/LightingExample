//
// Created by Willam Galvin on 2025-05-14.
//

#ifndef RENDERER_H
#define RENDERER_H

#include <GLFW/glfw3.h>
#include "../entity/player.h"

typedef struct Renderer {
    GLFWwindow* window;
} Renderer;

void render_player(Player* player);

void render_map(Player* player, bool* player_loaded, int tile_size);

#endif //RENDERER_H
