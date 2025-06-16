// === include/rover.h ===
#ifndef ROVER_H
#define ROVER_H

#define MAP_SIZE 8

typedef struct {
    unsigned char battery_level;
    unsigned char charging;
    unsigned char sensor_accuracy;
    unsigned char direction; // 0: up, 1: right, 2: down, 3: left
    unsigned char x, y;
    unsigned char command_received;
    unsigned char command_pending;
    unsigned char last_command;
    char scanned_map[MAP_SIZE][MAP_SIZE];
} Rover;

void init_rover(Rover *rover);
void move_rover(Rover *rover);
void rotate_rover(Rover *rover, char direction);
char scan_terrain(Rover *rover, char real_terrain);

#endif
