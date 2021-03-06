#include <time.h>
#include "utils.h"

bool set_is_reflexive(set_t *set, set_t *relation) {
    for (size_t i = 0; i < set_size(set); i++) {
        pair_t pair = {set_at_as(set, i, int), set_at_as(set, i, int)};
        if (!set_contains(relation, pair)) {
            return false;
        }
    }
    return true;
}

bool set_is_symmetric(set_t *relation) {
    for (size_t i = 0; i < set_size(relation); i++) {
        pair_t pair = set_at_as(relation, i, pair_t);
        pair_t symmetry = {pair.second, pair.first};
        if (!set_contains(relation, symmetry)) {
            return false;
        }
    }
    return true;
}

bool set_is_antisymmetric(set_t *relation) {
    for (size_t i = 0; i < set_size(relation); i++) {
        pair_t pair = set_at_as(relation, i, pair_t);
        if (pair.first != pair.second) {
            pair_t symmetry = {pair.second, pair.first};
            if (set_contains(relation, symmetry)) {
                return false;
            }
        }
    }
    return true;
}

bool set_is_transitive(set_t *relation) {
    for (size_t i = 0; i < set_size(relation); i++) {
        pair_t pair = set_at_as(relation, i, pair_t);
        for (size_t j = 0; j < set_size(relation); j++) {
            pair_t next_pair = set_at_as(relation, j, pair_t);
            if (pair.second == next_pair.first) {
                pair_t transition = {pair.first, next_pair.second};
                if (!set_contains(relation, transition)) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    srand(time(NULL));

    set_t *universe = new_set(int, 5);
    for (int i = 0; i < set_capacity(universe); i++) {
        set_insert(universe, i);
    }
    print_set("U", universe);

    set_t *relation = new_set(pair_t, 10);
    while (set_size(relation) < set_capacity(relation)) {
        pair_t pair = {
                .first = set_at_as(universe, rand() % set_size(universe), int),
                .second = set_at_as(universe, rand() % set_size(universe), int)
        };
        set_insert(relation, pair);
    }
    print_relation("R", relation);

    if (set_is_reflexive(universe, relation)) {
        printf("\nA rela????o R ?? reflexiva.\n");
    } else {
        printf("\nA rela????o R n??o ?? reflexiva.\n");
    }

    set_free(universe);

    if (set_is_symmetric(relation)) {
        printf("A rela????o R ?? sim??trica.\n");
    } else {
        printf("A rela????o R n??o ?? sim??trica.\n");
    }

    if (set_is_antisymmetric(relation)) {
        printf("A rela????o R ?? antissim??trica.\n");
    } else {
        printf("A rela????o R n??o ?? antissim??trica.\n");
    }

    if (set_is_transitive(relation)) {
        printf("A rela????o R ?? transitiva.\n");
    } else {
        printf("A rela????o R n??o ?? transitiva.\n");
    }

    set_free(relation);
}