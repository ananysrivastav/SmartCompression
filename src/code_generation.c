void generateCodes(Node *root, char *code, int depth, char codes[][MAX_CHARS]) {
    if (!root) return;

    if (!root->left && !root->right) {
        code[depth] = '\0';
        strcpy(codes[(unsigned char)root->ch], code);
        return;
    }

    code[depth] = '0';
    generateCodes(root->left, code, depth + 1, codes);

    code[depth] = '1';
    generateCodes(root->right, code, depth + 1, codes);
}
