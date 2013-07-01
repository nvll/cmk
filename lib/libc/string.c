#include <string.h>


size_t strlen(const char *s)
{
    int cnt;
    for (cnt = 0; s[cnt] != '\0'; cnt++);
    return cnt;
}

char *strrev(char *s)
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

void *memset(void *b, int c, size_t len)
{
    if (!b) {
        return b;
    }

    for (size_t x = 0; x < len; x++) {
        ((char *)b)[x] = c;
    }

    return b;
}

void bzero(void *s, size_t n)
{
    memset(s, 0, n);
}
