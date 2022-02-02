#include "queue.h"

#include <stdio.h>
#include <stdint.h>

/**
 * @brief access the first element
 */

void    *queue_front(queue *Queue){
    if (queue_empty(Queue) == true){
        printf("Empty Queue\n");
        return NULL;
    }
    return Queue->front->data;
}

/**
 * @brief access the last element
 */

void    *queue_back(queue *Queue){
    if (queue_empty(Queue) == true){
        printf("Empty Queue\n");
        return NULL;
    }
    return Queue->rear->data;
}
