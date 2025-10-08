#include "frequency.h"
#include "common.h"

void calculateFrequency(const char *filename, int freq[]) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("File open error");
        return;
    }

    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        freq[(unsigned char)ch]++;
    }

    fclose(fp);
}
