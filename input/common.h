#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256

// Add the file size function prototype
long getFileSize(const char *filename);

typedef struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
} Node;

typedef struct MinHeap {
    int size;
    int capacity;
    Node **array;
} MinHeap;

#endif
