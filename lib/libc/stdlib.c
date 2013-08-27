#include <c/stdlib.h>
#include <c/string.h>

void itoa(unsigned int val, char *buf, int flags)
{
    unsigned int negative = 0, pos = 0;

    if (flags & 0x1) {
        if (((int)val) < 0) {
            negative = 1;
            val *= -1;
        }
    }

    do {
        buf[pos++] = '0' + (val % 10);
    } while ((val /= 10));

    if (negative)
        buf[pos++] = '-';

    buf[pos] = 0;
    strrev(buf);
}

