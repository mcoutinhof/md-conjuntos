#include "relation.h"

// define se o par passado está presente na relação
bool set_pair_contains(set_pair_int_t relation, pair_int_t pair){
    for (size_t i = 0; i < relation->size; i++){
        // se cada elemento for igual, ela existe, returna verdadeiro
        if ((relation->data[i].first == pair.first) && (relation->data[i].second == pair.second)){
            return true;
        }
    }
    // se nenhum for encontrado, retorna falso
    return false;
}