#include <stdlib.h>
#include <stdio.h>

#include "bucket.h"
#include "hashmap.h"

const size_t ARRAY_SIZE = 10;

static const char alphabet[27] = {
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N',
    'O','P','Q','R','S','T','U','V','W','X','Y','Z','\0' 
};

char *generateRandomString(size_t length) {
    char *str = calloc(length+1, sizeof(char));
    for (size_t i = 0; i < length; i++) {
        str[i] = alphabet[rand() % 26];
    }
    str[length] = '\0';
    return str;
}

char **generateKeys(size_t numberOfKeys, size_t stringLength) {
    char **keys = calloc(numberOfKeys, sizeof(char*));
    for (int i = 0; i < numberOfKeys; i++) {
        keys[i] = generateRandomString(stringLength);
    }
    return keys;
}

void testExists(hashmap *map, char **searchKeys, size_t arraySize) {
    for (int i = 0; i < arraySize; i++) {
        const char *search = searchKeys[i];
        printf("Key '%s' exists in map: %d\n", search, hashmapExists(map, search));
    }
}

void testGets(hashmap *map, char **searchKeys, size_t arraySize) {
    for (int i = 0; i < arraySize; i++) {
        const char *search = searchKeys[i];
        bucket *item = hashmapGet(map, search);
        if (item != NULL) {
            printf("Key '%s': ", search);
            printBucket(item);
        } else {
            printf("Key '%s': NONE\n", search);
        }
    }
}

void basicTest(void) {
    hashmap *map = newHashmap(1000);

    char **keys = generateKeys(ARRAY_SIZE, 10);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        bucket *item = newBucket(keys[i], "animal");
        // printBucket(item);
        hashmapAdd(map, item);
    }
    printHashmap(map);

    char **searchKeys = generateKeys(ARRAY_SIZE, 10);

    testExists(map, keys, ARRAY_SIZE);
    testExists(map, searchKeys, ARRAY_SIZE);

    testGets(map, keys, ARRAY_SIZE);
    testGets(map, searchKeys, ARRAY_SIZE);

    freeHashmap(map);
}

void bigTest(void) {
    hashmap *map = newHashmap(10000);
}

int main(void) {
    basicTest();
    return 0;
}