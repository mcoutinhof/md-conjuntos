#include <time.h>
#include "utils.h"

bool set_is_subset(set_t *set_a, set_t *set_b) {
    for (size_t i = 0; i < set_size(set_a); i++) {
        if (!set_contains(set_b, set_at_as(set_a, i, int))) {
            return false;
        }
    }
    return true;
}

int main() {
    srand(time(NULL));

    set_t *universe = new_set(int, 51);
    for (int i = 0; i < set_capacity(universe); i++) {
        set_insert(universe, i);
    }
    print_set("U", universe);

    set_t *set_a = new_set(int, 20);
    while (set_size(set_a) < set_capacity(set_a)) {
        set_insert(set_a, set_at_as(universe, rand() % set_size(universe), int));
    }
    print_set("A", set_a);

    set_t *set_b = new_set(int, 5);
    while (set_size(set_b) < set_capacity(set_b)) {
        set_insert(set_b, set_at_as(universe, rand() % set_size(universe), int));
    }
    print_set("B", set_b);

    set_free(universe);

    if (set_is_subset(set_b, set_a)) {
        printf("\nO conjunto B é subconjunto do conjunto A.\n");
    } else {
        printf("\nO conjunto B não é subconjunto do conjunto A.\n");
    }

    set_free(set_a);
    set_free(set_b);
}