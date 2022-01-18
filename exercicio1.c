#include <time.h>
#include "utils.h"

void *set_union(set_t *set_a, set_t *set_b) {
    set_t *set_c = new_set(int, set_size(set_a) + set_size(set_b));
    for (size_t i = 0; i < set_size(set_a); i++) {
        set_insert(set_c, set_at_as(set_a, i, int));
    }
    for (size_t i = 0; i < set_size(set_b); i++) {
        set_insert(set_c, set_at_as(set_b, i, int));
    }
    set_shrink_to_fit(set_c);
    return set_c;
}

void *set_intersection(set_t *set_a, set_t *set_b) {
    set_t *set_c = new_set(int, min(set_size(set_a), set_size(set_b)));
    for (size_t i = 0; i < set_size(set_a); i++) {
        if (set_contains(set_b, set_at_as(set_a, i, int))) {
            set_insert(set_c, set_at_as(set_a, i, int));
        }
    }
    set_shrink_to_fit(set_c);
    return set_c;
}

void *set_difference(set_t *set_a, set_t *set_b) {
    set_t *set_c = new_set(int, max(set_size(set_a), set_size(set_b)));
    for (size_t i = 0; i < set_size(set_a); i++) {
        if (!set_contains(set_b, set_at_as(set_a, i, int))) {
            set_insert(set_c, set_at_as(set_a, i, int));
        }
    }
    set_shrink_to_fit(set_c);
    return set_c;
}

void *set_complement(set_t *universe, set_t *set) {
    return set_difference(universe, set);
}

int main() {
    srand(time(NULL));

    set_t *universe = new_set(int, 51);
    for (int i = 0; i < set_capacity(universe); i++) {
        set_insert(universe, i);
    }
    print_set("U", universe);

    set_t *set_a = new_set(int, 10);
    while (set_size(set_a) < set_capacity(set_a)) {
        set_insert(set_a, set_at_as(universe, rand() % set_size(universe), int));
    }
    print_set("A", set_a);

    set_t *set_b = new_set(int, 10);
    while (set_size(set_b) < set_capacity(set_b)) {
        set_insert(set_b, set_at_as(universe, rand() % set_size(universe), int));
    }
    print_set("B", set_b);

    set_t *set_c = set_union(set_a, set_b);
    print_set("A ∪ B", set_c);
    set_free(set_c);

    set_t *set_d = set_intersection(set_a, set_b);
    print_set("A ∩ B", set_d);
    set_free(set_d);

    set_t *set_e = set_difference(set_a, set_b);
    print_set("A − B", set_e);
    set_free(set_e);

    set_t *set_f = set_difference(set_b, set_a);
    print_set("B − A", set_f);
    set_free(set_f);

    set_free(set_b);

    set_t *set_g = set_complement(universe, set_a);
    print_set("¬A", set_g);
    set_free(set_g);

    set_free(universe);
    set_free(set_a);
}