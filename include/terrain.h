// === include/terrain.h ===
#ifndef TERRAIN_H
#define TERRAIN_H

#define MAP_SIZE 8

void generate_map(char map[MAP_SIZE][MAP_SIZE]);
void print_map(char map[MAP_SIZE][MAP_SIZE]);

#endif

// === include/control_center.h ===
#ifndef CONTROL_CENTER_H
#define CONTROL_CENTER_H

#include "rover.h"

void control_panel(Rover *rover, char real_map[MAP_SIZE][MAP_SIZE]);

#endif