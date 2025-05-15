//
// Created by Willam Galvin on 2025-05-14.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "../util/vec_2d.h"

extern const float PLAYER_SIZE;

typedef struct Player {
    fVec2D pos;
    float angle;
    float d_x;
    float d_y;
} Player;

void calculate_delta_values(Player* player);

void rotate_player(Player* player, bool rotate_right);

void move_player(Player* player, bool move_forward);

#endif //PLAYER_H
