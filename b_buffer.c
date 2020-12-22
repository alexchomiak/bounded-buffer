#include "b_buffer.h"
#include <semaphore.h>

void init_b_buff(b_buffer * b) {
    sem_init(&b->accessor, 0, 1);
}

void write(b_buffer * b, int v) {
    sem_wait(&b->accessor);
        b->value[b->next_in] = v;
        b->next_in++;
    sem_post(&b->accessor);
}

int read(b_buffer * b) {
    sem_wait(&b->accessor);
        int ret = b->value[b->next_out];
        b->next_out++;
    sem_post(&b->accessor);
    return ret;
}

