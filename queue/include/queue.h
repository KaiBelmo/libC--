#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct node 
{
    struct node     *next;
    void            *data;
    int32_t         sizeof_data;
} node;

/**
 * @front:  points to the first node
 * @rear:   points to the last node
 * @len:    length of the queue
 */
typedef struct queue
{
    node    *front;
    node    *rear;
    int32_t len;
} queue;

queue   *queue_new(void *);
int32_t queue_size(queue *);
queue   *queue_pop(queue *);
bool    queue_empty(queue *);
void    *queue_back(queue *);
void    *queue_front(queue *);
queue   *queue_clear(queue *);
queue   *queue_delete(queue *);
void    queue_swap(queue *, queue *);
queue   *queue_push(queue *, void *);
queue   *queue_concat(queue *, queue *);
node    *queue_new_node(void *, node *);

#endif /* queue.h */

