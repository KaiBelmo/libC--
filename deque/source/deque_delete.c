#include "deque.h"

#include <stdlib.h>

/**
 * @brief delete the last element from the container
 */
deque   *deque_pop_back(deque *Deque){
    if (Deque->len == 0){
        return Deque;
    }
    node *tmp = Deque->rear;
    if (Deque->len == 1){
        Deque->rear = Deque->front = NULL;
    } else {
        Deque->rear = Deque->rear->prev;
        Deque->rear->next = NULL;
    }
    Deque->len--;
    free(tmp);
    tmp = NULL;
    return Deque;
}

/**
 * @brief delete the first element from the container
 */
deque   *deque_pop_front(deque *Deque){
    if (Deque->len == 0){
        return Deque;
    }
    node *tmp = Deque->front;
    if (Deque->len == 1){
        Deque->front = Deque->rear = NULL;
    } else {
        Deque->front = Deque->front->next;
        Deque->front->prev = NULL;
    }
    Deque->len--;
    free(tmp);
    tmp = NULL;
    return Deque;
}

/**
 * @brief container destructor
 */
deque   *deque_delete(deque *Deque){
    if (Deque->front != NULL)
      Deque = deque_clear(Deque);
    free(Deque);
    return Deque;
}

/**
 * @brief delete all elements in a container
 */
deque   *deque_clear(deque *Deque){
    while (Deque->front != NULL)
    {
        node *tmp = Deque->front;
        Deque->front = Deque->front->next;
        free(tmp);
    }
    Deque->front = Deque->rear = NULL;
    Deque->len = 0;
    return Deque;
}
