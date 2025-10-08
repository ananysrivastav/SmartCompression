#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "huffman.h"

Node* createNode(char ch, int freq);
MinHeap* createMinHeap(int capacity);
void insertHeap(MinHeap *heap, Node *node);
Node* extractMin(MinHeap *heap);
void heapify(MinHeap *heap, int idx);
void freeTree(Node *root);

#endif // MIN_HEAP_H
