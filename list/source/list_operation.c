#include "list.h"

#include <stddef.h>
#include <stdio.h>

d_list  *list_concat(d_list *list_a, d_list *list_b){
    if (list_a->len == 0 || list_b->len == 0){
        return (list_a->len == 0) ? list_b : list_a;
    }
    d_list *a = list_a;
    d_list *b = list_b;
    a->tail->next = b->head;
    b->head->prev = a->tail;
    a->len += b->len;
    return a;
}

d_list  *_list_merge(d_list *list_a, d_list *list_b, int (*compar)(void *, void *)){
    (void)list_a; (void)list_b; (void)compar;
    printf("unimplemented!");
    return NULL;
}

d_list  *_list_sort(d_list *list, int (*compar)(void *, void *)){
    (void)list; (void)compar;
    printf("unimplemented!");
    return NULL;
}