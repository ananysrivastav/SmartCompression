void decodeFile(const char *encoded, const char *decoded, Node *root) {
    FILE *in = fopen(encoded, "r");
    FILE *out = fopen(decoded, "w");

    Node *curr = root;
    char bit;
    while ((bit = fgetc(in)) != EOF) {
        curr = (bit == '0') ? curr->left : curr->right;

        if (!curr->left && !curr->right) {
            fputc(curr->ch, out);
            curr = root;
        }
    }

    fclose(in);
    fclose(out);
}
