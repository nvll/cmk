#pragma once

#ifdef __cplusplus
#define __CPP_START extern "C" {
#define __CPP_END }
#else
#define __CPP_START
#define __CPP_END
#endif

#ifdef WITH_HOST_LIBC
#define LIBC(name) libc_##name
#else
#define LIBC(name) name
#endif
