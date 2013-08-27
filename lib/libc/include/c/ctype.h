#pragma once
#include <c/libc.h>

#ifdef WITH_HOST_LIBC
#include <ctype.h>
#endif

__CPP_START;

int LIBC(toupper)(int c);
int LIBC(tolower)(int c);
int LIBC(isdigit)(int c);

__CPP_END;
