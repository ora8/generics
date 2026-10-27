#include <stdio.h>

#include "item.h"

int main() {

    item_vector *vector = item_vector_create();
    for (size_t i = 0; i < 100; i++)
    {
        item item = {i, i + 100};
        item_vector_push_back(vector, &item);
    }

    for (size_t i = 0; i < item_vector_size(vector); i++) {
        item *item = item_vector_get(vector, i);
        printf("item {%d, %d}\n", item->x, item->y);
    }
    return 0;
}