#include "priority_queue.h"
#include <stdlib.h>


struct priority_queue *p_queue_push(struct priority_queue *Q, void *data, void *key){
    if (Q == NULL){
        return NULL;
    } else if (Q->len >= Q->size){
        Q = resize(Q);
        if (Q == NULL)
            return NULL;
    } else if (Q->len == 0){
        Q->pqueue[0] = new_node(data, key);
        Q->len++;
    } else {
        int i = Q->len;
        Q->pqueue[Q->len++] = new_node(data, key);
        while (i > 0 && Q->compar(Q->pqueue[i].key, Q->pqueue[get_parent(i)].key) >= 0){
            p_queue_swap(&(Q->pqueue[i]), &(Q->pqueue[get_parent(i)]));
            i = get_parent(i);
        }
    }
    return Q;
}
