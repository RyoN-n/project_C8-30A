// === src/rover.c ===
#include <stdlib.h>
#include <time.h>
#include "rover.h"

void init_rover(Rover *rover) {
    rover->battery_level = 100;
    rover->charging = 0;
    rover->sensor_accuracy = 100;
    rover->direction = 1;
    rover->x = 0;
    rover->y = 0;
    rover->command_received = 0;
    rover->command_pending = 0;
    rover->last_command = 0;
    for (int i = 0; i < MAP_SIZE; ++i)
        for (int j = 0; j < MAP_SIZE; ++j)
            rover->scanned_map[i][j] = '?';
}

void rotate_rover(Rover *rover, char dir) {
    if (dir == 'L') rover->direction = (rover->direction + 3) % 4;
    else if (dir == 'R') rover->direction = (rover->direction + 1) % 4;
}

void move_rover(Rover *rover) {
    if (rover->direction == 0 && rover->y > 0) rover->y--;
    else if (rover->direction == 1 && rover->x < MAP_SIZE - 1) rover->x++;
    else if (rover->direction == 2 && rover->y < MAP_SIZE - 1) rover->y++;
    else if (rover->direction == 3 && rover->x > 0) rover->x--;
}

char scan_terrain(Rover *rover, char real_terrain) {
    int rand_val = rand() % 100;
    if (rand_val < rover->sensor_accuracy) return real_terrain;
    else {
        const char terrains[] = {'.', 'V', '^', '~'};
        return terrains[rand() % 4];
    }
}
