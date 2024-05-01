#include <stdio.h>

#include "bucket.h"
#include "hashmap.h"

const size_t MAP_SIZE = 10;
const size_t ARRAY_SIZE = 10;

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
        hashmapAdd(map, item);
    }
    printHashmap(map);

    char searchKeys[ARRAY_SIZE][10] = {
        "cat",
        "dog",
        "bat",
        "one",
        "rat",
        "two",
        "wolf",
        "five",
        "bobcat",
        "seven",
    };

    for (int i = 0; i < ARRAY_SIZE; i++) {
        const char *search = searchKeys[i];
        printf("Key '%s' exists in map: %d\n", search, hashmapExists(map, search));
    }

    freeHashmap(map);
    return 0;
}