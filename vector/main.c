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
