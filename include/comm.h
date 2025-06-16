#ifndef COMM_H
#define COMM_H

// 通信バッファサイズ
#define COMM_BUFFER_SIZE 16

// 通信バッファ構造体
typedef struct {
    unsigned char buffer[COMM_BUFFER_SIZE];  // コマンドを格納するバッファ（FIFO）
    int head;  // 書き込み位置
    int tail;  // 読み出し位置
} CommBuffer;

// バッファの初期化
void init_comm_buffer(CommBuffer *comm);

// コマンドを送信（追加）
int send_command(CommBuffer *comm, unsigned char cmd);

// コマンドを受信（取り出し）
unsigned char receive_command(CommBuffer *comm);

// バッファが空かどうか
int is_buffer_empty(const CommBuffer *comm);

// バッファが満かどうか
int is_buffer_full(const CommBuffer *comm);

#endif
