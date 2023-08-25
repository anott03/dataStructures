#include <malloc.h>
#include <stdio.h>

typedef struct CircularBuffer {
    int *buffer;
    unsigned int bufsize;
    unsigned int start;
    unsigned int end;
} CircularBuffer;

CircularBuffer newcb(unsigned int size) {
    CircularBuffer cb;
    cb.buffer = malloc(sizeof(int) * size);
    cb.bufsize = 7;
    cb.start = 0;
    cb.end = 1;
    return cb;
}

void push(CircularBuffer *cb, int val) {
    if (cb->end == cb->start) {
        ++cb->start;
    }
    cb->buffer[cb->end-1] = val;
    ++cb->end;
    if (cb->end == cb->bufsize+1) {
        cb->end = 1;
    }
}

int pop(CircularBuffer *cb) {
    int val = cb->buffer[cb->start];
    ++cb->start;
    if (cb->start == cb->bufsize) {
        cb->start = 0;
    }
    return val;
}

int main() {
    CircularBuffer cb = newcb(7);
    for (int i = 0; i < 10; ++i) {
        push(&cb, i);
    }

    printf("%i\n", cb.start);
    printf("%i\n", cb.end);
    for (int i = 0; i < cb.bufsize; ++i) {
        printf("%i ", pop(&cb));
    }

    free(cb.buffer);
    return 0;
}
