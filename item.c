#include <stdlib.h>

#include "item.h"

item_vector *item_vector_create() {
    item_vector *vector = malloc(sizeof(item_vector));
    if (!vector) {
        return NULL;
    }
    vector->items = malloc(ITEM_VECTOR_INITIAL_CAPACITY * sizeof(item));
    if (!vector->items) {
        free(vector);
        return NULL;
    }
    vector->size = 0;
    vector->capacity = ITEM_VECTOR_INITIAL_CAPACITY;
    return vector;   
}

void item_vector_free(item_vector *vector) {
    if (!vector) {
        return;
    }
    free(vector->items);
    free(vector);
}


void item_vector_clear(item_vector *vector) {
    vector->size = 0;
}

item *item_vector_get(item_vector *vector, size_t index)
{
    if (index >= vector->size) {
        return NULL;
    }
    return vector->items + index;
}

size_t item_vector_is_empty(item_vector *vector) {
    return vector->size = 0;
}

static void item_vector_resize(item_vector *vector) {
    size_t new_capacity = vector->capacity + ITEM_VECTOR_INITIAL_CAPACITY;
    vector->items = realloc(vector->items, new_capacity * sizeof(item));
    vector->capacity = new_capacity;
}

void item_vector_push_back(item_vector *vector, item *item) {
    if (vector->size == vector->capacity) {
        item_vector_resize(vector);
    }
    vector->items[vector->size] = *item;
    vector->size++;
}

void item_vector_pop_back(item_vector *vector)
{
    if (vector->size == 0) {
        return;
    }
    vector->size--;
}

size_t item_vector_size(item_vector *vector)
{
    return vector->size;
}