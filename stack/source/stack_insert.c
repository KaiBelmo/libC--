#include "stack.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief inserts element at the top
 * 
 * @param Stack 
 * @param data new data
 */

stack  *stack_push(stack *Stack, void *data){
    node *new_node;
    new_node = stack_new_node(data, NULL);
    if(new_node == NULL){
        return Stack;
    }
    if(stack_empty(Stack) == true){
        Stack->buttom = Stack->top = new_node;
    } else { 
        Stack->top->next = new_node;
        Stack->top = new_node;
    }
    Stack->len++;
    return Stack;
}
