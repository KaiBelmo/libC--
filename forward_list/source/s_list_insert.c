#include "s_list.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief add element at the end of the list
 * 
 * @param head original list
 * @param data new data
 * @return new list with new the node, and null if malloc fails
 */

s_list *slist_push_back(s_list *head, void *data){
    s_list *new_node, *tmp = head;
    new_node = slist_new_node(data);
    if(new_node == NULL){
        return head;
    }
    if(head == NULL){
        head = new_node;
        return head;    
    } 
    while (tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = new_node;
    return head;
}

/**
 * @brief change insert element at beginning of the list
 * 
 * @param head original list 
 * @param data new data
 * @return new list with new the node, and null if malloc fails
 */

s_list *slist_push_front(s_list *head, void *data){
    s_list *new_node = slist_new_node(data);
    if(new_node == NULL){
        return head;
    }
    new_node->next = head;
    head = new_node;
    return head;
}

/**
 * @brief add element after specific index
 * 
 * @param head original list
 * @param data new data
 * @param idx  index
 * @return new list with new the node, and null if malloc fails
 */

s_list *slist_insert_aftr_idx(s_list *head, void *data, size_t idx){
    if(idx < 0 || idx > slist_size(head)){
        printf("idx = %ld out of bounds\n", idx);
        return head;
    }
    s_list *new_node = slist_new_node(data);
    s_list *tmp = head;
    if(new_node == NULL){
        return head;
    }
    if(idx == 0){
        head = slist_push_front(head, data);
        return head;
    } else if (idx == slist_size(head)){
        head = slist_push_back(head, data);
        return head;
    }
    for(size_t i = 0; ; i++, tmp = tmp->next){
        if(i == idx){
            new_node->next = tmp->next->next;
            tmp->next = new_node;
            break;
        }
    }
    return head;
}

/**
 * @brief 
 * 
 * @param head : original list
 * @param data :  data new data
 * @param compar: the function compare two elements it return a number < 0 if first element less or equal the second element
 * @return new list 
 */

s_list *slist_insert_sorted(s_list *head, void *data, int (*compar)(void *, void *)){
    s_list *new_node = slist_new_node(data);
    if (new_node == NULL){
        return head;
    }
    s_list *tmp = head, *prev = NULL;
    if (tmp == NULL){
        return new_node;
    }
    while (tmp != NULL)
    {
        if (compar(tmp->data, new_node->data) > 0){
            new_node->next = prev->next;
            prev->next = new_node;
            return head;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    prev->next = new_node;
    return head;
}
