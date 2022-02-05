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
    (void)argc; (void)argv;
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

