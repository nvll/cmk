#include <c/ctype.h>
#include "units.h"

NEW_TEST(ctype)
{
    for (int c = '!'; c < '~'; c++)
        CHECKF(tolower(c) == libc_tolower(c), "%c != %c", tolower(c), libc_tolower(c));

    for (int c = '!'; c < '~'; c++)
        CHECKF(isdigit(c) == libc_isdigit(c), "%c != %c", isdigit(c), libc_isdigit(c));

    for (int c = '!'; c < '~'; c++)
        CHECKF(toupper(c) == libc_toupper(c), "%c != %c", toupper(c), libc_toupper(c));
}


