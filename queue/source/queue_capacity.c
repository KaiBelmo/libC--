#include "queue.h"

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief return the number of elements in the queue
 * 
 * @param Queue
 */

int32_t queue_size(queue *Queue){
    return Queue->len;
}

/**
 * @brief test whether the container is empty
 * 
 * @return true if the container is empty, false otherwise.
 */

bool    queue_empty(queue *Queue){
    return (Queue->len == 0) ? true : false; 
}
 
