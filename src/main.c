#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "rover.h"
#include "comm.h"

int main() {
    srand((unsigned int)time(NULL));  // 乱数初期化

    TerrainMap terrain;
    Rover rover;
    CommBuffer comm;

    // 初期化
    generate_random_map(&terrain);
    init_rover(&rover);
    init_comm_buffer(&comm);

    printf("=== 地形マップ（本部側）===\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", terrain.grid[i][j]);
        }
        printf("\n");
    }

    // サンプルコマンドを送る（上→右→スキャン→送信）
    send_command(&comm, 0x10);  // 上へ
    send_command(&comm, 0x40);  // 右へ
    send_command(&comm, 0x50);  // スキャン
    send_command(&comm, 0x60);  // データ送信

    printf("\n=== ローバー動作開始 ===\n");
    while (!is_buffer_empty(&comm)) {
        unsigned char cmd = receive_command(&comm);
        rover_receive_command(&rover, cmd);
        rover_execute(&rover, &terrain);

        printf("\n[現在位置] (%d, %d), バッテリー: %d%%, 精度: %d%%\n",
            rover.pos_x, rover.pos_y, rover.battery_level, rover.sensor_accuracy);
    }

    printf("\n=== ローバーによる観測地図 ===\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", rover.sensed_map[i][j]);
        }
        printf("\n");
    }

    return 0;
}
