#include "set.h"
#include "utils.h"

static int comparInt(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

void print_set(const char *name, set_t *set) {
    if (set_size(set) == 0) {
        printf("%s = {}.\n", name);
    } else {
        set_sort(set, comparInt);
        printf("%s = {", name);
        for (size_t i = 0; i < set_size(set); i++) {
            printf("%d, ", set_at_as(set, i, int));
        }
        printf("\b\b}.\n");
    }
}

static int comparPair(const void *_a, const void *_b) {
    const pair_t *a = _a, *b = _b;
    if (a->first != b->first) {
        return a->first - b->first;
    } else {
        return a->second - b->second;
    }
}

void print_relation(const char *name, set_t *relation) {
    if (set_size(relation) == 0) {
        printf("%s = {}.\n", name);
    } else {
        set_sort(relation, comparPair);
        printf("%s = {", name);
        for (size_t i = 0; i < set_size(relation); i++) {
            printf("(%d, %d), ", set_at_as(relation, i, pair_t).first, set_at_as(relation, i, pair_t).second);
        }
        printf("\b\b}.\n");
    }
}