#include "stack.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief create new container
 * 
 * @param data 
 * @return  - if data equal NULL it will return an empty container
 *          - else will return a new container 
 *          contain the data that you give as an argument
 */

stack  *stack_new(void *data){
    stack *new_stack;
    new_stack = (stack *)malloc(sizeof(struct stack));
    if(new_stack == NULL){
        perror("malloc");
        return NULL; 
    }
    if(data == NULL){
        new_stack->buttom = new_stack->top = NULL;
        new_stack->len = 0;
    } else {
        new_stack->buttom = new_stack->top = stack_new_node(data, NULL);
        new_stack->len++;
    }
    return new_stack;
}

/**
 * @brief create new node
 * 
 * @param data point to the next node
 * @param next 
 * @return new node
 */
node    *stack_new_node(void *data, node *next){
    node *new_node;
    new_node = (node *)malloc(sizeof(struct node));
    if (new_node == NULL){
        perror("malloc");
        return NULL;
    }
    new_node->data = data;
    new_node->next = next;
    new_node->sizeof_data = sizeof(data);
    return new_node;
}