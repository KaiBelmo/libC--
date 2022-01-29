#include "list.h"

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief test whether list is empty
 * 
 * @return true if the list is empty, false otherwise.
 */
bool    list_empty(d_list *list){
    return (list->head == NULL && list->tail == NULL) ? true : false;
}

/**
 * @brief slist_size iterate over the whole list and counter nodes
 * 
 * @return the number of elements in the list
 */
uint32_t    list_size(d_list *list){
    return list->len;
}
