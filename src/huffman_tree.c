#include "huffman_tree.h"
#include "min_heap.h"
#include "common.h"

Node* buildHuffmanTree(int freq[]) {
    MinHeap *heap = createMinHeap(MAX_CHARS);
    for (int i = 0; i < MAX_CHARS; i++) {
        if (freq[i] > 0)
            insertHeap(heap, createNode((char)i, freq[i]));
    }

    while (heap->size > 1) {
        Node *left = extractMin(heap);
        Node *right = extractMin(heap);
        Node *merged = createNode('$', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        insertHeap(heap, merged);
    }

    Node* root = extractMin(heap);
    freeMinHeap(heap);
    return root;
}
