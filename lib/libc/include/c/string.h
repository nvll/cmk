#pragma once
#include <c/libc.h>
#include <c/stddef.h>

#ifdef WITH_HOST_LIBC
#include <string.h>
#endif

__CPP_START

size_t  LIBC(strlen)(const char *s);
void*   LIBC(memset)(void *b, int c, size_t len);
char*   strrev(char *s);
// inline methods that aren't standard to libc

__CPP_END
