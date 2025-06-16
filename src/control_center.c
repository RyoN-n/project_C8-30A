#include <stdio.h>
#include "control_center.h"
#include "rover.h"

unsigned char get_user_command() {
    printf("\n--- 操作コマンド ---\n");
    printf("1: 上へ移動\n");
    printf("2: 下へ移動\n");
    printf("3: 左へ移動\n");
    printf("4: 右へ移動\n");
    printf("5: センサーで地形をスキャン\n");
    printf("6: ローバーのデータ取得\n");
    printf("9: 終了\n");
    printf("コマンドを入力してください: ");

    int input;
    scanf("%d", &input);

    switch (input) {
        case 1: return CMD_MOVE_UP;
        case 2: return CMD_MOVE_DOWN;
        case 3: return CMD_MOVE_LEFT;
        case 4: return CMD_MOVE_RIGHT;
        case 5: return CMD_SCAN;
        case 6: return CMD_GET_DATA;
        case 9: return CMD_QUIT;
        default: return 0;
    }
}

void execute_command(Rover* rover, unsigned char command) {
    rover_receive_command(rover, command);
}
