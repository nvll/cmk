OUTPUT := stellaris
MODULE_DEPS := \
	lib/libc \
	lib/TI \
	lib/CMSIS \
	arch/cortex-m \
	board/stellaris

include make/arm-m-binary.mk
