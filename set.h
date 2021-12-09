#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct __set_t {
    size_t capacity, size, type_size;
    void *data;
} *set_t;

#define new_set(type, initial_capacity) set_create(sizeof(type), (initial_capacity))

void *set_create(size_t type_size, size_t initial_capacity);

void set_free(void *set_ptr);

void set_reserve(void *set_ptr, size_t req_capacity);

void set_shrink_to_fit(void *set_ptr);

void set_clear(void *set_ptr);

void set_insert(void *__restrict set_ptr, const void *__restrict val_ptr);

bool set_contains(void *__restrict set_ptr, const void *__restrict val_ptr);

void set_sort(void *__restrict set_ptr);

void *set_copy(void *__restrict set_ptr);