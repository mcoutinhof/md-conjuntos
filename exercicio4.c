#include <time.h>
#include "set.h"
#include "utils.h"

set_pair_int_t set_reflexive_closure(set_int_t __restrict set, set_pair_int_t __restrict rel) {
    rel = set_copy(rel);
    // TODO: code
    return rel;
}

set_pair_int_t set_symmetric_closure(set_pair_int_t __restrict rel) {
    rel = set_copy(rel);
    // TODO: code
    return rel;
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

    printf("\nFeixo Reflexivo\n");
    set_pair_int_t refl = set_reflexive_closure(universe, rel);
    print_set_pair_int_t("R*", refl);

    printf("\nFeixo Simétrico\n");
    set_pair_int_t symm = set_symmetric_closure(rel);
    print_set_pair_int_t("R*", refl);

    set_free(universe);
    set_free(rel);
}