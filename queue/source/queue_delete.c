#include "queue.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief delete all node in the container
 * 
 * @param Queue 
 * @return return empty container
 */

queue   *queue_clear(queue *Queue){
    while (Queue->front != NULL)
    {
        node *tmp = Queue->front;
        Queue->front = Queue->front->next;
        free(tmp);
    }
    Queue->len = 0;
    Queue->front = Queue->rear = NULL;
    return Queue;
}

/**
 * @brief removes the first node
 */
queue  *queue_pop(queue *Queue){
    if (queue_empty(Queue) == true){
        printf("Empty Queue\n");
        return Queue;
    } else if (Queue->len == 1){
        free(Queue->front);
        Queue->front = Queue->rear = NULL;
        Queue->len--;
    } else {    
        node *tmp = Queue->front;
        Queue->front = Queue->front->next;
        free(tmp);
        tmp = NULL;
        Queue->len--;
    }
    return Queue;
}


/**
 * @brief container destructor
 *
 * @param Queue container
 */

queue   *queue_delete(queue *Queue){
    if (Queue->front != NULL)
      Queue = queue_clear(Queue);
    free(Queue);
    Queue = NULL;
    return Queue;
}