// === src/control_center.c ===
#include <stdio.h>
#include <stdlib.h>
#include "control_center.h"
#include "terrain.h"

void control_panel(Rover *rover, char real_map[MAP_SIZE][MAP_SIZE]) {
    char input;
    printf("W: forward, A: turn left, D: turn right, S: scan, Q: quit\n");

    while (1) {
        printf("\nRover position: (%d,%d), Battery: %d%%, Accuracy: %d%%\n",
               rover->x, rover->y, rover->battery_level, rover->sensor_accuracy);
        printf("Command: ");
        scanf(" %c", &input);

        if (input == 'Q') break;
        else if (input == 'W') move_rover(rover);
        else if (input == 'A') rotate_rover(rover, 'L');
        else if (input == 'D') rotate_rover(rover, 'R');
        else if (input == 'S') {
            char actual = real_map[rover->y][rover->x];
            char detected = scan_terrain(rover, actual);
            rover->scanned_map[rover->y][rover->x] = detected;
            rover->sensor_accuracy -= 5;
        }
    }

    printf("\nScanned map:\n");
    print_map(rover->scanned_map);
    printf("\nActual map:\n");
    print_map(real_map);
}