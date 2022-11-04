#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H


#include <stdio.h>
#include <stdbool.h>

typedef struct node {
    void *data;
    void *key;
} node;

struct priority_queue {
    node *pqueue;
    int len;
    int size;
    int (*compar)(const void *, const void *);
};

struct priority_queue *p_queue_new(int size, int (*compar)(const void *, const void *));
struct priority_queue *p_queue_push(struct priority_queue *Q, void *data, void *key);
struct priority_queue *p_queue_pop(struct priority_queue *Q);
struct priority_queue *resize(struct priority_queue *);
node p_queue_max_node(struct priority_queue *Q);
node p_queue_min_node(struct priority_queue *Q);
bool p_queue_empty(struct priority_queue *Q);
int p_queue_size(struct priority_queue *Q);
struct node new_node(void *, void *);
void p_queue_swap(node *a, node *b);
int get_right_child(int position);
int get_left_child(int position);
int get_parent(int position);

#endif /* priority_queue.h */
