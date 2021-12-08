/**
 * @author Mateus Coutinho
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define auto __auto_type

#define __vector(T) \
    struct { size_t capacity, size, type_size; T *data; }

#define vector(T) \
    __vector(T) *

typedef vector(void) vector_t;

typedef __vector(void) __vector_t;

#define new_vector(type, initial_capacity) \
    (vector(type)) vector_create(sizeof(type), (initial_capacity))

#define vector_create(sizeof_type, initial_capacity) (void *) ({    \
    vector_t _vector = malloc(sizeof(__vector_t));                  \
    _vector->type_size = (sizeof_type);                             \
    _vector->size = 0;                                              \
    _vector->capacity = (initial_capacity);                         \
    _vector->data = malloc(_vector->capacity * _vector->type_size); \
    /* return */ _vector;                                           \
})

#define vector_destroy(vector) ({ \
    free((vector)->data);         \
    free((vector));               \
})

#define vector_realloc(vector, new_capacity) \
    ((vector)->data = reallocarray((vector)->data, ((vector)->capacity = (new_capacity)), (vector)->type_size))

#define vector_type_size(vector) \
    ((vector)->type_size)

#define vector_empty(vector) \
    ((vector)->size == 0)

#define vector_size(vector) \
    ((vector)->size)

#define vector_reserve(vector, req_capacity) ({   \
    if ((req_capacity) > (vector)->capacity) {    \
        vector_realloc((vector), (req_capacity)); \
    }                                             \
})

#define vector_capacity(vector) \
    ((vector)->capacity)

#define vector_shrink_to_fit(vector) ({           \
    if ((vector)->capacity > (vector)->size) {    \
        vector_realloc((vector), (vector)->size); \
    }                                             \
})

#define vector_clear(vector) \
    ((vector)->size = 0)

#define vector_insert(vector, value) ({           \
    vector_reserve((vector), (vector)->size + 1); \
    (vector)->data[(vector)->size++] = (value);   \
})

#define vector_resize(vector, new_size) ({ \
    vector_reserve((vector), (new_size));  \
    (vector)->size = (new_size);           \
})