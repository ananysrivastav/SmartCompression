
#ifndef IO_MODULE_H
#define IO_MODULE_H

#include "huffman.h"

void encodeFile(const char *input, const char *output, char codes[][MAX_CHARS]);
void decodeFile(const char *encoded, const char *decoded, Node *root);

#endif // IO_MODULE_H
