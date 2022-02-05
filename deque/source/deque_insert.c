#include "deque.h"

#include <stdlib.h>

/**
 * @brief insert new last element
 */
deque   *deque_push_back(deque *Deque, void *data){
    node *new_node;
    new_node = deque_new_node(NULL, NULL, data);
    if (new_node == NULL){
        return Deque;
    }
    if (Deque->len == 0){
        Deque->front = Deque->rear = new_node;
        Deque->len++;
    } else {
        Deque->rear->next = new_node;
        new_node->prev = Deque->rear;
        Deque->rear = new_node;
        Deque->len++;
    }
    return Deque;
}

/**
 * @brief insert new first element
 */
deque   *deque_push_front(deque *Deque, void *data){
    node *new_node;
    new_node = deque_new_node(NULL, NULL, data);
    if (new_node == NULL){
        return Deque;
    }
    if (Deque->len == 0){
        Deque->front = Deque->rear = new_node;
        Deque->len++;
    } else {
        Deque->front->prev = new_node;
        new_node->next = Deque->front;
        Deque->front = new_node;
        Deque->len++;
    }
    return Deque;
}
