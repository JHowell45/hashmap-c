#include <stdlib.h>

#include "hashmap.h"

hashmap *newHashmap(size_t capacity) {
    hashmap *map = malloc(sizeof(hashmap));
    map->capacity = capacity;
    map->items = calloc(map->capacity, sizeof(bucket*));
    return map;
}