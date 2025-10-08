#include "common.h"

// Function to get file size in bytes
long getFileSize(const char *filename) {
    FILE *fp = fopen(filename, "r");
    long size = -1;

    if (fp == NULL) {
        perror("Error opening file for size check");
        return -1;
    }

    // Seek to the end of the file
    if (fseek(fp, 0, SEEK_END) == 0) {
        // Get the current position, which is the size
        size = ftell(fp);
    }
    
    fclose(fp);
    return size;
}
