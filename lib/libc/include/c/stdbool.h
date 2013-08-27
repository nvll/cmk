#pragma once
#ifdef WITH_HOST_LIBC
#include <stdbool.h>
#else
#define bool _Bool
#define true 1
#define false 0
#endif
