#include "set.h"
#include "utils.h"

void print_set(const char *name, set_int_t set) {
    if (set->size == 0) {
        printf("%s = Ø.\n", name);
    } else {
        set_sort(set);
        printf("%s = {", name);
        for (size_t i = 0; i < set->size; ++i) {
            printf("%d, ", set->data[i]);
        }
        printf("\b\b}.\n");
    }
}

void print_relation(const char *name, set_pair_int_t relation) {
    if (relation->size == 0) {
        printf("%s = Ø.\n", name);
    } else {
        set_sort(relation);
        printf("%s = {", name);
        for (size_t i = 0; i < relation->size; ++i) {
            printf("(%d, %d), ", relation->data[i].first, relation->data[i].second);
        }
        printf("\b\b}.\n");
    }
}

void print_closure(const char *name, set_pair_int_t closure, set_pair_int_t relation) {
    if (closure->size == 0) {
        printf("%s = Ø.\n", name);
    } else {
        set_sort(closure);
        printf("%s = {", name);
        for (size_t i = 0; i < closure->size; ++i) {
            if (set_contains(relation, &closure->data[i])) {
                printf("(%d, %d), ", closure->data[i].first, closure->data[i].second);
            } else {
                printf("\033[1m(%d, %d)\033[22m, ", closure->data[i].first, closure->data[i].second);
            }
        }
        printf("\b\b}.\n");
    }
}