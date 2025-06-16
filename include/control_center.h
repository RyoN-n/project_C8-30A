#ifndef CONTROL_CENTER_H
#define CONTROL_CENTER_H

#include "rover.h"

// コマンド定義（1バイト：上位4ビットがコマンド、下位4ビットがオプション）
typedef enum {
    CMD_MOVE_UP    = 0x10,
    CMD_MOVE_DOWN  = 0x20,
    CMD_MOVE_LEFT  = 0x30,
    CMD_MOVE_RIGHT = 0x40,
    CMD_SCAN       = 0x50,
    CMD_GET_DATA   = 0x60,
    CMD_QUIT       = 0xF0
} Command;

// コマンドの取得（ユーザー入力）
unsigned char get_user_command();

// コマンドの実行
void execute_command(Rover* rover, unsigned char command);

#endif
