int main() {
    int freq[MAX_CHARS] = {0};
    char codes[MAX_CHARS][MAX_CHARS];
    char tempCode[MAX_CHARS];

    calculateFrequency("input.txt", freq);
    Node *root = buildHuffmanTree(freq);
    generateCodes(root, tempCode, 0, codes);
    encodeFile("input.txt", "encoded.txt", codes);
    decodeFile("encoded.txt", "decoded.txt", root);

    return 0;
}
