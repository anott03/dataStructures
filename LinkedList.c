#include <stdio.h>
#include <malloc.h>

typedef struct IntNode {
    int val;
    struct IntNode *next;
    struct IntNode *prev;
} IntNode;

IntNode *newNode(int val) {
    IntNode *n = malloc(sizeof(IntNode));
    n->val = val;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

typedef struct {
    IntNode *head;
    IntNode *tail;
    unsigned int len;
} IntLinkedList;

IntLinkedList newLL() {
    IntLinkedList ll;
    ll.head = NULL;
    ll.tail = NULL;
    ll.len = 0;
    return ll;
}

void push(IntLinkedList *ll, int val) {
    if (ll->head == NULL && ll->tail == NULL) {
        ll->head = ll->tail = newNode(val);
        return;
    }
    IntNode *n = newNode(val);
    n->prev = ll->tail;
    ll->tail = n;
    ll->tail->prev->next = ll->tail;
}

int popLast(IntLinkedList *ll) {
    int last = ll->tail->val;
    if (ll->tail == ll->head) {
        free(ll->head);
        return last;
    }
    IntNode *oldLast = ll->tail;
    ll->tail = ll->tail->prev;
    free(oldLast);
    return last;
}

int main() {
    IntLinkedList ll = newLL();
    for (int i = 0; i < 10; ++i) {
        push(&ll, i);
    }

    for (int i = 0; i < 5; ++i) {
        printf("%i\n", popLast(&ll));
    }
    // there's a memory leak here...
    return 0;
}
