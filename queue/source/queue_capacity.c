#include "queue.h"

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief iterate over the whole container and counte nodes
 * 
 * @param Queue
 * @return the number of nodes in the container
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
 