#include "encoding.h"
#include "common.h"

void encodeFile(const char *input, const char *output, char codes[][MAX_CHARS]) {
    FILE *in = fopen(input, "r");
    FILE *out = fopen(output, "w");

    if (!in || !out) {
        perror("File open error during encoding");
        if (in) fclose(in);
        if (out) fclose(out);
        return;
    }

    char ch;
    while ((ch = fgetc(in)) != EOF) {
        fputs(codes[(unsigned char)ch], out);
    }

    fclose(in);
    fclose(out);
}
