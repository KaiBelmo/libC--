#include "vector.h"

#include <stdio.h>

/**
 * @brief access specified element with bounds checking
 * 
 * @param vec container
 * @param n index to element
 * @return content of the specified element
 */
void    *vec_at(vector *vec, int32_t n){
    if (n < 0 || n >= vec->len){
        printf("%d out of bounds\n", n);
        return NULL;
    }
    return vec->data[n];
}

/**
 * @brief access the first element
 * 
 * @param vec 
 */
void    *vec_front(vector *vec){
    return vec->data[0];
}

/**
 * @brief access the last element
 * 
 * @param vec contaner
 */
void    *vec_back(vector *vec){
    return vec->data[vec->len - 1];
}
