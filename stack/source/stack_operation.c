#include "stack.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief concat two containers by changing the last link from Stack_a
 * 
 * @param Stack_a: first list
 * @param Stack_b: second list
 * @return new list 
 */

stack  *stack_concat(stack *Stack_a, stack *Stack_b){
    stack *Stack_a_p = Stack_a;
    stack *Stack_b_p = Stack_b;
    stack *new_stack;
    Stack_a_p->top->next = Stack_b_p->buttom;
    new_stack = Stack_a_p;
    new_stack->len = Stack_a->len + Stack_b->len; 
    return new_stack;
}

/**
 * @brief swaps the contents
 */
void    stack_swap(stack *Stack_a, stack *Stack_b){
    stack *tmp = Stack_a;
    Stack_a = Stack_b;
    Stack_b = tmp;
}