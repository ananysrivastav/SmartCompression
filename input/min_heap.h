#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "common.h"

Node* createNode(char ch, int freq);
MinHeap* createMinHeap(int capacity);
void heapify(MinHeap *heap, int idx);
Node* extractMin(MinHeap *heap);
void insertHeap(MinHeap *heap, Node *node);

#endif
