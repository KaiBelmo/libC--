#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct node 
{
    struct node     *next;
    void            *data;
    int32_t         sizeof_data;
} node;

/**
 * @buttom: points to the last node of the stack
 * @top:    points to the first node of the stack
 * @len:    length of the stack
 */
typedef struct stack
{
    node    *buttom;
    node    *top;
    int32_t len;
} stack;

stack   *stack_new(void *);
int32_t stack_size(stack *);
stack   *stack_pop(stack *);
void    *stack_top(stack *);
bool    stack_empty(stack *);
stack   *stack_clear(stack *);
stack   *stack_delete(stack *);
void    *stack_buttom(stack *);
void    stack_swap(stack *, stack *);
stack   *stack_push(stack *, void *);
stack   *stack_concat(stack *, stack *);
node    *stack_new_node(void *, node *);

#endif /* stack.h */

