#ifndef __ALIBC_STRING_H
#define __ALIBC_STRING_H
#include <stddef.h>

size_t strlen(const char *s);
char *strrev(char *s);
void *memset(void *b, int c, size_t len);
void bzero(void *s, size_t n);

#endif
