#include "priority_queue.h"
#include <stdlib.h>

struct priority_queue *p_queue_pop(struct priority_queue *Q){
    if (Q->pqueue == NULL){
        return NULL;
    }
    
    Q->pqueue[0] = Q->pqueue[--(Q->len)];
    int i = 0, selected_child = 0;
    while (1){
        selected_child = Q->compar(Q->pqueue[get_left_child(i)].key, Q->pqueue[get_right_child(i)].key) <= 0 ? get_right_child(i) : get_left_child(i);
        if (selected_child == -1)
            return NULL; 
        else if (Q->compar(Q->pqueue[i].key, Q->pqueue[selected_child].key) >= 0)
            break;    
        else 
            p_queue_swap(&(Q->pqueue[i]), &(Q->pqueue[selected_child]));         
    }
    return Q;
}

