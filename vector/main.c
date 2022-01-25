#include "include/vector.h"
#include <stdio.h>
#include <string.h>

int8_t compare(void *a, void *b){
    return strcmp((char *)a, (char *)b);
}

int main(){
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
    // for (int i = 0; i < vec_a->len; i++){
        // printf("%s ", (char *)vec_a->data[i]);
    // }
    // printf("%d | %s", vec_find(vec_a, "iii", 0, vec_a->len - 1, compare), (char *)vec_a->data[vec_find(vec_a, "iii", 0, vec_a->len - 1, compare)]);
    printf("%d\n", vec_find_s(vec_a, "zzz", 0, vec_a->len - 1, compare));
    // printf("%d\n", vec_find(vec_a, "zzz", compare));

    return 0;
}