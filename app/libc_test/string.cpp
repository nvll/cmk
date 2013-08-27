#include <c/string.h>
#include "units.h"

NEW_TEST(strlen)
{
    char s[] = "1234567890";

    for (int i = 10; i > 0; i--) {
        s[i] = '\0';
        CHECK(strlen(s) == libc_strlen(s));
    }
}
