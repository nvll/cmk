#include <c/stdio.h>
#include "units.h"

MAKE_TEST(sprintf)
{
    char buf1[25], buf2[25];

    sprintf(buf1, "%d", 100);
    libc_sprintf(buf2, "%d", 100);
    //CHECK(buf1 == buf2);
}
