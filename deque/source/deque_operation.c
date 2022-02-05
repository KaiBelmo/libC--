#include "deque.h"

void    deque_swap(deque *a, deque *b){
    deque *tmp = a;
    a = b;
    b = tmp;
}
