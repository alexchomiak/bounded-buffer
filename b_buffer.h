#include <semaphore.h>
#ifndef B_BUFFER_H
#define B_BUFFER_H
#define B_BUFFER_SIZE 100
typedef struct {
    int value[B_BUFFER_SIZE];
    int next_in, next_out;
    sem_t accessor;
} b_buffer;
void init_b_buff(b_buffer * b);
void write(b_buffer * b, int v);
int read(b_buffer * b);
#endif