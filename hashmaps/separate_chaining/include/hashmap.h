#ifndef HASHMAP_H
#define HASHMAP_H

#include <stddef.h>
#include <stdbool.h>

#include "bucket.h"

typedef struct {
    size_t capacity;
    bucket **items;
} hashmap;

hashmap *newHashmap(size_t capacity);

static size_t hash(const char *key, size_t capacity);

void hashmapAdd(hashmap *map, bucket *item);

bool hashmapExists(hashmap *map, const char *key);

bucket *hashmapGet(hashmap *map, const char *key);

void printHashmap(hashmap *map);

void freeHashmap(hashmap *map);

typedef struct {
    size_t capacity;
    size_t count;
    bucket **items;
} resize_hashmap;

hashmap *newResizeHashmap(size_t capacity);

void resizeHashmapAdd(resize_hashmap *map, bucket *item);

bool hashmapExists(hashmap *map, const char *key);

bucket *hashmapGet(hashmap *map, const char *key);

void printResizeHashmap(resize_hashmap *map);

void freeResizehashmap(resize_hashmap *map);

#endif