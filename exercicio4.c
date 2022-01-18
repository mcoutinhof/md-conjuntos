#include <time.h>
#include "set.h"
#include "utils.h"

set_t *set_reflexive_closure(set_t *set, set_t *relation) {
    set_t *closure = set_copy(relation);
    for (size_t i = 0; i < set_size(set); i++){
        pair_t reflection = {set_at_as(set, i, int), set_at_as(set, i, int)};
        if (!set_contains(closure, reflection)){
            set_insert(closure, reflection);
        }
    }
    return closure;
}

set_t *set_symmetric_closure(set_t *relation) {
    set_t *closure = set_copy(relation);
    for (size_t i = 0; i < set_size(relation); i++){
        pair_t symmetry = {set_at_as(relation, i, pair_t).second, set_at_as(relation, i, pair_t).first};
        if (!set_contains(closure, symmetry)){
            set_insert(closure, symmetry);
        }
    }
    return closure;
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
                .second = set_at_as(universe, rand() % set_size(universe), int),
        };
        set_insert(relation, pair);
    }
    print_relation("R", relation);

    printf("\nFeixo Reflexivo\n");
    set_t *reflexive_closure = set_reflexive_closure(universe, relation);
    print_relation("R*", reflexive_closure);

    set_free(reflexive_closure);

    printf("\nFeixo Simétrico\n");
    set_t *symmetric_closure = set_symmetric_closure(relation);
    print_relation("R*", symmetric_closure);
    set_free(symmetric_closure);

    set_free(universe);
    set_free(relation);
}