#include <c/string.h>

size_t LIBC(strlen)(const char *s)
{
    int cnt;

    for (cnt = 0; s[cnt] != '\0'; cnt++);

    return cnt;
}

void* LIBC(memset)(void *b, int c, size_t len)
{
    if (!b)
        return b;

    for (size_t x = 0; x < len; x++)
        ((char *)b)[x] = c;

    return b;
}

char* strrev(char *s)
{
    char tmp;
    int len = strlen(s);

    for (int x = 0; x < len / 2; x++) {
        tmp = s[x];
        s[x] = s[len-x-1];
        s[len-x-1] = tmp;
    }

    return s;
}

