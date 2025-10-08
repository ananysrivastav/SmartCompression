#ifndef CODE_GENERATION_H
#define CODE_GENERATION_H

#include "huffman.h"
#include <string.h>

void generateCodes(Node *root, char *code, int depth, char codes[][MAX_CHARS]);

#endif // CODE_GENERATION_H
