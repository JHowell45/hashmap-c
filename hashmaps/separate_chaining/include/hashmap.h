#ifndef HASHMAP_H
#define HASHMAP_H

#include <stddef.h>

#include "bucket.h"

typedef struct {
    size_t capacity;
    bucket **items;
} hashmap;

hashmap *newHahsmap(size_t capacity);

void hashmapAdd(hashmap *map, bucket *item);

void hashmapSearch(hashmap *map, const char *key);

bucket *hashmapGet(hashmap *map, const char *key);

void printHashmap(hashmap *map);

void freeHashmap(hashmap *map);

#endif