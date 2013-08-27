#pragma once
#include <c/libc.h>

#ifdef WITH_HOST_LIBC
#include <stdlib.h>
#endif

/* Non-Standard libc functions */
void itoa(unsigned int val, char* buf, int flags);
void itob(unsigned int val, char* buf, int flags);
