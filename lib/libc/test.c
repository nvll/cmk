#include <dlfcn.h>

int main (int argc, char *argv[])
{

	void *handle;
	handle = dlopen("./libc.dylib", RTLD_NOW);
	if (!handle)
		return -1;
	
	void (*puts)(const char *s) = dlsym(handle, "puts");
	int (*printf)(const char * format, ...) = dlsym(handle, "printf");

	
	printf("Hex uppercase: '0x%X' = '0xFFAAFFAA'\n", 0xFFAAFFAA);
	printf("Hex lowercase: '0x%x' = '0xffaaffaa'\n", 0xFFAAFFAA);
	printf("hex with width: '0x%8X' = '0x     FFF'\n", 0xFFF);
	printf("hex with width and 0s: 0x%08X\n", 0xFFF);
	printf("Hex 0: 0x%x\n", 0);
	printf("Hex 1: 0x%x\n", 1);
	printf("Hex -1: 0x%x\n", -1);
	printf("Decimal positive unsigned: %u\n", 65536);
	printf("Decimal positive signed: %d\n", 65536);
	printf("Decimal negative unsigned: %u\n",  -65536);
	printf("Decimal negative signed: %d\n",  -65536);
	printf("Binary string odd: %b\n", 0x3AFC);
	printf("Binary string odd padding: 0%b\n", 0x3AFC);
	printf("Binary string odd spaces: %B\n", 0x3AFC3AFC);
	printf("Binary string odd spaces padding: %0B\n", 0x3AFC3AFC);
	return 0;
}
