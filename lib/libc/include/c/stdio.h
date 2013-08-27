#pragma once
#include <c/libc.h>

#ifdef WITH_HOST_LIBC
#include <stdio.h>
#endif

__CPP_START

// TODO: kill these off in the printf refactor
#define STDIO_SIGNED		(1 << 0)
#define STDIO_UPPERCASE		(1 << 1)
#define STDIO_ZERO_PADDING	(1 << 2)
#define STDIO_L_JUSTIFIED	(1 << 3)
#define STDIO_SPACE_BITS	(1 << 4)

/* putchar is defined via a target (architecture based. libc on host, or maybe in uart code
 * target side */
extern int putchar(int);
void LIBC(puts)(const char* s);
int  LIBC(printf)(const char* __restrict__ format, ...);

/* Non-Standard libc functions */
void to_hex(unsigned int val, char* buf, int width, int flags);
void _print_string(const char* s);

__CPP_END
