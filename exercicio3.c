#include <time.h>
#include "set.h"
#include "relation.h"
#include "utils.h"

bool set_is_reflexive(set_int_t __restrict set, set_pair_int_t __restrict relation) {
    for (size_t i = 0; i < set->size; ++i) {
        if (!set_contains(relation, &(pair_int_t) {set->data[i], set->data[i]})) {
            return false;
        }
    }
    return true;
}

// diz se a relação é simetrica 
bool set_is_symmetric(set_pair_int_t __restrict relation) {
    for (size_t i = 0; i < relation->size; i++){
        // para cada par existente, procura pela sua simetria
        pair_int_t pair = relation->data[i];
        pair_int_t symmetry = { pair.second, pair.first };
        // se uma simetria não for encontrada, é falso que a relação é simetrica
        if (!set_pair_contains(relation, symmetry)){
            return false;
        }
    }
    return true;
}

// verifica se a relação é antissimetrica
bool set_is_antisymmetric(set_pair_int_t __restrict relation) {
    for (size_t i = 0; i < relation->size; i++){
        // para cada par existente, procura pela sua simetria apenas se os numeros forem diferentes
        pair_int_t pair = relation->data[i];
        if (pair.first != pair.second){
            pair_int_t symmetry = { pair.second, pair.first };
            // se contem uma simetria e o par é de elementos diferentes, é falso que seja antissimetrica
            if (set_pair_contains(relation, symmetry)){
                return false;
            }
        }
    }
    return true;
}

// verifica se a relação é transitiva
bool set_is_transitive(set_pair_int_t __restrict relation) {
    for (size_t i = 0; i < relation->size; i++){
        // verifica cada par na relação
        pair_int_t pair = relation->data[i];
        for (size_t j = 0; j < relation->size; j++){
            // procura os pares na relação que começa com o mesmo elemento que "pair" termina
            pair_int_t next_pair = relation->data[j];
            if (pair.second == next_pair.first){
                pair_int_t transition = {pair.first, next_pair.second};
                // por fim, certifica que o par que compoe a transição está presente na relação
                if (!set_pair_contains(relation, transition)){
                    return false;
                }
            }
        }
    }
    return true;
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