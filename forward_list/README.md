


## forward list
singly linked list library.

#### struct
* `struct s_list` containes:
    * `data`: void pointer to point at any data
    * `next`: contains the link to next node can be null if the current node is the last node or an empty list
    * `sizeof_data`

#### functions

| function name          | description      | time complexity  |
| ---------------------- | ---------------- | ---------------- |
| `slist_new_node`       | create new list  | O(1)             |
| `slist_push_back`      | add element at the end of the list       | O(n)  |
| `slist_push_front`     | insert element at beginning of the list  | O(1)  |
| `slist_insert_aftr_idx`| add element after specific index         | O(n)  |
| `slist_insert_sorted`  |                                          | O(n)  |
| `slist_delete_node`    | delete speific node in a list            | O(n)  |
| `slist_pop_front`      | delete first element in a list           | O(1)  |
| `slist_pop_back`       | delete last element in a list            | O(n)  |
| `slist_clear`          | delete all elements in a list            | O(n)  |
| `slist_reverse`        | reverse the order of elements            | O(n)  |
| `slist_merge`          | merge two sorted linked list             | O(n)  |
| `slist_concat`         | concat two lists                         | O(n)  |
| `slist_sort`           | sorting a list with merge sort           | O(nlogn)|
| `slist_front`          | access first element                     | O(1)  |
| `slist_back`           | access last element                      | O(1)  |
| `slist_getmiddle`      | get middle node in a linked list         | O(n)  |
| `slist_get_node`       | get node at specific position            | O(n)  |
| `slist_position`       | search for specific value in the list    | O(n)  |
| `slist_size`           | iterate over the whole list and counter nodes | O(n) |
| `slist_empty`          | test whether list is empty               | O(1)  |

#### example

```C
#include "include/s_list.h"
#include <stdio.h>
#include <string.h>

int compar(void *ptr_a, void *ptr_b){
    int a = *(int *)ptr_a;
    int b = *(int *)ptr_b;
    return (a <= b) ? -1 : 1;
}

void print(s_list *node){
    for(s_list *tmp = node; tmp != NULL; tmp = tmp->next){
        printf("%d", *(int *)tmp->data);
        if (tmp->next != NULL)
            printf("->");
    }
    printf("\n");    
}

int main(int argc, char* argv[]){
    s_list *list = slist_new_node(0);
    int arr[10] = {41, 7, 90, 21, 44, 89, 73, 61, 0, 11};
    for (int i = 0; i < 10; i++){
        list = slist_push_back(list, &(arr[i]));
    }
    printf("size of the list is %ld\n", slist_size(list));
    print(list);
    list = slist_delete_node(list, slist_get_node(list, 3), compar);
    list = slist_sort(list, compar);
    list = slist_reverse(list);
    print(list);
    list = slist_clear(list);
    if (slist_empty(list)){
        printf("clear\n");
    }
    return 0;
}
```
***output***
```
size of the list is 10
41->7->90->21->44->89->73->61->0->11
90->89->73->61->44->41->21->11->7->0
clear
```
- todo
    - [ ] iterator
