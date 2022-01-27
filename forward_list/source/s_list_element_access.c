#include "s_list.h"

#include <stdio.h>

/**
 * @brief access first element
 * 
 * @return return first element in a list
 */

void *slist_front(s_list *head){
    return head->data;
}

/**
 * @brief access last element
 * 
 * @return return last element in a list
 */

void *slist_back(s_list *head){
    for (s_list *tmp = head; tmp->next == NULL; tmp = tmp->next){ }
    return head->data;
}

/**
 * @brief get middle node in a linked list
 */

s_list *slist_getmiddle(s_list *head){
    s_list *fast = head->next, *slow = head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/**
 * @brief get node at specific position 
 * 
 * @param head list
 * @param idx  index
 * @return the data of specific node
 *         null if index greater than list size  
 */

void *slist_get_node(s_list *head, size_t idx){
    if(idx < 0 || idx > slist_size(head)){
        printf("idx = %ld out of bounds\n", idx);
        return NULL;
    }
    size_t i = 0;
    for (s_list *tmp = head; tmp != NULL; tmp = tmp->next, i++){
        if (i == idx){
            return tmp->data;
        }
    }
    return NULL;
}

/**
 * @brief search for specific value in the list
 * 
 * @param head original list  
 * @param data to find
 * @param compar function should return 0 if arguments are equal
 * @return the position of the data in the list 
 */

int slist_position(s_list *head, void *data, int (*compar)(void *, void *)){
    int i = 0;
    for (s_list *tmp = head; tmp != NULL; tmp = tmp->next, i++){
        if (compar(tmp->data, data) == 0){
            return i;
        }
    }
    return -1;
}

