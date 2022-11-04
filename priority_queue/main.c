#include "priority_queue.h"
#include <stdio.h>

int compare(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

struct data {
    char *data;
    int key;
};

int main (void) {
    struct priority_queue *new = p_queue_new(10, compare);
    struct data tmp[7] = {
        {"AAA", 2},
        {"BBB", 7},
        {"CCC", 26},
        {"DDD", 25}, 
        {"EEE", 19},
        {"FFF", 33},
        {"GGG", 28}
    };

    for (int i = 0; i < 7; i++) {
        new = p_queue_push(new, (void *)tmp[i].data, &(tmp[i].key)); 
    }
     
    for (int i = 0; i < new->len; i++) 
        printf("%d -> %s\n", *(int *)new->pqueue[i].key, (char *)new->pqueue[i].data); 
    p_queue_pop(new);
    printf("max element: {%s, %d}\n", (char *)p_queue_max_node(new).data, *(int *)p_queue_max_node(new).key);
    return 0;
}
