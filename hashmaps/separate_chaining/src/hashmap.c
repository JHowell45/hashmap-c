#include <stdlib.h>
#include <stdio.h>

#include "bucket.h"
#include "hashmap.h"

hashmap *newHashmap(size_t capacity) {
    hashmap *map = malloc(sizeof(hashmap));
    map->capacity = capacity;
    map->items = calloc(map->capacity, sizeof(bucket*));
    return map;
}

static size_t hash(const char *key, size_t capacity) {
    size_t index = 0;
    for (const char *i = key; *i != '\0'; i++) {
        index += *i;
    }
    return index % capacity;
}

void hashmapAdd(hashmap *map, bucket *item) {
    size_t index = hash(item->key, map->capacity);
    if (map->items[index] == NULL) {
        map->items[index] = item;
    } else {
        bucketAdd(map->items[index], item);
    }
}

void hashmapSearch(hashmap *map, const char *key) {

}

// bucket *hashmapGet(hashmap *map, const char *key) {

// }

void printHashmap(hashmap *map) {
    printf("hashmap {\n");
    for (size_t i = 0; i < map->capacity; i++) {
        bucket *item = map->items[i];
        if (item != NULL) {
            printf("\t%zu: ", i);
            printBucket(item);
        }
    }
    printf("}\n");
}

void freeHashmap(hashmap *map) {
    for (int i = 0; i < map->capacity; i++) {
        bucket *item = map->items[i];
        if (item != NULL) {
            freeBucket(item);
        }
    }
    free(map->items);
    free(map);
}