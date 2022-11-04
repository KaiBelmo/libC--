#include "priority_queue.h"
#include <stdlib.h>
#include <stdbool.h>

struct priority_queue *resize(struct priority_queue *Q){
    Q->pqueue = realloc(Q->pqueue, Q->size * 2);
    if (Q->pqueue == NULL){
        perror("realloc");
    }
    return Q;
}

int get_parent(int position){
    if (position == 0)
       return 0; 
    else if (position < 0)
        return -1;
    else 
        return (position - 1) / 2;
}

int get_left_child(int position){
    if (position < 0)
        return -1;
    return (position * 2) + 1;
}

int get_right_child(int position){
    if (position < 0)
        return -1;
    return (position * 2) + 2;
}

void p_queue_swap(node *a, node *b){
    node tmp = *a;
    *a = *b;
    *b = tmp;
}

node p_queue_max_node(struct priority_queue *Q){
    if (Q == NULL || Q->len == 0)
        return (node){NULL, NULL};
    return Q->pqueue[0];
}
node p_queue_min_node(struct priority_queue *Q){
    if (Q == NULL || Q->len == 0)
        return (node){NULL, NULL};
    return Q->pqueue[Q->len - 1];
}
bool p_queue_empty(struct priority_queue *Q){
    if (Q->len == 0){
        return true;
    }
    return false;
}
int p_queue_size(struct priority_queue *Q){
    if (Q == NULL)
        return -1;
    return Q->len;
}

