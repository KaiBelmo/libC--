#ifndef S_LIST_H
#define S_LIST_H

#include <stdlib.h>
#include <stdbool.h>

/**
 * @data: void pointer to point at any data
 * @sizeof_data: 
 * @next: contains the link to next node
 *        can be null if the cuurent node is the last node or an empty list
 */

typedef struct s_list
{
    void            *data;
    size_t          sizeof_data;
    struct s_list   *next;
} s_list;

size_t  slist_size(s_list *);
bool    slist_empty(s_list *);
void    *slist_back(s_list *);
void    *slist_front(s_list *);
s_list  *slist_clear(s_list *);
s_list  *slist_new_node(void *);
s_list  *slist_reverse(s_list *);
s_list  *slist_pop_back(s_list *);
s_list  *slist_getmiddle(s_list *);
s_list  *slist_pop_front(s_list *);
s_list  *slist_concat(s_list *, s_list *);
void    *slist_get_node(s_list *, size_t );
s_list  *slist_push_back(s_list *, void *);
s_list  *slist_push_front(s_list *, void *);
s_list  *slist_sort(s_list *, int (*)(void *, void *));
s_list  *slist_insert_aftr_idx(s_list *, void *, size_t);
int     slist_position(s_list *, void *, int (*)(void *, void *));
s_list  *slist_merge(s_list *, s_list *, int (*)(void *, void *));
s_list  *slist_delete_node(s_list *, void *, int (*)(void *, void *));
s_list  *slist_insert_sorted(s_list *, void *, int (*)(void *, void *));

#endif /* s_list.h */

