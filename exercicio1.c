#include <time.h>
#include "set.h"
#include "utils.h"

void *set_union(set_int_t __restrict set_a, set_int_t __restrict set_b) {
    set_int_t set_c = new_set(int, set_a->size + set_b->size);
    for (size_t i = 0; i < set_a->size; ++i) {
        set_insert(set_c, &set_a->data[i]);
    }
    for (size_t i = 0; i < set_b->size; ++i) {
        set_insert(set_c, &set_b->data[i]);
    }
    set_shrink_to_fit(set_c);
    return set_c;
}

void *set_intersection(set_int_t __restrict set_a, set_int_t __restrict set_b) {
    set_int_t set_c = new_set(int, min(set_a->size, set_b->size));
    for (size_t i = 0; i < set_a->size; ++i) {
        if (set_contains(set_b, &set_a->data[i])) {
            set_insert(set_c, &set_a->data[i]);
        }
    }
    set_shrink_to_fit(set_c);
    return set_c;
}

void *set_difference(set_int_t __restrict set_a, set_int_t __restrict set_b) {
    set_int_t set_c = new_set(int, max(set_a->size, set_b->size));
    for (size_t i = 0; i < set_a->size; ++i) {
        if (!set_contains(set_b, &set_a->data[i])) {
            set_insert(set_c, &set_a->data[i]);
        }
    }
    set_shrink_to_fit(set_c);
    return set_c;
}

void *set_complement(set_int_t __restrict universe, set_int_t __restrict set) {
    return set_difference(universe, set);
}

int main() {
    srand(time(NULL));

    set_int_t universe = new_set(int, 51);
    for (int i = 0; i < universe->capacity; ++i) {
        set_insert(universe, &i);
    }
    print_set("U", universe);

    set_int_t set_a = new_set(int, 10);
    while (set_a->size < set_a->capacity) {
        set_insert(set_a, &universe->data[rand() % universe->size]);
    }
    print_set("A", set_a);

    set_int_t set_b = new_set(int, 10);
    while (set_b->size < set_b->capacity) {
        set_insert(set_b, &universe->data[rand() % universe->size]);
    }
    print_set("B", set_b);

    set_int_t set_c = set_union(set_a, set_b);
    print_set("A ∪ B", set_c);
    set_free(set_c);

    set_int_t set_d = set_intersection(set_a, set_b);
    print_set("A ∩ B", set_d);
    set_free(set_d);

    set_int_t set_e = set_difference(set_a, set_b);
    print_set("A − B", set_e);
    set_free(set_e);

    set_int_t set_f = set_difference(set_b, set_a);
    print_set("B − A", set_f);
    set_free(set_f);

    set_free(set_b);

    set_int_t set_g = set_complement(universe, set_a);
    print_set("¬A", set_g);
    set_free(set_g);

    set_free(universe);
    set_free(set_a);

}