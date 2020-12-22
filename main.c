#include "b_buffer.h"
#include <stdio.h>
// * Test thread safe buffer
int main() {
    b_buffer b = {.next_in = 0, .next_out = 0};
    init_b_buff(&b);
    write(&b, 10);
    printf("%d\n", read(&b));
    return 0;
}