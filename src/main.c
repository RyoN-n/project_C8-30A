// === src/main.c ===
#include <stdio.h>
#include "rover.h"
#include "terrain.h"
#include "control_center.h"

int main() {
    char map[MAP_SIZE][MAP_SIZE];
    Rover rover;

    generate_map(map);
    init_rover(&rover);
    control_panel(&rover, map);

    return 0;
}
