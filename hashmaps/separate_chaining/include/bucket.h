#ifndef BUCKET_H
#define BUCKET_H

typedef struct bucket_t bucket;

struct bucket_t {
    char *key;
    char *value;
    bucket *next;
};

bucket *newBucket(const char *key, const char *value);

void bucketAdd(bucket *item, bucket *next);

void printBucket(bucket *item);

void freeBucket(bucket *item);

#endif