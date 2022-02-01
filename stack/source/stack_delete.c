#include "stack.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief delete all elements in the container
 * 
 * @param Stack 
 * @return return empty container
 */

stack  *stack_clear(stack *Stack){
    while (Stack->buttom != NULL)
    {
        node *tmp = Stack->buttom;
        Stack->buttom = Stack->buttom->next;
        free(tmp);
    }
    Stack->len = 0;
    Stack->buttom = Stack->top = NULL;
    return Stack;
}

/**
 * @brief remove top node
 */
stack  *stack_pop(stack *Stack){
    if (stack_empty(Stack) == true){
        printf("Empty Stack");
        return NULL;
    } else if (Stack->len == 1){
        free(Stack->top);
        Stack->top = Stack->buttom = NULL;
        Stack->len--;
    } else {    
        node *tmp = Stack->buttom, *prev = NULL;
        while (tmp->next != NULL){
            prev = tmp;
            tmp = tmp->next;
        }
        Stack->top = prev;
        Stack->len--;
        free(Stack->top->next);
        Stack->top->next = NULL;
    }
    return Stack;
}


/**
 * @brief container destructor
 *
 * @param Stack container
 */

stack   *stack_delete(stack *Stack){
    if (Stack->buttom != NULL)
      Stack = stack_clear(Stack);
    free(Stack);
    Stack = NULL;
    return Stack;
}