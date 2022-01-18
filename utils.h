/**
 * @author Mateus Coutinho
 */

#pragma once

#include <stdio.h>
#include "set.h"

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

typedef struct pair_t {
    int first, second;
} pair_t;

void print_set(const char *name, set_t *set);

void print_relation(const char *name, set_t *relation);