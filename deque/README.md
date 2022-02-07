
## deque
double ended queue library.

#### struct
* `struct node` containes:
    * `next`: contains the link to the next element
    * `prev`: contains the link to the previous element
    * `data`: void pointer to point at any data
    * `sizeof_data`
* `struct deque` containes:
    * `front`:   points to the first node 
    * `rear`:    points to the last node 
    * `len`:     length of the deque

#### functions

| function name          | description      | time complexity  |
| ---------------------- | ---------------- | ---------------- |
| `deque_new`            | deque constructor                   | O(1)  |
| `deque_new_node`       | create new node                     | O(1)  |
| `deque_push_front`     | add element at beginning            | O(1)  |
| `deque_push_back`      | add element at the end              | O(1)  |
| `deque_pop_front`      | delete the first element            | O(1)  |
| `deque_pop_back`       | delete the last element             | O(1)  |
| `deque_delete`         | deque destructor                    | O(1)  |
| `deque_clear`          | delete all elements                 | O(n)  |
| `deque_front`          | access first element                | O(1)  |
| `deque_back`           | access last element                 | O(1)  |
| `deque_swap`           | swap contents                       | O(1)  |
| `deque_size`           | the number of elements in the deque | O(1)  |
| `deque_empty`          | test whether the deque is empty     | O(1)  |

#### example

```C
#include "deque.h"
#include <stdio.h>

void print(deque *q){
    for (node *i = q->front; i != NULL; i = i->next){
        printf("%s ", (char *)i->data);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    deque *my_deque = deque_new("aaaa");
    my_deque = deque_push_back(my_deque, "bbbb");
    my_deque = deque_push_back(my_deque, "cccc");
    my_deque = deque_push_back(my_deque, "dddd");
    my_deque = deque_push_back(my_deque, "eeee");
    print(my_deque);
    my_deque = deque_push_front(my_deque, "1111");
    my_deque = deque_push_front(my_deque, "0000");
    print(my_deque);
    my_deque = deque_pop_back(my_deque);
    my_deque = deque_pop_back(my_deque);
    my_deque = deque_pop_front(my_deque);
    print(my_deque);
    my_deque = deque_clear(my_deque);
    if (deque_empty(my_deque) == true){
        printf("Empty");
        my_deque = deque_delete(my_deque);
        return 0;
    }
    return 1;
}
```
***output***
```
aaaa bbbb cccc dddd eeee
0000 1111 aaaa bbbb cccc dddd eeee
1111 aaaa bbbb cccc
Empty
```
- todo
    - [ ] iterator
