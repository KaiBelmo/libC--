#include <stdlib.h>
#include <stdio.h>
#include "priority_queue.h"

struct priority_queue *p_queue_new(int size, int (*compar)(const void *, const void *)){
    if (size <= 0 || compar == NULL){
        return NULL;
    }
    struct priority_queue *new_pqueue = (struct priority_queue *)malloc(sizeof (struct priority_queue));
    if (new_pqueue == NULL){
        perror("malloc");
        return NULL;
    }
    new_pqueue->pqueue = (struct node *) malloc(sizeof(struct node) * size);
    if (new_pqueue->pqueue == NULL){
        perror("malloc");
        return NULL;
    }
    new_pqueue->len = 0;
    new_pqueue->size = size;
    new_pqueue->compar = compar;
    return new_pqueue;
}

struct node new_node (void *data, void *key){
    node new_node = {.data = data, .key = key};
    return new_node;
}
