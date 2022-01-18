#include <time.h>
#include "set.h"
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

// diz se a relação é simetrica 
bool set_is_symmetric(set_t *relation) {
    for (size_t i = 0; i < set_size(relation); i++){
        // para cada par existente, procura pela sua simetria
        pair_t pair = set_at_as(relation, i, pair_t);
        pair_t symmetry = { pair.second, pair.first };
        // se uma simetria não for encontrada, é falso que a relação é simétrica
        if (!set_contains(relation, symmetry)){
            return false;
        }
    }
    return true;
}

// verifica se a relação é antissimetrica
bool set_is_antisymmetric(set_t *relation) {
    for (size_t i = 0; i < set_size(relation); i++){
        // para cada par existente, procura pela sua simetria apenas se os numeros forem diferentes
        pair_t pair = set_at_as(relation, i, pair_t);
        if (pair.first != pair.second){
            pair_t symmetry = { pair.second, pair.first };
            // se contem uma simetria e o par é de elementos diferentes, é falso que seja antissimetrica
            if (set_contains(relation, symmetry)){
                return false;
            }
        }
    }
    return true;
}

// verifica se a relação é transitiva
bool set_is_transitive(set_t *relation) {
    for (size_t i = 0; i < set_size(relation); i++){
        // verifica cada par na relação
        pair_t pair = set_at_as(relation, i, pair_t);
        for (size_t j = 0; j < set_size(relation); j++){
            // procura os pares na relação que começa com o mesmo elemento que "pair" termina
            pair_t next_pair = set_at_as(relation, j, pair_t);
            if (pair.second == next_pair.first){
                pair_t transition = {pair.first, next_pair.second};
                // por fim, certifica que o par que compoe a transição está presente na relação
                if (!set_contains(relation, transition)){
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
                .second = set_at_as(universe, rand() % set_size(universe), int),
        };
        set_insert(relation, pair);
    }
    print_relation("R", relation);

    if (set_is_reflexive(universe, relation)) {
        printf("\nA relação R é reflexiva.\n");
    } else {
        printf("\nA relação R não é reflexiva.\n");
    }

    set_free(universe);

    if (set_is_symmetric(relation)) {
        printf("A relação R é simétrica.\n");
    } else {
        printf("A relação R não é simétrica.\n");
    }

    if (set_is_antisymmetric(relation)) {
        printf("A relação R é antissimétrica.\n");
    } else {
        printf("A relação R não é antissimétrica.\n");
    }

    if (set_is_transitive(relation)) {
        printf("A relação R é transitiva.\n");
    } else {
        printf("A relação R não é transitiva.\n");
    }

    set_free(relation);
}