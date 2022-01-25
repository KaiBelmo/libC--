#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define INITIAL_SIZE 20

/**
 * @alloc: size of allocated storage
 * @len: number of elements in array
 * @sizeof_data: 
 * @clear: if clear is set to 1 (true), the buffer should be initialized to 0
 * @data: array of pointers  
 */

typedef struct vector {
    int8_t  clear;
    int32_t sizeof_data;
    int64_t alloc;
    int64_t len;
    void    **data;
} vector;

int64_t vec_size(vector *);
bool    vec_empty(vector *);
void    *vec_back(vector *);
void    vec_clear(vector *);
void    vec_delete(vector *);
void    *vec_front(vector *);
int8_t  vec_pop_back(vector *);
int32_t vec_capacity(vector *);
void    *vec_at(vector *, int32_t);
int8_t  vec_shrink_to_fit(vector *);
void    vec_swap(vector *, vector *);
int8_t  vec_erase(vector *, int32_t);
int8_t  vec_resize(vector *, int64_t);
int8_t  vec_push_back(vector *, void *);
vector  *vec_new(int64_t, int32_t, bool);
int8_t  vec_assign(vector *, int32_t, void *);
int8_t  vec_insert(vector *, void *, int32_t);
void    vec_swap_elements(vector *, int32_t, int32_t);
int32_t vec_find(vector *, void *, int8_t (*)(void *, void *));
int32_t vec_find_s(vector *, void *, int64_t , int64_t , int8_t (*)(void *, void *));


#endif /* vector.h */
