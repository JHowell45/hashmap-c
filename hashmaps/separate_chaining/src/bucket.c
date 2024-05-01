#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "bucket.h"

bucket *newBucket(const char *key, const char *value) {
    bucket *item = malloc(sizeof(bucket));
    item->key = strdup(key);
    item->value = strdup(value);
    item->next = NULL;
    return item;
}

void bucketAdd(bucket *item, bucket *next) {
    bucket *temp = item;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = next;
}

void printBucket(bucket *item) {
    printf("{ '%s' => '%s' }", item->key, item->value);
    bucket *next = item->next;
    while (next != NULL) {
        printf(" -> { '%s' => '%s' }", next->key, next->value);
        next = next->next;
    }
    printf("\n");
}

void freeBucket(bucket *item) {
    if (item->next != NULL) {
        freeBucket(item->next);
    }
    free(item->key);
    free(item->value);
    free(item);
}