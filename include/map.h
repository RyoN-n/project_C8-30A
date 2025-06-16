#ifndef MAP_H
#define MAP_H

typedef struct {
    char grid[8][8];  // 8x8の地形マップ
} TerrainMap;

// 地形マップの初期化（ランダム生成）
void generate_map(TerrainMap* map);

// 地形マップの表示
void print_map(TerrainMap* map);

#endif
