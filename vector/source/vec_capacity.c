#include "vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief test whether vector is empty
 * 
 * @param vec container
 * @return true if the vector len == 0
 * @return false if the vector len != 0
 */
bool    vec_empty(vector *vec){
    return (vec->len == 0) ? true : false;
}

/**
 * @brief return size
 * 
 * @param vec container
 */
int64_t vec_size(vector *vec){
    return vec->len;
}

/**
 * @brief return size of allocated storage for the vector
 * 
 * @param vec container
 */
int32_t vec_capacity(vector *vec){
    return vec->alloc;
}

/**
 * @brief changes the number of allocated memory
 * 
 * @param vec container
 * @param new_size new container size
 * @return -1 if it fails, 0 otherwise  
 */
int8_t  vec_resize(vector *vec, int64_t new_size){
    if (new_size <= 0)
        return -1;
    vec->alloc = new_size;
    vec->data = realloc(vec->data, vec->alloc * vec->sizeof_data);
    if (vec->data == NULL){
        perror("realloc");
        return -1;
    }
    return 0;
}

/**
 * @brief reduces memory usage by freeing unused memory
 * 
 * @param vec container
 * @return -1 if it fails, 0 otherwise   
 */
int8_t  vec_shrink_to_fit(vector *vec){
    vec->alloc = vec->len;
    return vec_resize(vec, vec->len);
}