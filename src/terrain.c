// === src/terrain.c ===
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "terrain.h"

void generate_map(char map[MAP_SIZE][MAP_SIZE]) {
    const char terrains[] = {'.', 'V', '^', '~'};
    srand(time(NULL));
    for (int i = 0; i < MAP_SIZE; ++i) {
        for (int j = 0; j < MAP_SIZE; ++j) {
            map[i][j] = terrains[rand() % 4];
        }
    }
}

void print_map(char map[MAP_SIZE][MAP_SIZE]) {
    for (int i = 0; i < MAP_SIZE; ++i) {
        for (int j = 0; j < MAP_SIZE; ++j) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}