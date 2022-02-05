#include "deque.h"

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * @brief access the first element
 */
void    *deque_front(deque *Deque){
    if (deque_empty(Deque) == true){
        printf("empty deque\n");
        return NULL;
    }
    return Deque->front->data;
}

/**
 * @brief access the last element
 */
void    *deque_back(deque *Deque){
    if (deque_empty(Deque) == true){
        printf("empty deque\n");
        return NULL;
    }
    return Deque->rear->data;
}