#include "decoding.h"
#include "common.h"

void decodeFile(const char *encoded, const char *decoded, Node *root) {
    FILE *in = fopen(encoded, "r");
    FILE *out = fopen(decoded, "w");

    if (!in || !out) {
        perror("File open error during decoding");
        if (in) fclose(in);
        if (out) fclose(out);
        return;
    }

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
