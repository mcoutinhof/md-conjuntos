#include "set.h"
#include <memory.h>

void *set_create(size_t type_size, size_t initial_capacity) {
    set_t set = malloc(sizeof(struct __set_t));
    set->type_size = type_size;
    set->size = 0;
    set->capacity = initial_capacity;
    set->data = malloc(initial_capacity * type_size);
    return set;
}

void set_free(void *set_ptr) {
    set_t set = set_ptr;
    free(set->data);
    free(set);
}

void set_reserve(void *set_ptr, size_t req_capacity) {
    set_t set = set_ptr;
    if (req_capacity > set->capacity) {
        set->data = reallocarray(set->data, (set->capacity = req_capacity), set->type_size);
    }
}

void set_shrink_to_fit(void *set_ptr) {
    set_t set = set_ptr;
    if (set->size < set->capacity) {
        set->data = reallocarray(set->data, (set->capacity = set->size), set->type_size);
    }
}

void set_insert(void *__restrict set_ptr, const void *__restrict val_ptr) {
    if (set_contains(set_ptr, val_ptr)) {
        return;
    }
    set_t set = set_ptr;
    set_reserve(set_ptr, set->size + 1);
    memcpy(set->data + set->size++ * set->type_size, val_ptr, set->type_size);
}

bool set_contains(void *__restrict set_ptr, const void *__restrict val_ptr) {
    set_t set = set_ptr;
    for (size_t i = 0; i < set->size; ++i)
        if (memcmp(set->data + i * set->type_size, val_ptr, set->type_size) == 0)
            return true;
    return false;
}

void set_sort(void *__restrict set_ptr) {
    set_t set = set_ptr;
    int set_compare(const void *s1, const void *s2) {
        return memcmp(s1, s2, set->type_size);
    }
    qsort(set->data, set->size, set->type_size, set_compare);
}

void *set_copy(void *__restrict set_ptr) {
    set_t set_a = set_ptr;
    set_t set_b = malloc(sizeof(struct __set_t));
    memcpy(set_b, set_a, sizeof(struct __set_t));
    set_b->data = malloc(set_a->capacity * set_a->type_size);
    memcpy(set_b->data, set_a->data, set_a->capacity * set_a->type_size);
    return set_b;
}