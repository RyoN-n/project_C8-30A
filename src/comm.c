#include <stdio.h>
#include "comm.h"

// 通信バッファの初期化
void init_comm_buffer(CommBuffer *comm) {
    comm->head = 0;
    comm->tail = 0;
}

// コマンドを送信（バッファに追加）
int send_command(CommBuffer *comm, unsigned char cmd) {
    if (is_buffer_full(comm)) {
        return -1; // バッファが満杯
    }
    comm->buffer[comm->head] = cmd;
    comm->head = (comm->head + 1) % COMM_BUFFER_SIZE;
    return 0; // 成功
}

// コマンドを受信（バッファから取得）
unsigned char receive_command(CommBuffer *comm) {
    if (is_buffer_empty(comm)) {
        return 0xFF; // エラー: バッファ空
    }
    unsigned char cmd = comm->buffer[comm->tail];
    comm->tail = (comm->tail + 1) % COMM_BUFFER_SIZE;
    return cmd;
}

// バッファが空かどうか
int is_buffer_empty(const CommBuffer *comm) {
    return comm->head == comm->tail;
}

// バッファが満かどうか
int is_buffer_full(const CommBuffer *comm) {
    return ((comm->head + 1) % COMM_BUFFER_SIZE) == comm->tail;
}
