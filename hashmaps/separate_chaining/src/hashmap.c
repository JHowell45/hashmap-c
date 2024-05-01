#include <stdlib.h>

#include "bucket.h"
#include "hashmap.h"

hashmap *newHashmap(size_t capacity) {
    hashmap *map = malloc(sizeof(hashmap));
    map->capacity = capacity;
    map->items = calloc(map->capacity, sizeof(bucket*));
    return map;
}

void hashmapAdd(hashmap *map, bucket *item) {

}

void hashmapSearch(hashmap *map, const char *key) {

}

bucket *hashmapGet(hashmap *map, const char *key) {

}

void printHashmap(hashmap *map) {

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