#include "list.h"

#include <stdio.h>

/**
 * @brief access first element
 * 
 * @param list container
 */
void    *list_front(d_list *list){
    if (list_empty(list) == true){
        printf("Empty list\n");
        return NULL;
    }
    return list->head->data;
}

/**
 * @brief access last element
 * 
 * @param list container
 */
void    *list_back(d_list *list){
    if (list_empty(list) == true){
        printf("Empty list\n");
        return NULL;
    }
    return list->tail->data;
}

/**
 * @brief get middle node in a list
 * 
 * @param list container
 */
node    *list_getmiddle(d_list *list){
    if (list_empty(list) == true){
        printf("Empty list\n");
        return NULL;
    }
    node *fast = list->head->next, *slow = list->head;
    while (fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

/**
 * @brief get node at specific position 
 * 
 * @param list  container
 * @param idx   index
 */
void    *list_get_node(d_list *list, uint32_t idx){
    if (list_empty(list) == true){
        printf("Empty list\n");
        return NULL;
    } else if(idx >= list->len){
        printf("idx = %d out of bounds\n", idx);
        return NULL;
    }
    uint32_t j = 0;
    for (node *i = list->head; i != NULL; i = i->next, j++){
        if (j == idx){
            return i->data;
        }
    }
    return NULL;
}

/**
 * @brief search for specific value in the list
 * 
 * @param list container
 * @param data data to find
 * @param compar function pointer takes two arguements, if the argumenets are equal it should return 0
 * @return the position of the data in the list 
 */
int32_t list_position(d_list *list, void *data, int (*compar)(void *, void *)){
    if (list_empty(list) == true){
        printf("Empty list\n");
        return -1;
    }
    int j = 0;
    for (node *i = list->head; i != NULL; i = i->next, j++){
        if (compar(i->data, data) == 0){
            return j;
        }
    }
    return -1;
}
