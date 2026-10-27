#ifndef _ITEM_H_
#define _ITEM_H

#define ITEM_KEY_SIZE 20
#define ITEM_VECTOR_INITIAL_CAPACITY 10

typedef struct {
    int x;
    int y;
} item;

typedef struct
{
    item *items;
    size_t size;
    size_t capacity;
} item_vector;

item_vector *item_vector_create();
void item_vector_free(item_vector *vector);
void item_vector_clear(item_vector *vector);
item *item_vector_get(item_vector *vector, size_t index);
size_t item_vector_is_empty(item_vector *vector);
void item_vector_push_back(item_vector *vector, item *item);
void item_vector_pop_back(item_vector *vector);
size_t item_vector_size(item_vector *vector);

#endif