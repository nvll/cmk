#include <c/ctype.h>

int LIBC(tolower)(int c)
{
    if (c >= 65 && c <= 90)
        return (c + 32);

    return c;
}

int LIBC(toupper)(int c)
{
    if (c >= 97 && c <= 122)
        return (c - 32);

    return c;
}

int LIBC(isdigit)(int c)
{
    if (c >= 48 && c <= 57)
        return 1;

    return 0;
}
