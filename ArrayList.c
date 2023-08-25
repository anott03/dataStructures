#include <stdio.h>
#include <malloc.h>

struct IntArrayList {
    int *data;
    int len;
    int numItems;
};

struct IntArrayList new() {
    struct IntArrayList arr;
    arr.data = malloc(10 * sizeof(int));
    arr.len = 10;
    arr.numItems = 0;
    return arr;
}

void push(struct IntArrayList *arr, int num) {
    if (arr->numItems == arr->len) {
        int *oldData = arr->data;
        arr->data = malloc((arr->len * 2) * sizeof(int));
        for (int i = 0; i < arr->len; ++i) {
            arr->data[i] = oldData[i];
        }
        free(oldData);
        arr->len *= 2;
        printf("done iterating\n");
    }
    arr->data[arr->numItems] = num;
    ++arr->numItems;
}

int pop(struct IntArrayList *arr) {
    if (arr->numItems == 0) {
        return 0;
    }
    arr->numItems -= 1;
    return arr->data[arr->numItems];
}

int main() {
    struct IntArrayList arr = new();
    for (int i = 0; i < 12; ++i) {
        push(&arr, 17);
    }
    printf("num %i\n", arr.data[11]);
    free(arr.data);
    return 0;
}
