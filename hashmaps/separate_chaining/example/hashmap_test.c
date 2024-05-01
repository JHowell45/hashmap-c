#include <stdio.h>

#include "bucket.h"
#include "hashmap.h"

const size_t MAP_SIZE = 10;
const size_t ARRAY_SIZE = 10;
const size_t SEARCH_ARRAY_SIZE = 11;

int main(void) {
    hashmap *map = newHashmap(MAP_SIZE);

    char keys[ARRAY_SIZE][10] = {
        "cat",
        "dog",
        "bat",
        "elephant",
        "rat",
        "lion",
        "wolf",
        "giraffe",
        "bobcat",
        "tiger",
    };

    for (int i = 0; i < ARRAY_SIZE; i++) {
        bucket *item = newBucket(keys[i], "animal");
        printBucket(item);
        hashmapAdd(map, item);
    }
    printHashmap(map);

    char searchKeys[SEARCH_ARRAY_SIZE][10] = {
        "cat",
        "dog",
        "bat",
        "elephant",
        "rat",
        "lion",
        "wolf",
        "giraffe",
        "bobcat",
        "tiger",
        "one"
    };

    for (int i = 0; i < SEARCH_ARRAY_SIZE; i++) {
        const char *search = searchKeys[i];
        printf("Key '%s' exists in map: %d\n", search, hashmapExists(map, search));
    }

    freeHashmap(map);
    return 0;
}