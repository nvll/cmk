#include <c/stdio.h>
#include <c/stdlib.h>
#include <c/string.h>
#include <c/stdint.h>
#include <c/ctype.h>
#include <c/stdarg.h>


static const char hex_tbl[] = "0123456789abcdef";

void LIBC(puts)(const char* s)
{
    _print_string(s);
    putchar('\n');
}

int LIBC(printf)(const char* __restrict__ format, ...)
{
    char buf[38];
    va_list ap;
    uint32_t flags, width;
    char c;
    va_start(ap, format);

    while ((c = *format++)) {
        flags = width = 0;
        memset(buf, 0, sizeof(buf));

        if (c != '%') {
            putchar(c);
            continue;
        }

parse_arg:
        c = *format++;

        if (c == '-') {
            flags |= STDIO_L_JUSTIFIED;
            goto parse_arg;
        }

        if (isdigit(c)) {
            if (c == '0') {
                flags |= STDIO_ZERO_PADDING;
            } else {
                width = (width * 10) + (c - '0');
            }

            goto parse_arg;
        }

        switch (c) {
            case 'B':
                flags |= STDIO_SPACE_BITS;

            case 'b':
                itob(va_arg(ap, uint32_t), buf, flags);
                _print_string(buf);
                break;

            case 's':
                _print_string(va_arg(ap, char *));
                break;

            case 'X':
                flags |= STDIO_UPPERCASE;

            case 'x':
            case 'p':
                to_hex(va_arg(ap, uint32_t), buf, width, flags);
                _print_string(buf);
                break;

            case 'd':
                flags |= STDIO_SIGNED;

            case 'u':
                itoa(va_arg(ap, uint32_t), buf, flags);
                _print_string(buf);
                break;

            case '%':
            default:
                putchar(c);
        }
    }

    va_end(ap);
    return 0;
}

/* Non-Standard libc functions */
void to_hex(unsigned int val, char* buf, int width, int flags)
{
    char c;
    int i = 0;

    do {
        c = hex_tbl[val & 0xF];
        buf[i++] = (flags & STDIO_UPPERCASE) ? toupper(c) : c;
        val >>= 4;
        width--;
    } while (val);

    while (width-- > 0)
        buf[i++] = (flags & STDIO_ZERO_PADDING) ? '0' : ' ';

    buf[i] = '\0';
    strrev(buf);
}

void itob(unsigned int val, char* buf, int flags)
{
    int pos = 0, bit = 0;

    do {
        buf[pos++] = (val & 0x1) ? '1' : '0';

        if ((flags & STDIO_SPACE_BITS) && bit++ == 7) {
            buf[pos++] = ' ';
            bit = 0;
        }
    } while (val >>= 1);

    if (flags & STDIO_ZERO_PADDING && bit != 0) {
        for (int y = bit; y < 8; y++) {
            buf[pos++] = '0';
        }
    }

    buf[pos++] = '\0';
    strrev(buf);
}

void _print_string(const char* s)
{
    for (const char* tmp = s; *tmp != '\n'; tmp++)
        putchar(*tmp);
}
