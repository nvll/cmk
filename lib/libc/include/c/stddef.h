#pragma once

#ifdef WITH_HOST_LIBC
#include <stddef.h>
#else
typedef unsigned long size_t;
typedef long ssize_t;
#define NULL 0
#endif
