#include "list.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief add element at the end of the list
 * 
 * @param list container
 * @param data new data
 * @return new list with new the node, and null if malloc fails 
 */
d_list  *list_push_front(d_list *list, void *data){
    node *new_node;
    new_node = list_new_node(NULL, NULL, data);
    if (new_node == NULL){
        return list;
    }
    if (list->len == 0){
        list->head = list->tail = new_node;
        list->len++;
    } else {
        list->head->prev = new_node;
        new_node->next = list->head;
        list->head = new_node;
        list->len++;
    }
    return list;
}

/**
 * @brief insert element at beginning of the list
 * 
 * @param list container
 * @param data new data
 * @return new list with new the node, and null if malloc fails 
 */
d_list  *list_push_back(d_list *list, void *data){
    node *new_node;
    new_node = list_new_node(NULL, NULL, data);
    if (new_node == NULL){
        return list;
    }
    if (list->len == 0){
        list->head = list->tail = new_node;
        list->len++;
    } else {
        list->tail->next = new_node;
        new_node->prev = list->tail;
        list->tail = new_node;
        list->len++;
    }
    return list;
}

/**
 * @brief add element after specific index
 * 
 * @param list container 
 * @param data new data
 * @param idx  index
 * @return new list with new the node, and null if malloc fails 
 */
d_list  *list_insert_aftr_idx(d_list *list, void *data, uint32_t idx){
    if (idx > list->len){
        printf("idx = %d out of bounds\n", idx);
        return list;
    }
    if (idx == 0){
        list = list_push_front(list, data);
    } else if (idx == list->len){
        list = list_push_back(list, data);
    } else {
        uint32_t i = 0;
        for (node *tmp = list->head; tmp != NULL; i++, tmp = tmp->next){
            if (idx == i){
                node *new_node = list_new_node(NULL, NULL, data);
                if (new_node != NULL){
                    new_node->prev = tmp;
                    new_node->next = tmp->next;
                    tmp->next->prev = new_node;
                    tmp->next = new_node;
                    break;
                }
                return list;
            }
        }
    }
    list->len++;
    return list;
}
