void encodeFile(const char *input, const char *output, char codes[][MAX_CHARS]) {
    FILE *in = fopen(input, "r");
    FILE *out = fopen(output, "w");

    char ch;
    while ((ch = fgetc(in)) != EOF) {
        fputs(codes[(unsigned char)ch], out);
    }

    fclose(in);
    fclose(out);
}
