#include <time.h>
#include "set.h"
#include "utils.h"

bool set_is_reflexive(set_int_t __restrict set, set_pair_int_t __restrict relation) {
    for (size_t i = 0; i < set->size; ++i) {
        if (!set_contains(relation, &(pair_int_t) {set->data[i], set->data[i]})) {
            return false;
        }
    }
    return true;
}

bool set_is_symmetric(set_pair_int_t __restrict relation) {
    // TODO: code
    return true;
}

bool set_is_antisymmetric(set_pair_int_t __restrict relation) {
    // TODO: code
    return true;
}

bool set_is_transitive(set_pair_int_t __restrict relation) {
    // TODO: code
    return true;
}

int main() {
    srand(time(NULL));

    set_int_t universe = new_set(int, 5);
    for (int i = 0; i < universe->capacity; ++i) {
        set_insert(universe, &i);
    }
    //print_set("U", universe);

    set_pair_int_t relation = new_set(pair_int_t, 10);
    while (relation->size < relation->capacity) {
        set_insert(relation, &(pair_int_t) {
                .first = universe->data[rand() % universe->size],
                .second = universe->data[rand() % universe->size],
        });
    }
    //print_relation("R", relation);

    if (set_is_reflexive(universe, relation)) {
        printf("\nA relação R é reflexiva.\n");
    } else {
        printf("\nA relação R \033[4mnão\033[24m é reflexiva.\n");
    }

    set_free(universe);

    if (set_is_symmetric(relation)) {
        printf("A relação R é simétrica.\n");
    } else {
        printf("A relação R \033[4mnão\033[24m é simétrica.\n");
    }

    if (set_is_antisymmetric(relation)) {
        printf("A relação R é antissimétrica.\n");
    } else {
        printf("A relação R \033[4mnão\033[24m é antissimétrica.\n");
    }

    if (set_is_transitive(relation)) {
        printf("A relação R é transitiva.\n");
    } else {
        printf("A relação R \033[4mnão\033[24m é transitiva.\n");
    }

    set_free(relation);
}