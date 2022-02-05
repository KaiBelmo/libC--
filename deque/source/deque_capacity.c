#include "deque.h"

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief iterate over the whole deque and counte nodes
 * 
 * @return the number of elements in the deque
 */
uint32_t    deque_size(deque *Deque){
    return Deque->len;
}

/**
 * @brief test whether the container is empty
 *
 * @return true if the deque is empty, false otherwise.
 */
bool    deque_empty(deque *Deque){
    return (Deque->len == 0) ? true : false;
}
