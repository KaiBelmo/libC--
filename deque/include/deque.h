#ifndef DEQUE_H
#define DEQUE_H

#include <stdint.h>
#include <stdbool.h>

typedef struct node {
    struct node *next;
    struct node *prev;
    void        *data;
    int32_t     sizeof_data;
} node;

/**
 * @front:  points to the first node
 * @rear:   points to the last node
 * @len:    length of the deque
 */
typedef struct deque {
    node        *front;
    node        *rear;
    uint32_t    len;
} deque;

deque   *deque_new(void *);
bool    deque_empty(deque *);
uint32_t deque_size(deque *);
void    *deque_back(deque *);
deque   *deque_clear(deque *);
void    *deque_front(deque *);
deque   *deque_delete(deque *);
deque   *deque_pop_back(deque *);
deque   *deque_pop_front(deque *);
void    deque_swap(deque *, deque *);
deque   *deque_push_back(deque *, void *);
deque   *deque_push_front(deque *, void *);
node    *deque_new_node(node *, node *, void *);

#endif /* deque.h */
