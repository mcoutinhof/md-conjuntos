#include <time.h>
#include "vector.h"

int main() {
    auto universe = new_vector(int, 51);
    for(int i = 0; i < 51; ++i)
        vector_insert(universe, i);

    auto setA = new_vector(int, 10);
    for (int i = 0; i < 10; ++i)
        vector_insert(setA, universe->data[rand() % (universe->size + 1)]);

    auto setB = new_vector(int, 10);
    for (int i = 0; i < 10; ++i)
        vector_insert(setB, universe->data[rand() % (universe->size + 1)]);


    return EXIT_SUCCESS;
}