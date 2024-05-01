#include <stdio.h>

#include "hashmap.h"

int main(void) {
    hashmap *map = newHashmap(100);

    freeHashmap(map);
    return 0;
}