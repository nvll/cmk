#include <c/ctype.h>
#include "units.h"

MAKE_TEST(tolower)
{
    for (int c = '!'; c < '~'; c++)
        ASSERT_EQ(tolower(c), libc_tolower(c), "Testing tolower()");
}

MAKE_TEST(isdigit)
{
    for (int c = '!'; c < '~'; c++)
        ASSERT_EQ(isdigit(c), libc_isdigit(c), "Testing isdigit()");
}

MAKE_TEST(toupper)
{
    for (int c = '!'; c < '~'; c++)
        ASSERT_EQ(toupper(c), libc_toupper(c), "Testing toupper()");
}
