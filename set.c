#include <string.h>
#include "set.h"

struct set_t {
    void *data;
    size_t capacity, size, type_size;
};

set_t *set_create(size_t type_size, size_t initial_capacity) {
    set_t *set = malloc(sizeof(set_t));
    set->capacity = initial_capacity;
    set->size = 0;
    set->type_size = type_size;
    set->data = malloc(initial_capacity * type_size);
    return set;
}

void set_destroy(set_t *set) {
    free(set->data);
    free(set);
}

void *set_at(set_t *set, size_t index) {
    return set->data + index * set->type_size;
}

void *set_data(set_t *set) {
    return set->data;
}

size_t set_type_size(set_t *set) {
    return set->type_size;
}

bool set_empty(set_t *set) {
    return set->size == 0;
}

size_t set_size(set_t *set) {
    return set->size;
}

void set_reserve(set_t *set, size_t req_capacity) {
    if (req_capacity > set->capacity) {
        set->data = realloc(set->data, (set->capacity = req_capacity) * set->type_size);
    }
}

size_t set_capacity(set_t *set) {
    return set->capacity;
}

void set_shrink_to_fit(set_t *set) {
    if (set->capacity > set->size) {
        set->data = realloc(set->data, (set->capacity = set->size) * set->type_size);
    }
}

void set_clear(set_t *set) {
    set->size = 0;
}

void set_insert_(set_t *set, const void *pointer) {
    if (!set_contains_(set, pointer)) {
        set_reserve(set, set->size + 1);
        memcpy(set_at(set, set->size++), pointer, set->type_size);
    }
}

void set_erase(set_t *set, size_t index) {
    set_erase_n(set, index, 1);
}

void set_erase_n(set_t *set, size_t index, size_t count) {
    if (index + count > set->size) {
        count = set->size - index;
    }
    if (index < set->size) {
        set->size -= count;
        if (index < set->size) {
            memmove(set_at(set, index), set_at(set, index + count), (set->size - index) * set->type_size);
        }
    }
}

void set_erase_range(set_t *set, size_t fromIndex, size_t toIndex) {
    set_erase_n(set, fromIndex, toIndex - fromIndex);
}

bool set_contains_(set_t *set, const void *pointer) {
    for (size_t i = 0; i < set->size; i++) {
        if (memcmp(set_at(set, i), pointer, set->type_size) == 0) {
            return true;
        }
    }
    return false;
}

void set_resize(set_t *set, size_t new_size) {
    set_reserve(set, new_size);
    set->size = new_size;
}

void set_sort(set_t *set, __compar_fn_t compar) {
    qsort(set->data, set->size, set->type_size, compar);
}

set_t *set_copy(set_t *set) {
    set_t *other = malloc(sizeof(set_t));
    other->capacity = set->capacity;
    other->size = set->size;
    other->type_size = set->type_size;
    other->data = malloc(other->capacity * other->type_size);
    memcpy(other->data, set->data, other->capacity * other->type_size);
    return other;
}