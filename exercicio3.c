#include <time.h>
#include "set.h"
#include "utils.h"

bool set_is_reflexive(set_int_t __restrict set, set_pair_int_t __restrict rel) {
    for (size_t i = 0; i < set->size; ++i) {
        if (!set_contains(rel, &(pair_int_t) {set->data[i], set->data[i]})) {
            return false;
        }
    }
    return true;
}

bool set_is_symmetric(set_pair_int_t __restrict rel) {
    // TODO: code
    return false;
}

bool set_is_antisymmetric(set_pair_int_t __restrict rel) {
    // TODO: code
    return false;
}

bool set_is_transitive(set_pair_int_t __restrict rel) {
    // TODO: code
    return false;
}

int main() {
    srand(time(NULL));

    set_int_t universe = new_set(int, 5);
    for (int i = 0; i < universe->capacity; ++i) {
        set_insert(universe, &i);
    }
    print_set_int_t("U", universe);

    set_pair_int_t rel = new_set(pair_int_t, 10);
    while (rel->size < rel->capacity) {
        set_insert(rel, &(pair_int_t) {
                .first = universe->data[rand() % universe->size],
                .second = universe->data[rand() % universe->size],
        });
    }
    print_set_pair_int_t("R", rel);

    if (set_is_reflexive(universe, rel)) {
        printf("\nA relação R é reflexiva.\n");
    } else {
        printf("\nA relação R não é reflexiva.\n");
    }

    if (set_is_symmetric(rel)) {
        printf("A relação R é simétrica.\n");
    } else {
        printf("A relação R não é simétrica.\n");
    }

    if (set_is_antisymmetric(rel)) {
        printf("A relação R é antissimétrica.\n");
    } else {
        printf("A relação R não é antissimétrica.\n");
    }

    if (set_is_transitive(rel)) {
        printf("A relação R é transitiva.\n");
    } else {
        printf("A relação R não é transitiva.\n");
    }

    set_free(universe);
    set_free(rel);
}