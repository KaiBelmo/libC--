

## queue
singly linked list queue implementation.

#### struct
* `struct node` containes:
    * `next`: contains the link to the next node
    * `data`: void pointer to point at any data
    * `sizeof_data`
* `struct queue` containes:
    * `front`: points to the first node of the queue
    * `rear`: points to the last node of the queue
    * `len`: length of the stack

#### functions

| function name          | description                         | time complexity  |
| ---------------------- | -------------------------------     | ---------------- |
| `queue_new`            | queue constructor                   | O(1)             |
| `queue_new_node`       | create new node                     | O(1)             |
| `queue_size`           | the number of elements in the queue | O(1)             |
| `queue_empty`          | test whether the queue is empty     | O(1)             |
| `queue_clear`          | delete all elements in the queue    | O(n)             |
| `queue_pop`            | removes the first node              | O(1)             |
| `queue_front`          | access the first element            | O(1)             |
| `queue_back`           | access the last element             | O(1)             |
| `queue_push`           | inserts element at the end          | O(1)             |
| `queue_concat`         | concat two stacks                   | O(1)             |
| `queue_swap`           | swap contents                       | O(1)             |
| `queue_delete`         | container destructor                | O(1)             |


#### example

```C
#include "include/queue.h"
#include <stdio.h>
#include <string.h>

void print_s(queue *Q){
    for(node *tmp = Q->front; tmp != NULL; tmp = tmp->next){
        printf("%s", (char *)tmp->data);
        if (tmp->next != NULL)
            printf("->");
    }
    printf("\n");    
}

void print_d(queue *Q){
    for(node *tmp = Q->front; tmp != NULL; tmp = tmp->next){
        printf("%d", *(int *)tmp->data);
        if (tmp->next != NULL)
            printf("->");
    }
    printf("\n");    
}

int main(int argc, char* argv[]){
    queue *my_queue = queue_new(0);
    queue_push(my_queue, "10");
    queue_push(my_queue, "20");
    queue_push(my_queue, "30");
    printf("size of queue is %d\n", my_queue->len);
    if (queue_empty(my_queue) == false)
        print_s(my_queue);
    my_queue = queue_pop(my_queue);
    my_queue = queue_pop(my_queue);
    my_queue = queue_pop(my_queue);
    my_queue = queue_pop(my_queue);
    if (queue_empty(my_queue) == false)
        print_s(my_queue);

    printf("size of queue is %d\n", my_queue->len);
    my_queue = queue_clear(my_queue);
    if (queue_empty(my_queue) == true){
        puts("Empty");
        my_queue = queue_delete(my_queue);
    }
    
    int a[10] = {41, 7, 90, 21, 44, 89, 73, 61, 0, 11};
    int b[3] = {69, 69, 69};
    queue *my_queue_a = queue_new(0);
    queue *my_queue_b = queue_new(0);
    for (int i = 0; i < sizeof(a) / sizeof(a[1]); i++){
        my_queue_a = queue_push(my_queue_a, &(a[i]));
    }
    for (int i = 0; i < sizeof(b) / sizeof(b[1]); i++){
        my_queue_b = queue_push(my_queue_b, &(b[i]));
    }
    queue *c = queue_concat(my_queue_a, my_queue_b);
    print_d(c);
    c = queue_clear(c);
    if (queue_empty(c) == true){
        puts("Empty");
        c = queue_delete(c);
    }
    return 0;
}

```
***output***
```
size of queue is 3
10->20->30
Empty Queue
size of queue is 0
Empty
41->7->90->21->44->89->73->61->0->11->69->69->69
Empty
```
- todo
    - [ ] iterator
