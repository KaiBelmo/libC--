#include "queue.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief concat two containers by changing the last link from Queue_a
 * 
 * @param Queue_a: first container
 * @param Queue_b: second container
 */

queue  *queue_concat(queue *Queue_a, queue *Queue_b){
    queue *Queue_a_p = Queue_a;
    queue *Queue_b_p = Queue_b;
    queue *new_queue;
    Queue_a_p->rear->next = Queue_b_p->front;
    new_queue = Queue_a_p;
    new_queue->len = Queue_a_p->len + Queue_b_p->len; 
    return new_queue;
}

/**
 * @brief swaps the contents
 */
void    queue_swap(queue *Queue_a, queue *Queue_b){
    queue *tmp = Queue_a;
    Queue_a = Queue_b;
    Queue_b = tmp;
}