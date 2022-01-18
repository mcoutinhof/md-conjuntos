#pragma once

#include <stdlib.h>
#include <stdbool.h>

/**
 * Cria um conjunto que inicialmente armazena até `initial_capacity` elementos do tipo `type`.
 */
#define new_set(type, initial_capacity) set_create(sizeof(type), initial_capacity)

/**
 * Destrói o conjunto `set`, liberando a memória alocada.
 */
#define set_free(set) set_destroy(set)

/**
 * Acessa diretamente um elemento do conjunto `set` na posição `index` como uma variável do tipo `type`.
 */
#define set_at_as(set, index, type) (*(type *) set_at(set, index))

/**
 * Acrescenta `value` ao fim do conjunto `set`.
 */
#define set_insert(set, value) ({    \
    __auto_type __value__ = (value); \
    set_insert_(set, &__value__);    \
})

/**
 * Checa se `value` está presente no conjunto `set`.
 */
#define set_contains(set, value) ({  \
    __auto_type __value__ = (value); \
    set_contains_(set, &__value__);  \
})

typedef struct set_t set_t;

/**
 * Cria um conjunto que inicialmente armazena até `initial_capacity` elementos com `type_size` bytes de tamanho.
 */
set_t *set_create(size_t type_size, size_t initial_capacity);

/**
 * Destrói o conjunto `set`, liberando a memória alocada.
 */
void set_destroy(set_t *set);

/**
 * Retorna o endereço para o elemento do conjunto `set` na posição `index`.
 */
void *set_at(set_t *set, size_t index);

/**
 * Retorna o array primitiva usada pelo conjunto.
 */
void *set_data(set_t *set);

/**
 * Retorna o tamanho em bytes dos elementos que o conjunto armazena.
 */
size_t set_type_size(set_t *set);

/**
 * Checa se o conjunto `set` está vazio.
 */
bool set_empty(set_t *set);

/**
 * Retorna a quantidade de elementos em `set`.
 */
size_t set_size(set_t *set);

/**
 * Aumenta a capacidade do conjunto `set` para `req_capacity` elementos, se a capacidade atual já não for maior ou igual.
 */
void set_reserve(set_t *set, size_t req_capacity);

/**
 * Retorna a quantidade de elementos que `set` pode armazenar até ter que alocar mais memória.
 */
size_t set_capacity(set_t *set);

/**
 * Reduz a capacidade de `set` para o seu tamanho.
 */
void set_shrink_to_fit(set_t *set);

/**
 * Apaga todos os elementos do conjunto `set`. A capacidade permanece inalterada.
 */
void set_clear(set_t *set);

/**
 * Acrescenta o valor apontado por `pointer` ao fim do conjunto `set`.
 */
void set_insert_(set_t *set, const void *pointer);

/**
 * Apaga o elemento do conjunto `set` na posição `index`.
 */
void set_erase(set_t *set, size_t index);

/**
 * Apaga `n` elementos do conjunto `set` começando do índice `index`.
 */
void set_erase_n(set_t *set, size_t index, size_t n);

/**
 * Apaga do conjunto `set` os elementos do índice `fromIndex` até `toIndex` (exclusive).
 */
void set_erase_range(set_t *set, size_t fromIndex, size_t toIndex);

/**
 * Checa se o valor apontado por `pointer` está presente no conjunto `set`.
 */
bool set_contains_(set_t *set, const void *pointer);

/**
 * Redimensiona o conjunto `new_size` para conter `new_size` elementos.
 */
void set_resize(set_t *set, size_t new_size);

/**
 * Ordena o conjunto `set` usando a função `compar` para comparar seus elementos.
 */
void set_sort(set_t *set, __compar_fn_t compar);

/**
 * Cria uma cópia do conjunto `set`.
 */
set_t *set_copy(set_t *set);