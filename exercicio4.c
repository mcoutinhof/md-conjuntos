#include <time.h>
#include "set.h"
#include "utils.h"
#include "relation.h"

set_pair_int_t set_reflexive_closure(set_int_t __restrict set, set_pair_int_t __restrict relation) {
    set_pair_int_t closure = set_copy(relation);
    for (size_t i = 0; i < set->size; i++){
        pair_int_t reflection = {set->data[i], set->data[i]};
        if (!set_pair_contains(closure, reflection)){
            set_insert(closure, &reflection);
        }
    }
    return closure;
}

set_pair_int_t set_symmetric_closure(set_pair_int_t __restrict relation) {
    set_pair_int_t closure = set_copy(relation);
    for (size_t i = 0; i < relation->size; i++){
        pair_int_t symmetry = {relation->data[i].second, relation->data[i].first};
        if (!set_pair_contains(closure, symmetry)){
            set_insert(closure, &symmetry);
        }
    }
    return closure;
}

int main() {
    srand(time(NULL));

    set_int_t universe = new_set(int, 5);
    for (int i = 0; i < universe->capacity; ++i) {
        set_insert(universe, &i);
    }
    print_set("U", universe);

    set_pair_int_t relation = new_set(pair_int_t, 10);
    while (relation->size < relation->capacity) {
        set_insert(relation, &(pair_int_t) {
                .first = universe->data[rand() % universe->size],
                .second = universe->data[rand() % universe->size],
        });
    }
    print_relation("R", relation);

    printf("\nFeixo Reflexivo\n");
    set_pair_int_t reflexive_closure = set_reflexive_closure(universe, relation);
    print_closure("R*", reflexive_closure, relation);

    set_free(reflexive_closure);

    printf("\nFeixo Simétrico\n");
    set_pair_int_t symmetric_closure = set_symmetric_closure(relation);
    print_closure("R*", symmetric_closure, relation);
    set_free(symmetric_closure);

    set_free(universe);
    set_free(relation);
}