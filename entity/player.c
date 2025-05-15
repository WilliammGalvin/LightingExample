//
// Created by Willam Galvin on 2025-05-14.
//

#include "player.h"
#include "../util/angle_util.h"
#include <math.h>

const float PLAYER_SIZE = 15.0f;

const float PLAYER_WALK_SPEED = 1.5f;
const float PLAYER_ROTATE_SPEED = 0.065;

void calculate_delta_values(Player* player) {
    player->d_x = cosf(player->angle);
    player->d_y = sinf(player->angle);
}

void rotate_player(Player* player, bool rotate_right) {
    const int dir = rotate_right ? -1 : 1;
    player->angle += PLAYER_ROTATE_SPEED * dir;

    if (player->angle > PI * 2) {
        player->angle = 0;
    } else if (player->angle < 0) {
        player->angle = PI * 2;
    }

    calculate_delta_values(player);
}

void move_player(Player* player, bool move_forward) {
    const int dir = move_forward ? 1 : -1;
    player->pos.x += player->d_x * PLAYER_WALK_SPEED * dir;
    player->pos.y += player->d_y * PLAYER_WALK_SPEED * dir;
}
