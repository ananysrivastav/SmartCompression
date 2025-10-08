#include "common.h"
#include "frequency.h"
#include "huffman_tree.h"
#include "code_generation.h"
#include "encoding.h"
#include "decoding.h"

void freeHuffmanTree(Node *root) {
    if (!root) return;
    freeHuffmanTree(root->left);
    freeHuffmanTree(root->right);
    free(root);
}

int main() {
    int freq[MAX_CHARS] = {0};
    char codes[MAX_CHARS][MAX_CHARS];
    char tempCode[MAX_CHARS];

    calculateFrequency("input.txt", freq);
    Node *root = buildHuffmanTree(freq);
    
    if (root) {
        generateCodes(root, tempCode, 0, codes);
        encodeFile("input.txt", "encoded.txt", codes);
        decodeFile("encoded.txt", "decoded.txt", root);
        freeHuffmanTree(root); 
    } else {
        fprintf(stderr, "Error: Huffman tree could not be built (Empty input?)\n");
    }

    return 0;
}
