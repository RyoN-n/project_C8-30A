#include <stdio.h>
#include <stdlib.h>
#include "rover.h"

// 初期化
void init_rover(Rover* rover) {
    rover->battery_level = 100;
    rover->charging = 0;
    rover->sensor_accuracy = 100;
    rover->direction = DIR_UP;
    rover->pos_x = 0;
    rover->pos_y = 0;
    rover->command_received = 0;
    rover->command_pending = 0;
    rover->last_command = 0;
    
    // 観測マップを '?' で初期化
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            rover->sensed_map[i][j] = '?';
}

void rover_receive_command(Rover* rover, unsigned char command) {
    rover->command_received = 1;
    rover->command_pending = 1;
    rover->last_command = command;
}

void rover_execute(Rover* rover, TerrainMap* map) {
    if (!rover->command_received || !rover->command_pending) return;

    unsigned char cmd = rover->last_command;
    switch (cmd) {
        case 0x10: if (rover->pos_y > 0) rover->pos_y--; break;  // 上
        case 0x20: if (rover->pos_y < 7) rover->pos_y++; break;  // 下
        case 0x30: if (rover->pos_x > 0) rover->pos_x--; break;  // 左
        case 0x40: if (rover->pos_x < 7) rover->pos_x++; break;  // 右
        case 0x50: {
            // センサースキャン（確率で誤認）
            char actual = map->grid[rover->pos_y][rover->pos_x];
            char result = actual;
            int rand_val = rand() % 100;
            if (rand_val > rover->sensor_accuracy) {
                // ランダム誤認
                char terrain[] = {'.', 'V', '^', '~'};
                result = terrain[rand() % 4];
            }
            rover->sensed_map[rover->pos_y][rover->pos_x] = result;

            // 精度低下
            if (actual == '^') rover->sensor_accuracy -= 2;
            else if (actual == '~') rover->sensor_accuracy -= 3;
            else rover->sensor_accuracy -= 1;
            if (rover->sensor_accuracy > 100) rover->sensor_accuracy = 0;

            break;
        }
        case 0x60: {
            // データ送信シミュレーション
            rover_send_data(rover);
            break;
        }
        default: break;
    }

    // バッテリー消費（V:谷なら充電不可）
    char tile = map->grid[rover->pos_y][rover->pos_x];
    if (tile == 'V') {
        rover->charging = 0;
    } else {
        rover->charging = 1;
        rover->battery_level += 1;
        if (rover->battery_level > 100) rover->battery_level = 100;
    }

    if (rover->battery_level > 0) {
        rover->battery_level -= 1;
    }

    rover->command_pending = 0;
}

void rover_send_data(Rover* rover) {
    printf("=== ローバーからの地図データ ===\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", rover->sensed_map[i][j]);
        }
        printf("\n");
    }
}
