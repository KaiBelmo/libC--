
## vector
dynamic array library.

#### struct
* `struct node` containes:
    * `data`: array of pointers  
    * `alloc`: size of allocated storage
    * `len`: number of elements in array
    * `clear`: if clear is set to 1 (true), the buffer should be initialized to 0
    * `sizeof_data`

| function name          | description                         | time complexity  |
| ---------------------- | -------------------------------     | ---------------- |
| `vec_new`              | vector constructor                  | O(1)             |
| `vec_push_back`        | add an element to the end           | O(1)             |
| `vec_insert`           | insert element at specific index    | O(n)             |
| `vec_assign`           | assigns values to the container     | O(n)             |
| `vec_pop_back`         | removes the last element            | O(1)             |
| `vec_delete`           | vector destructor                   | O(1)             |
| `vec_clear`            | clears the contents                 | O(1)             |
| `vec_front`            | access first element                | O(1)             |
| `vec_back`             | access last element                 | O(1)             |
| `vec_swap`             | swaps the contents                  | O(1)             |
| `vec_at`               | access specified element with bounds checking| O(1)             |
| `vec_size`             | the number of elements in the container  | O(1)             |
| `vec_empty`            | test whether vector is empty        | O(1)             |
| `vec_capacity`         | return size of allocated storage for the vector | O(1)             |
| `vec_erase`            | erases element                      | O(n)             |
| `vec_shrink_to_fit`    | reduces memory usage by freeing unused memory | O(1)             |
| `vec_resize`           | changes the number of allocated memory | O(1)             |
| `vec_swap_elements`    | swap element                        | O(1)             |
| `vec_find`             | linear search for a specific value          | O(n)             |
| `vec_find_s`           | binary search to find specific value in the vector (sorted vector)| O(logn)|


#### example

```C
#include "include/vector.h"
#include <stdio.h>
#include <string.h>

int8_t compare(void *a, void *b){
    return strcmp((char *)a, (char *)b);
}

void print(vector *vec){
    for (int i = 0; i < vec->len; i++){
        printf("%s ", (char *)vec->data[i]);
    }
    printf("\n");
}

int main(){
    int idx = 0;
    vector *vec_a = vec_new(50, sizeof(void *), true);
    vec_push_back(vec_a, "aaa");
    vec_push_back(vec_a, "bbb");
    vec_push_back(vec_a, "ccc");
    vec_push_back(vec_a, "ddd");
    vec_push_back(vec_a, "eee");
    vec_push_back(vec_a, "fff");
    vec_push_back(vec_a, "ggg");
    vec_push_back(vec_a, "hhh");
    vec_push_back(vec_a, "iii");
    printf("vec_a capacity is %d | vec_a len is %ld\n", vec_capacity(vec_a), vec_size(vec_a));
    print(vec_a);
    if ((idx = vec_find_s(vec_a, vec_back(vec_a), 0, vec_a->len - 1, compare)) != -1)
        printf("element found, idx = %d\n", idx);
    vec_pop_back(vec_a);
    vec_pop_back(vec_a);
    vec_pop_back(vec_a);
    vec_shrink_to_fit(vec_a);
    printf("vec_a capacity is %d | vec_a len is %ld\n", vec_capacity(vec_a), vec_size(vec_a));
    print(vec_a);
    if ((idx = vec_find(vec_a, "hhh", compare)) == -1)
        printf("element not found, idx = %d\n", idx);
    return 0;
}

```
***output***
```
vec_a capacity is 50 | vec_a len is 9
aaa bbb ccc ddd eee fff ggg hhh iii
element found, idx = 8
vec_a capacity is 6 | vec_a len is 6
aaa bbb ccc ddd eee fff
element not found, idx = -1
```
- todo
    - [ ] iterator
    - [ ] sorting
