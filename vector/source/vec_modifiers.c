#include "vector.h"

#include <stdio.h>
#include <string.h>

/**
 * @brief assigns values to the container
 * 
 * @param size 
 * @param value 
 * @return -1 if it fails, 0 otherwise 
 */
int8_t  vec_assign(vector *vec, int32_t size, void *value){
    if (vec->alloc <= size){
        if (vec_resize(vec, vec->alloc << 1) == -1)
            return -1;
    }
    for (int i = 0; i < size; i++){
        vec->data[i] = value;
    }
    vec->len += size;
    return 0;
}

/**
 * @brief adds an element to the end
 * 
 * @param vec container
 * @param value element
 * @return -1 if it fails, 0 otherwise 
 */
int8_t  vec_push_back(vector *vec, void *value){
    if (vec->alloc <= vec->len){
        if (vec_resize(vec, vec->alloc << 1) == -1)
            return -1;
    }
    vec->data[vec->len] = value;
    vec->len++;
    return 0;
}

/**
 * @brief removes the last element
 * 
 * @param vec container
 * @return -1 if it fails, 0 otherwise 
 */
int8_t  vec_pop_back(vector *vec){
    if (vec->len >= 1){
        vec->data[vec->len] = 0;
        vec->len--;
        return 0;
    }
    return -1;
}

/**
 * @brief swaps the contents
 * 
 * @param vec_a 
 * @param vec_b 
 */
void    vec_swap(vector *vec_a, vector *vec_b){
    vector *tmp = vec_a;
    vec_a = vec_b;
    vec_b = tmp;
}

/**
 * @brief clears the contents
 * 
 * @param vec 
 */
void    vec_clear(vector *vec){
    free(vec->data);
    vec->len = 0;
}

/**
 * @brief inserts elements
 * 
 * @param vec container
 * @param value element value to insert
 * @param n position
 * @return -1 if it fails, 0 otherwise  
 */
int8_t  vec_insert(vector *vec, void *value, int32_t n){
    if (n < 0 || n >= vec->len){
        printf("%d out of bounds\n", n);
        return -1;
    }
    for (int i = vec->len; i >= n; i--){
        vec->data[i] = vec->data[i-1];
    }
    vec->data[n] = value;
    vec->len++;
    return 0;
}

/**
 * @brief erases elements
 * 
 * @param vec container
 * @param n position
 * @return -1 if it fails, 0 otherwise  
 */
int8_t  vec_erase(vector *vec, int32_t n){
    if (n < 0 || n >= vec->len){
        printf("%d out of bounds\n", n);
        return -1;
    }
    memmove(&(vec->data[n]), &(vec->data[n+1]), (vec->len - n) * vec->sizeof_data);
    vec->len--;
    return 0;
}

/**
 * @brief swap element
 * 
 * @param vec 
 * @param i 
 * @param j 
 */
void    vec_swap_elements(vector *vec, int32_t i, int32_t j){
    if (i < 0 || i >= vec->len || j < 0 || j >= vec->len){
        printf("i or j out of bounds\n");
        return;
    }
    void *tmp = vec->data[i];
    vec->data[i] = vec->data[j];
    vec->data[j] = tmp;
}