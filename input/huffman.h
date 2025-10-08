#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARS 256

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

#endif // HUFFMAN_H
