#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"

void generate_map(TerrainMap* map) {
    char terrain_types[] = {'.', 'V', '^', '~'}; // 平地・谷・山・水たまり
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            map->grid[i][j] = terrain_types[rand() % 4];
        }
    }
}

void print_map(TerrainMap* map) {
    printf("=== 地形マップ ===\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", map->grid[i][j]);
        }
        printf("\n");
    }
}
