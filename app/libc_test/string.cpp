#include <c/string.h>
#include "units.h"

MAKE_TEST(strlen)
{
    char s[256];

    ASSERT_EQ(0, 1, "Intentional assert");

    /* Keep shrinking the string and ensuring that both strlens match up */
    for (int i = sizeof(s); i > 0; i--) {
        s[i] = '\0';
        TEST_EQ(strlen(s), libc_strlen(s), NULL);
    }

}
