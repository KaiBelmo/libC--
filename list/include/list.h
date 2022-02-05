#ifndef LIST_H
#define LIST_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @next:   contains the link to the next element in the list
 * @prev:   contains the link to the previous element in the list.
 * @data:   void pointer to point at any data type
 * @sizeof_data: sizeof data
 */
typedef struct node {
    struct node *next;
    struct node *prev;
    void        *data;
    int32_t     sizeof_data;
} node;

/**
 * @head:   points to the first node of the list
 * @tail:   points to the last node of the list
 * @len:    length of the list
 */
typedef struct d_list {
    node        *head;
    node        *tail;
    uint32_t    len;
} d_list;

d_list  *list_new(void *);
uint32_t list_size(d_list *);
bool    list_empty(d_list *);
void    *list_back(d_list *);
void    *list_front(d_list *);
d_list  *list_clear(d_list *);
d_list  *list_pop_back(d_list *);
d_list  *list_pop_back(d_list *);
d_list  *list_pop_front(d_list *);
node    *list_getmiddle(d_list *);
void    *list_get_node(d_list *, uint32_t);
d_list  *list_push_back(d_list *, void *);
d_list  *list_push_front(d_list *, void *);
node    *list_new_node(node *, node *, void *);
d_list  *list_insert_aftr_idx(d_list *, void *, uint32_t);
int32_t list_position(d_list *, void *, int (*)(void *, void *));
d_list  *list_delete_node(d_list *, void *, int (*)(void *, void *));
d_list  *list_concat(d_list *, d_list *);
d_list	*list_delete(d_list *);

//     unimplemented!
d_list  *_list_merge(d_list *, d_list *, int (*)(void *, void *));
d_list  *_list_sort(d_list *, int (*)(void *, void *));

#endif  /* list.h */
