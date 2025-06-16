#ifndef ROVER_H
#define ROVER_H

#include "map.h"

typedef enum {
    DIR_UP,
    DIR_RIGHT,
    DIR_DOWN,
    DIR_LEFT
} Direction;

typedef struct {
    unsigned char battery_level;      // 0〜100
    unsigned char charging;          // 0=なし, 1=充電中
    unsigned char sensor_accuracy;   // 0〜100%
    Direction direction;             // 2bitで管理可能
    unsigned char pos_x;             // 0〜7
    unsigned char pos_y;             // 0〜7
    unsigned char command_received;  // 1=コマンドあり, 0=なし
    unsigned char command_pending;   // 1=未完了, 0=完了
    unsigned char last_command;      // 最後に受信したコマンド
    char sensed_map[8][8];           // 8x8の観測結果
} Rover;

// ローバーの初期化
void init_rover(Rover* rover);

// ローバーがコマンドを受け取る
void rover_receive_command(Rover* rover, unsigned char command);

// ローバーがコマンドを実行する
void rover_execute(Rover* rover, TerrainMap* map);

// ローバーの情報を1バイトずつ送信する（シミュレーション）
void rover_send_data(Rover* rover);

#endif
