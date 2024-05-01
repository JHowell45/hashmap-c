#include <stdio.h>

#include "bucket.h"

int main(void) {
    bucket *item = newBucket("hello", "world");
    bucket *item2 = newBucket("goodbye", "world");
    bucket *item3 = newBucket("welcome", "world");
    printBucket(item);
    bucketAdd(item, item2);
    printBucket(item);
    bucketAdd(item, item3);
    printBucket(item);

    freeBucket(item);
    return 0;
}