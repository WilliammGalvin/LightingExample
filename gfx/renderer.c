//
// Created by Willam Galvin on 2025-05-14.
//

#include "renderer.h"

#include <math.h>

#include "../entity/player.h"
#include "../util/angle_util.h"
#include "../world/map.h"

const bool TESTING_GRID = true;

void render_player(Player* player) {
    const float half_size = PLAYER_SIZE / 2.0f;
    glColor3f(1.0f, 1.0f, 1.0f);

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glVertex2f(player->pos.x, player->pos.y);
    glVertex2f(
        player->pos.x + player->d_x * 15.0f,
        player->pos.y + player->d_y * 15.0f
    );
    glEnd();

    glPushMatrix();
    glTranslatef(player->pos.x, player->pos.y, 0.0f);
    glRotatef(rad_to_deg(player->angle), 0.0f, 0.0f, 1.0f);

    glBegin(GL_QUADS);
    glVertex2f(-half_size, -half_size);
    glVertex2f(half_size, -half_size);
    glVertex2f(half_size, half_size);
    glVertex2f(-half_size, half_size);
    glEnd();

    glPopMatrix();
}

void render_map(Player* player, bool* player_loaded, int tile_size) {
    for (size_t y = 0; y < MAP_SIZE; y++) {
        for (size_t x = 0; x < MAP_SIZE; x++) {
            const int id = MAP_DATA[y * MAP_SIZE + x];
            const int tile_x = x * tile_size;
            const int tile_y = y * tile_size;

            if (id == 2 && !*player_loaded) {
                const fVec2D player_pos = {
                    (float) tile_x + tile_size / 2.0f,
                    (float) tile_y + tile_size / 2.0f
                };

                player->pos = player_pos;
                *player_loaded = true;
            }

            if (id == 1) {
                glColor3f(0.4f, 0.4f, 0.4f);
            } else {
                glColor3f(0.0f, 0.0f, 0.0f);
            }

            const int inset = TESTING_GRID ? 1 : 0;

            glBegin(GL_QUADS);
            glVertex2i(tile_x + inset, tile_y + inset);
            glVertex2i(tile_x + tile_size - inset, tile_y + inset);
            glVertex2i(tile_x + tile_size - 1, tile_y + tile_size - inset);
            glVertex2i(tile_x + inset, tile_y + tile_size - inset);
            glEnd();
        }
    }
}