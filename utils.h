/**
 * @author Mateus Coutinho
 */

#pragma once

#include <stdio.h>

#define max(a, b) ({      \
    __auto_type _a = (a); \
    __auto_type _b = (b); \
    _a > _b ? _a : _b;    \
})

#define min(a, b) ({      \
    __auto_type _a = (a); \
    __auto_type _b = (b); \
    _a < _b ? _a : _b;    \
})

typedef struct __set_int_t {
    size_t capacity, size, type_size;
    int *data;
} *set_int_t;

typedef struct __pair_int_t {
    int first, second;
} pair_int_t;

typedef struct __set_pair_int_t {
    size_t capacity, size, type_size;
    pair_int_t *data;
} *set_pair_int_t;

void print_set_int_t(const char *name, set_int_t set);

void print_set_pair_int_t(const char *name, set_pair_int_t set);