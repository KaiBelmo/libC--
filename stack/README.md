
## stack
singly linked list stack implementation.

#### struct
* `struct node` containes:
    * `next`: contains the link to the next node
    * `data`: void pointer to point at any data
    * `sizeof_data`
* `struct stack` containes:
    * `buttom`: points to the first node of the stack
    * `top`: points to the last node of the stack
    * `len`: length of the stack

#### functions

| function name          | description                         | time complexity  |
| ---------------------- | -------------------------------     | ---------------- |
| `stack_new`            | stack constructor                   | O(1)             |
| `stack_new_node`       | create new node                     | O(1)             |
| `stack_size`           | the number of elements in the stack | O(1)             |
| `stack_empty`          | test whether stack is empty         | O(1)             |
| `stack_clear`          | delete all elements in the stack    | O(n)             |
| `stack_pop`            | remove top node                     | O(n)             |
| `stack_buttom`         | access the first element            | O(1)             |
| `stack_top`            | access the last element             | O(1)             |
| `stack_push`           | inserts element at the top          | O(1)             |
| `stack_concat`         | concat two stacks                   | O(1)             |
| `stack_swap`           | swap contents                       | O(1)             |
| `stack_delete`         | container destructor                | O(1)             |


#### example

```C
#include "include/stack.h"
#include <stdio.h>
#include <string.h>

void print(stack *Stack){
    for(node *tmp = Stack->buttom; tmp != NULL; tmp = tmp->next){
        printf("%d", *(int *)tmp->data);
        if (tmp->next != NULL)
            printf("->");
    }
    printf("\n");
}

int main(int argc, char* argv[]){
    stack *Stack = stack_new(0);
    Stack = stack_push(Stack, "0");
    Stack = stack_push(Stack, "1");
    Stack = stack_push(Stack, "2");
    printf("size of the stack is %d\n", stack_size(Stack));
    while (!stack_empty(Stack)){
        printf("%s ", (char *)stack_top(Stack));
        Stack = stack_pop(Stack);
    }
    Stack = stack_delete(Stack);
    printf("\n");
    int a[10] = {41, 7, 90, 21, 44, 89, 73, 61, 0, 11};
    int b[3] = {69, 69, 69};
    stack *my_stack_a = stack_new(0);
    stack *my_stack_b = stack_new(0);
    for (int i = 0; i < sizeof(a) / sizeof(a[1]); i++){
        my_stack_a = stack_push(my_stack_a, &(a[i]));
    }
    for (int i = 0; i < sizeof(b) / sizeof(b[1]); i++){
        my_stack_b = stack_push(my_stack_b, &(b[i]));
    }
    stack *c = stack_concat(my_stack_a, my_stack_b);
    print(c);
    return 0;
}

```
***output***
```
size of the stack is 3
2 1 0
41->7->90->21->44->89->73->61->0->11->69->69->69
```
- todo
    - [ ] iterator
