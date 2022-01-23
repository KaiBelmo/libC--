#include "s_list.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief delete all elements in a list
 * 
 * @param head 
 * @return return empty list
 */

s_list *slist_clear(s_list *head){
    while (head != NULL)
    {
        s_list *tmp = head;
        head = head->next;
        free(tmp);
    }
    head = NULL;
    return head;
}

/**
 * @brief delete speific node in a list
 * 
 * @param head original list
 * @param data the data of the node to remove
 * @param compare: the function compare two elements it return 0 if first element equal second element
 *                 otherwise it return non zero
 */

s_list *slist_delete_node(s_list *head, void *data, int (*compare)(void *, void *)){
    s_list *prev = NULL, *tmp = head;
    while (tmp != NULL){
        if(compare(data, tmp->data) == 0){
            prev->next = tmp->next;
            free(tmp);
            return head;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return head;
}

/**
 * @brief delete first element in a list
 * 
 * @param head original list
 */

s_list *slist_pop_front(s_list *head){
    s_list *tmp = head;
    head = head->next;
    free(tmp);
    return head;
}

/**
 * @brief delete last element in a list 
 * 
 * @param head original list 
 */

s_list *slist_pop_back(s_list *head){
    s_list *tmp = head, *prev = NULL;
    while (tmp->next!= NULL){
        prev = tmp;
        tmp = tmp->next;
    }
    free(prev->next);
    prev->next = NULL;
    return head;
}
