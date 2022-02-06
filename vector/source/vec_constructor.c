#include "vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * @brief vector constructor
 * 
 * @param alloc initial container size
 * @param sizeof_data sizeof vector elements
 * @param clear if clear is set to true, the allocated memory will be filled with 0
 * @return new vector 
 */
vector *vec_new(int64_t alloc, int32_t sizeof_data, bool clear){
    vector *vec;
    int64_t tmp = alloc;
    vec = (vector *)malloc(sizeof(vector));
    if (vec == NULL){
        perror("malloc");
        return NULL;
    }
    if (alloc <= 0){
        vec->data = malloc(sizeof_data * INITIAL_SIZE);
        tmp = INITIAL_SIZE;
    } else {
        vec->data = malloc(sizeof_data * alloc);
    }
    if (vec->data == NULL){
        perror("malloc");
        free(vec);
        vec = NULL;
    } else {
        if (clear == true){
            vec->data = memset(vec->data, 0, sizeof_data * tmp);
        }
        vec->alloc = tmp;
        vec->len = 0;
        vec->sizeof_data = sizeof_data;
    }
    return vec;
}
