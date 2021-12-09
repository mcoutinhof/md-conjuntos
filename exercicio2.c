#include <time.h>
#include "set.h"
#include "utils.h"

bool set_is_subset(set_int_t __restrict set_a, set_int_t __restrict set_b) {
    for (size_t i = 0; i < set_a->size; ++i) {
        if (!set_contains(set_b, &set_a->data[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    srand(time(NULL));

    set_int_t universe = new_set(int, 51);
    for (int i = 0; i < universe->capacity; ++i) {
        set_insert(universe, &i);
    }
    print_set_int_t("U", universe);

    set_int_t set_a = new_set(int, 20);
    while (set_a->size < set_a->capacity) {
        set_insert(set_a, &universe->data[rand() % universe->size]);
    }
    print_set_int_t("A", set_a);

    set_int_t set_b = new_set(int, 5);
    while (set_b->size < set_b->capacity) {
        set_insert(set_b, &universe->data[rand() % universe->size]);
    }
    print_set_int_t("B", set_b);

    if(set_is_subset(set_b, set_a)) {
        printf("\nO conjunto B é subconjunto do conjunto A.\n");
    } else {
        printf("\nO conjunto B não é subconjunto do conjunto A.\n");
    }

    set_free(universe);
    set_free(set_a);
    set_free(set_b);
}