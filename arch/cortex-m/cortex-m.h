#pragma once
#define __WEAK			__attribute__((weak))
#define __SECTION(x)	__attribute__((section(x)))

#ifdef CORTEX_M0
    #include <core_cm0.h>
#endif
#ifdef CORTEX_M0_PLUS
    #include <core_cm0plus.h>
#endif
#ifdef CORTEX_M3
    #include <core_cm3.h>
#endif
#ifdef CORTEX_M4
    #include <core_cm4.h>
#endif

typedef void * irq_handler_t;

struct cm_stack_frame {
	unsigned int r0;
	unsigned int r1;
	unsigned int r2;
	unsigned int r3;
	unsigned int r12;
	unsigned int lr;
	unsigned int pc;
	unsigned int xpsr;
};

#define writel(value, addr)     *((volatile unsigned int *)addr) = value
#define readl(addr)             *((volatile unsigned int *)addr)
#define rmwritel(value, addr)    writel(readl(addr) | value, addr)
