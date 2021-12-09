#include <time.h>
#include "set.h"
#include "utils.h"

set_pair_int_t set_reflexive_closure(set_int_t __restrict set, set_pair_int_t __restrict relation) {
    relation = set_copy(relation);
    // TODO: code
    return relation;
}

set_pair_int_t set_symmetric_closure(set_pair_int_t __restrict relation) {
    relation = set_copy(relation);
    // TODO: code
    return relation;
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

    set_free(universe);

    printf("\nFeixo Reflexivo\n");
    set_pair_int_t reflexive_closure = set_reflexive_closure(universe, relation);
    print_closure("R*", reflexive_closure, relation);

    set_free(reflexive_closure);

    printf("\nFeixo Simétrico\n");
    set_pair_int_t symmetric_closure = set_symmetric_closure(relation);
    print_closure("R*", symmetric_closure, relation);
    set_free(symmetric_closure);

    set_free(relation);
}