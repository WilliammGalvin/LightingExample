#include <stdio.h>
#include <GLFW/glfw3.h>
#include "entity/player.h"
#include "gfx/renderer.h"
#include "gfx/display.h"
#include "gfx/lighting.h"
#include "world/map.h"

GLFWwindow* window;
Player player;
Renderer renderer;

bool player_loaded = false;
int pressed_keys[GLFW_KEY_LAST + 1] = { 0 };

int tile_size;
float screen_buffer;

void update() {
    if (pressed_keys[GLFW_KEY_W]) {
        move_player(&player, true);
    } else if (pressed_keys[GLFW_KEY_S]) {
        move_player(&player, false);
    }

    if (pressed_keys[GLFW_KEY_D]) {
        rotate_player(&player, true);
    } else if (pressed_keys[GLFW_KEY_A]) {
        rotate_player(&player, false);
    }
}

void render() {
    glPushMatrix();
    glTranslatef(screen_buffer, screen_buffer, 0.0f);

    render_map(&player, &player_loaded, tile_size);
    render_player(&player);
    cast_ray(player.pos, player.angle, tile_size);

    glPopMatrix();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        pressed_keys[key] = 1;
    } else if (action == GLFW_RELEASE) {
        pressed_keys[key] = 0;
    }
}

int init_window() {
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    window = glfwCreateWindow(
    SCREEN_SIZE, SCREEN_SIZE, "Lighting Example", NULL, NULL
    );

    glfwSetKeyCallback(window, key_callback);

    const Renderer r = { window };
    renderer = r;

    Player p = { { 200.0f, 200.0f }, 0.0f, 0.0f, 0.0f };
    calculate_delta_values(&p);
    player = p;

    if (window == NULL) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, SCREEN_SIZE, 0, SCREEN_SIZE, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    while (!glfwWindowShouldClose(window)) {
        update();

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

int main(void) {
    const MapRenderData mrd = get_map_render_data(SCREEN_SIZE);
    tile_size = mrd.tile_size;
    screen_buffer = mrd.screen_buffer;

    const int window_term_status = init_window();
    return window_term_status;
}
