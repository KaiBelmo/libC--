#include "s_list.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Reverse the order of elements
 * 
 * @param node the original list
 * @return new list with reversed elements  
 */

s_list  *slist_reverse(s_list *head){
    // s_list *tmp = slist_new_node(0);
    // for(; node != NULL; node = node->next)
    //     tmp = slist_push_front(tmp, node->data);
    // return tmp;
    s_list *next, *current = head, *prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

/**
 * @brief merge two sorted linked list
 * 
 * @param list_a: first list 
 * @param list_b: second list
 * @param compar: the function compare two elements it return a number < 0 if first element less or equal the second element
 * 
 * @return new list with merged elements
 */

s_list  *slist_merge(s_list *list_a, s_list *list_b, int (*compar)(void *, void *)){
	s_list *new_list, *tail, *next_node;
	new_list = tail = next_node = NULL;
	while(list_a != NULL && list_b != NULL){
		if (compar(list_a->data, list_b->data) < 0){
			next_node = list_a;
			list_a = list_a->next;
		} else {
			next_node = list_b;
			list_b = list_b->next;
		}
		if (tail == NULL){
			new_list = next_node;
			tail = new_list;
		} else {
			tail->next = next_node;
		    tail = tail->next;
		}
	}
	tail->next = (list_a != NULL) ? list_a : list_b;
    return new_list;
}

/**
 * @brief concat two lists by changing the last link from list1
 * 
 * @param list1: first list
 * @param list2: second list
 * @return new list 
 */

s_list  *slist_concat(s_list *list1, s_list *list2){
    s_list *new_list = list1;
    s_list *tmp = new_list;
    for(; tmp->next != NULL; tmp = tmp->next);
    tmp->next = list2;
    return new_list;
}

/**
 * @brief sorting a singly linked list with merge sort
 * 
 * @param head unsorted list
 * @param compar the function compare two elements it return a number < 0 if first element less or equal the second element
 * @return sorted list
 */

s_list  *slist_sort(s_list *head, int (*compar)(void *, void *)){
    if (head == NULL || head->next == NULL){
        return head;
    }
    s_list *mid = slist_getmiddle(head);
    s_list *left = mid->next;
    s_list *right = head;
    mid->next = NULL;
    left = slist_sort(left, compar);
    right = slist_sort(right, compar);
    return slist_merge(left, right, compar);
}
