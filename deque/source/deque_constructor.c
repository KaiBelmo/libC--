#include "deque.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief create new node
 * 
 * @param data 
 * @param next link to the next node
 * @param prev link to the previous node
 * @return new node
 */
node    *deque_new_node(node *next, node *prev, void *data){
    node *new_node = (node *)malloc(sizeof(struct node));
    if (new_node == NULL){
        perror("malloc");
        return NULL;
    }
    new_node->data = data;
    new_node->prev = prev;
    new_node->next = next;
    new_node->sizeof_data = sizeof(data);
    return new_node;
}

/**
 * @brief deque constructor
 * 
 * @param data to initialize the container 
 * @return new container 
 */
deque   *deque_new(void *data){
    deque *new_deque;
    new_deque = (deque *)malloc(sizeof(struct deque));
    if (new_deque == NULL){
        perror("malloc");
        return NULL;
    }
    if (data == NULL){
        new_deque->len = 0;
        new_deque->front = NULL;
        new_deque->rear = NULL;
        return new_deque;
    }
    new_deque->front = new_deque->rear = deque_new_node(NULL, NULL, data);
    if (new_deque->front == NULL || new_deque->rear == NULL){
        free(new_deque);
        return NULL;
    }
    new_deque->len = 1;
    return new_deque;
}

