#include "set.h"
#include "utils.h"

void print_set_int_t(const char *name, set_int_t set) {
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

void print_set_pair_int_t(const char *name, set_pair_int_t set) {
    if (set->size == 0) {
        printf("%s = Ø.\n", name);
    } else {
        set_sort(set);
        printf("%s = {", name);
        for (size_t i = 0; i < set->size; ++i) {
            printf("(%d, %d), ", set->data[i].first, set->data[i].second);
        }
        printf("\b\b}.\n");
    }
}