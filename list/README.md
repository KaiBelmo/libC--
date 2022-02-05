
## list
doubly linked list library.

#### struct
* `struct node` containes:
    * `next`: contains the link to the next element in the list
    * `prev`: contains the link to the previous element in the list.
    * `data`: void pointer to point at any data
    * `sizeof_data`
* `struct d_list` containes:
    * `head`:   points to the first node of the list
    * `tail`:   points to the last node of the list
    * `len`:    length of the list

#### functions

| function name          | description      | time complexity  |
| ---------------------- | ---------------- | ---------------- |
| `list_new`             | list constructor                    | O(1)  |
| `list_new_node`        | create new node                     | O(1)  |
| `list_push_front`      | add element at beginning of the list| O(1)  |
| `list_push_back`       | add element at the end of the list  | O(1)  |
| `list_insert_aftr_idx` | add element after specific index    | O(n)  |
| `list_pop_front`       | delete first element in a list      | O(1)  |
| `list_pop_back`        | delete last element in a list       | O(1)  |
| `list_delete`          | list destructor                     | O(1)  |
| `list_delete_node`     | delete speific node in a list       | O(n)  |
| `list_clear`           | delete all elements in a list       | O(n)  |
| `list_concat`          | concat two lists                    | O(1)  |
| `list_merge`           | merge two sorted linked list        | O(n)  |
| `list_sort`            | sorting a list with merge sort      | O(nlogn)|
| `list_front`           | access first element                | O(1)  |
| `list_back`            | access last element                 | O(1)  |
| `list_getmiddle`       | get middle node in a linked list    | O(n)  |
| `list_get_node`        | get node at specific position       | O(n)  |
| `list_position`        | search for specific value in the list | O(n)  |
| `list_size`            | the number of elements in the list  | O(1) |
| `list_empty`           | test whether list is empty          | O(1)  |

#### example

```C
#include "include/list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print(d_list *list){
    for (node *i = list->head; i != NULL; i = i->next){
        if (i->prev != NULL)
            printf("<->");
        printf("%s", (char *)i->data);
    }
    printf("\n");
}

int main(int argc, char* argv[]){
    (void)argc;(void)argv;
    d_list *list = list_new(NULL);
    list = list_push_front(list, "aaaa");
    list = list_push_front(list, "uuuu");
    list = list_push_back(list, "bbbb");
    list = list_push_back(list, "cccc");
    list = list_push_back(list, "dddd");
    list = list_push_back(list, "eeee");
    list = list_insert_aftr_idx(list, "zzzz", 2);
	print(list);
    printf("list len = %d\n", list->len);
    d_list *tmp = list_new("pppp");
    tmp = list_push_back(tmp, "oooo");
    tmp = list_push_back(tmp, "tttt");
    tmp = list_push_back(tmp, "rrrr");
    tmp = list_push_back(tmp, "wwww");
	d_list *a = list_concat(list, tmp);
	printf("a len = %d\n", a->len);
	print(a);
    for (uint32_t  i = 0; i < list->len; i++){
        list = list_pop_front(list);
    }
    list = list_clear(list);
    if (list_empty(list) == true){
        printf("list is empty\n");
    }
    return 0;
}
```
***output***
```
uuuu<->aaaa<->bbbb<->zzzz<->cccc<->dddd<->eeee
list len = 7
a len = 12
uuuu<->aaaa<->bbbb<->zzzz<->cccc<->dddd<->eeee<->pppp<->oooo<->tttt<->rrrr<->wwww
list is empty
```
- todo
    - [ ] iterator
    - [ ] list_merge && list_sort
