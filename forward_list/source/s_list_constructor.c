#include "s_list.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief create new list
 * 
 * @param data 
 * @return  - if data equal NULL it will return an empty list
 *          - else will return a new list 
 *          contain the data that you give as an argument
 */

s_list *slist_new_node(void *data){
    s_list *new_node;
    if(data == NULL){
        new_node = NULL;
    } else {
        new_node = (s_list *)malloc(sizeof(struct s_list));
        if(new_node == NULL){
            perror("malloc");
            return NULL; 
        }
        new_node->data = data;
        new_node->sizeof_data = sizeof(data);
        new_node->next = NULL;
    }
    return new_node;
}
