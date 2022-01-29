#include "list.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief delete all elements in a list
 *
 * @param list container
 * @return return empty list
 */

d_list  *list_clear(d_list *list){
    while (list->head != NULL)
    {
        node *tmp = list->head;
        list->head = list->head->next;
        free(tmp);
    }
    list->head = list->tail = NULL;
    list->len = 0;
    return list;
}

/**
 * @brief delete speific node in a list
 *
 * @param list original list
 * @param data the data of the node to remove
 * @param compare: the function compare two elements it return 0 if first element equal second element
 *                 otherwise it return non zero
 */

d_list  *list_delete_node(d_list *list, void *data, int (*compare)(void *, void *)){
    if (compare(data, list->head) == 0){
        list = list_pop_front(list);
        return list;
    } else if (compare(data, list->tail) == 0){
        list = list_pop_back(list);
        return list;
    }
    node *prev = NULL, *tmp = list->head;
    while (tmp != NULL){
        if(compare(data, tmp->data) == 0){
            prev->next = tmp->next;
            list->len--;
            free(tmp);
            return list;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return list;
}

/**
 * @brief delete the first element from the list
 *
 * @param head original list
 */

d_list  *list_pop_front(d_list *list){
    if (list->len == 0){
        return list;
    }
    node *tmp = list->head;
    if (list->len == 1){
        list->head = list->tail = NULL;
    } else {
        list->head = list->head->next;
        list->head->prev = NULL;
    }
    list->len--;
    free(tmp);
    tmp = NULL;
    return list;
}

/**
 * @brief delete the last element from the list
 *
 * @param list original list
 */

d_list  *list_pop_back(d_list *list){
    if (list->len == 0){
        return list;
    }
    node *tmp = list->tail;
    if (list->len == 1){
        list->tail = list->head = NULL;
    } else {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    list->len--;
    free(tmp);
    tmp = NULL;
    return list;
}

/**
 * @brief list destructor
 *
 * @param list container
 */

void    list_delete(d_list *list){
    if (list->head != NULL)
      list = list_clear(list);
    free(list);
}
