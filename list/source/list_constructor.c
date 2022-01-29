#include "list.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief create new node
 * 
 * @param next point to the next node
 * @param prev point to the previous node
 * @param data 
 * @return new node
 */
node    *list_new_node(node *next, node *prev, void *data){
    node *new_node = (node *)malloc(sizeof(struct node));
    if (new_node == NULL){
        perror("malloc");
        return NULL;
    }
    new_node->data = data;
    new_node->prev = prev;
    new_node->next = next;
    new_node->sizeof_data = sizeof(data);
    return new_node;
}

/**
 * @brief list constructor
 * 
 * @param data to initialize the head of the list
 * @return new list 
 */
d_list  *list_new(void *data){
    d_list *new_list;
    new_list = (d_list *)malloc(sizeof(struct d_list));
    if (new_list == NULL){
        perror("malloc");
        return NULL;
    }
    if (data == NULL){
        new_list->len = 0;
        new_list->head = NULL;
        new_list->tail = NULL;
        return new_list;
    }
    new_list->head = new_list->tail = list_new_node(NULL, NULL, data);
    if (new_list->head == NULL || new_list->tail == NULL){
        free(new_list);
        return NULL;
    }
    new_list->len = 1;
    return new_list;
}
