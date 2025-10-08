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
    const char *INPUT_FILE = "input.txt";
    const char *ENCODED_FILE = "encoded.txt";
    long original_size, encoded_size;

    // --- STEP 1: Get Original Size ---
    original_size = getFileSize(INPUT_FILE);
    if (original_size == -1) {
        fprintf(stderr, "Could not proceed without input file size.\n");
        return 1;
    }
    printf("\n[STATUS] Original file size: %ld bytes (%.2f KB)\n", 
           original_size, (double)original_size / 1024.0);

    // --- STEP 2: Core Huffman Workflow ---
    calculateFrequency(INPUT_FILE, freq);
    Node *root = buildHuffmanTree(freq);
    
    if (root) {
        generateCodes(root, tempCode, 0, codes);
        encodeFile(INPUT_FILE, ENCODED_FILE, codes);
        
        // --- STEP 3: Get Encoded Size ---
        encoded_size = getFileSize(ENCODED_FILE);
        
        // --- STEP 4: Print Results ---
        printf("[RESULT] Encoded file size: %ld bytes (%.2f KB)\n", 
               encoded_size, (double)encoded_size / 1024.0);
        
        if (original_size > 0) {
             double ratio = (double)encoded_size / original_size * 100.0;
             printf("[SUMMARY] Compression Ratio (Encoded/Original): %.2f%%\n", ratio);
             printf("[SUMMARY] Space Saved: %.2f KB\n", (double)(original_size - encoded_size) / 1024.0);
        }

        // --- STEP 5: Decode ---
        printf("[STATUS] Decoding encoded file...\n");
        decodeFile(ENCODED_FILE, "decoded.txt", root);
        printf("[STATUS] Decoding complete. Output in 'decoded.txt'.\n");
        
        freeHuffmanTree(root); 
    } else {
        fprintf(stderr, "Error: Huffman tree could not be built (Empty input?).\n");
    }

    return 0;
}
