
## priority queue
binary heap priority queue implementation.

#### struct
* `struct node` contains:
    * `data`: void pointer to point at any data 
    * `key`: every node has its own key 
* `struct priority_queue` contains:
    * `pqueue`: array of nodes
    * `len`: number of elements in array
    * `size`: size of array
    * `compar`: 

#### functions 
| function name          | description      | time complexity  |
| ---------------------- | ---------------- | ---------------- |
| `p_queue_new`          | priority queue constructor  | O(1)             |
| `p_queue_push`         | inserts element  | O(logn)             |
| `p_queue_pop`          | removes the top element  | O(logn)             |
| `p_queue_max_node`     | return the max node  | O(1)             |
| `p_queue_min_node`     | return the min node  | O(1)             |
| `p_queue_empty`        | test whether priority queue is empty  | O(1)             |
| `p_queue_size`         | returns the number of nodes  | O(1)             |
| `p_queue_swap`         | swaps the nodes  | O(1)             |


#### example

```
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

```

***output***

```
33 -> FFF
25 -> DDD
28 -> GGG
2 -> AAA
19 -> EEE
7 -> BBB
26 -> CCC
max element: {GGG, 28}
```
