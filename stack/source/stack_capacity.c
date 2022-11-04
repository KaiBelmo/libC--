#include "stack.h"

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief returns the number of elements
 * 
 * @param Stack
 * @return the number of elements in the stack
 */

int32_t stack_size(stack *Stack){
    return Stack->len;
}

/**
 * @brief test whether stack is empty
 * 
 * @return true if the stack is empty, false otherwise.
 */

bool    stack_empty(stack *Stack){
    return (Stack->len == 0) ? true : false; 
}
