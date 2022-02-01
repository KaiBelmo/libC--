#include "stack.h"

#include <stdio.h>
#include <stdint.h>

/**
 * @brief access the first element
 * 
 * @return return first element in the stack
 */

void    *stack_buttom(stack *Stack){
    if (stack_empty(Stack) == true){
        printf("Empty Stack\n");
        return NULL;
    }
    return Stack->buttom->data;
}

/**
 * @brief access the last element
 * 
 * @return return last element in a stack
 */

void    *stack_top(stack *Stack){
    if (stack_empty(Stack) == true){
        printf("Empty Stack\n");
        return NULL;
    }
    return Stack->top->data;
}
