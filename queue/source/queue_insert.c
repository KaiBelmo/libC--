#include "queue.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief inserts element at the end
 * 
 * @param Queue 
 * @param data new data
 */

queue  *queue_push(queue *Queue, void *data){
    node *new_node;
    new_node = queue_new_node(data, NULL);
    if(new_node == NULL){
        return Queue;
    }
    if(queue_empty(Queue) == true){
        Queue->front = Queue->rear = new_node;
    } else { 
        Queue->rear->next = new_node;
        Queue->rear = new_node;
    }
    Queue->len++;
    return Queue;
}
