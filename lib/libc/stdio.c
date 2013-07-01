#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#include <ctype.h>

#define PRINT_STRING(x) for (const char *_tmp = x; *_tmp != '\0'; _tmp++){ putchar(*_tmp); }

extern int putchar(int c);
int putc(int c)
{
	putchar(c);
	return c;
}

#define STDIO_SIGNED		(1 << 0)
#define STDIO_UPPERCASE		(1 << 1)
#define STDIO_ZERO_PADDING	(1 << 2)
#define STDIO_L_JUSTIFIED	(1 << 3)
#define STDIO_SPACE_BITS	(1 << 4)

static const char hex_tbl[] = "0123456789abcdef";
void to_hex(unsigned int val, char *buf, int width, int flags)
{
	char c;
	int i = 0;
	
	do {
		c = hex_tbl[val & 0xF];
		buf[i++] = (flags & STDIO_UPPERCASE) ? toupper(c) : c;
		val >>= 4;
		width--;
	} while (val);

	while (width-- > 0) {
		buf[i++] = (flags & STDIO_ZERO_PADDING) ? '0' : ' ';
	}
	buf[i] = '\0';
	strrev(buf);
}

void itoa(unsigned int val, char *buf, int flags)
{
	unsigned int negative = 0, pos = 0;

	if (flags & STDIO_SIGNED) {
		if (((int)val) < 0) {
			negative = 1;
			val *= -1;
		}
	}
	
	do {
		buf[pos++] = '0' + (val % 10);
	} while ((val /= 10));
	
	if (negative) {
		buf[pos++] = '-';
	}

	buf[pos] = 0;
	strrev(buf);
}

void itob(unsigned int val, char *buf, int flags)
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


void puts(const char *s)
{
	PRINT_STRING(s);
	putchar('\n');
}

	
int printf(const char * restrict format, ...)
{
	char buf[38];
	va_list ap;
	uint32_t flags, width;
	char c;

	va_start(ap, format);
	while((c = *format++)) {
		flags = width = 0;
		bzero(buf, sizeof(buf));
		
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

		switch(c) {
			case 'B':
				flags |= STDIO_SPACE_BITS;
			case 'b':
				itob(va_arg(ap, uint32_t), buf, flags);
				PRINT_STRING(buf);
				break;
			case 's':
				PRINT_STRING(va_arg(ap, char *));
				break;
			case 'X':
				flags |= STDIO_UPPERCASE;
			case 'x':
			case 'p':
				to_hex(va_arg(ap, uint32_t), buf, width, flags);
				PRINT_STRING(buf);
				break;
			case 'd':
				flags |= STDIO_SIGNED;
			case 'u':
				itoa(va_arg(ap, uint32_t), buf, flags);
				PRINT_STRING(buf);
				break;
			case '%':
			default:
				putchar(c);
		}
		
	}
	va_end(ap);
	return 0;
}
