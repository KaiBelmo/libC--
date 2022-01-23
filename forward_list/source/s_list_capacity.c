#include "s_list.h"

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief slist_size iterate over the whole list and counter nodes
 * 
 * @param head
 * @return the number of elements in the list
 */

size_t slist_size(s_list *head){
    for(size_t i = 0; ; head = head->next, i++){
        if(head == NULL){
            return i;
        }
    }
    return -1;
}

/**
 * @brief test whether list is empty
 * 
 * @return true if the list is empty, false otherwise.
 */

bool slist_empty(s_list *head){
    return (head == NULL) ? true : false; 
}