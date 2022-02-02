#include "queue.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief create new container
 * 
 * @param data 
 * @return  - if data equal NULL it will return an empty container
 *          - else will return a new container 
 *          contain the data that you give as an argument
 */

queue  *queue_new(void *data){
    queue *new_queue;
    new_queue = (queue *)malloc(sizeof(struct queue));
    if(new_queue == NULL){
        perror("malloc");
        return NULL; 
    }
    if(data == NULL){
        new_queue->front = new_queue->rear = NULL;
        new_queue->len = 0;
    } else {
        new_queue->front = new_queue->rear = queue_new_node(data, NULL);
        new_queue->len++;
    }
    return new_queue;
}

/**
 * @brief create new node
 * 
 * @param data point to the next node
 * @param next 
 * @return new node
 */
node    *queue_new_node(void *data, node *next){
    node *new_node;
    new_node = (node *)malloc(sizeof(struct node));
    if (new_node == NULL){
        perror("malloc");
        return NULL;
    }
    new_node->data = data;
    new_node->next = next;
    new_node->sizeof_data = sizeof(data);
    return new_node;
}