#include "vector.h"

/**
 * @brief vector destructor
 * 
 * @param vec container
 */
void    vec_delete(vector *vec){
    if (vec != NULL){
        free(vec->data);
        free(vec);
        vec = NULL;
    }
}

/**
 * @brief implement binary search to find specific value in vector, s in the function name stands for sorted (sorted vector)
 * 
 * @param vec container
 * @param value element value to search for 
 * @param start 
 * @param end 
 * @param compar function pointer, should return value less than 0 if second arg greater than first arg, and 0 if equal
 */
int32_t  vec_find_s(vector *vec, void *value, int64_t start, int64_t end, int8_t (*compar)(void *, void *)){
    if (start > end){
        return -1;
    }
    int32_t mid = (start + end) / 2;
    if (compar(vec->data[mid], value) == 0){
        return mid;
    }
    // value greater than data[mid]
    if (compar(vec->data[mid], value) < 0){
        return vec_find_s(vec, value, mid + 1, end, compar);
    } else {
        return vec_find_s(vec, value, start, mid - 1, compar);
    }
}

/**
 * @brief linear search for a specific value
 * 
 * @param vec container
 * @param value element value to search for
 * @param compar function pointer, should return value less than 0 if second arg greater than first arg, and 0 if equal
 */
int32_t  vec_find(vector *vec, void *value, int8_t (*compar)(void *, void *)){
    for (int i = 0; i < vec->len; i++){
        if (compar(vec->data[i], value) == 0)
            return 0;
    }
    return -1;
}
