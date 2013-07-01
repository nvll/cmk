// vim expandtab:ts=4:sw=4:sts=4
#include <irqn.h>
#include <cortex-m.h>
#include <stdio.h>
#include <stddef.h>

#define CM_HANDLER(x) &x##_handler
#define DEFINE_CM_HANDLER(x) \
void __WEAK x##_handler(struct cm_stack_frame *frame) \
{ \
    __disable_irq(); \
    printf("\n%s exception, dumping frame:\n", #x); \
    cm_dump_frame(frame); \
    while(1) ; \
}

static unsigned char cm_stack[2048];
extern void main(void);

extern uint32_t __text_end__;
extern uint32_t __data_start__;
extern uint32_t __data_end__;
extern uint32_t __bss_start__;
extern uint32_t __bss_end__;

void _start(void)
{
    uint32_t *src = &__text_end__, *dest = &__data_start__;
    while (dest < &__data_end__) {
        *dest++ = *src++;
    }

    uint32_t *bss = &__bss_start__;
    while (bss < &__bss_end__) {
        *bss++ = 0;
    }

    main();
}

void cm_dump_frame(struct cm_stack_frame *frame)
{
    printf("PC:    0x%08X  LR:    0x%08X  xPSR:  0x%08X\n", frame->pc, frame->lr, frame->xpsr);
    printf("R0:    0x%08X  R1:    0x%08X  R2:    0x%08X  R3:    0x%08X\n", frame->r0, frame->r1, frame->r2, frame->r3);
    printf("R12:   0x%08X\n", frame->r12);
}

DEFINE_CM_HANDLER(nmi);
DEFINE_CM_HANDLER(hardfault);
DEFINE_CM_HANDLER(memmanage);
DEFINE_CM_HANDLER(busfault);
DEFINE_CM_HANDLER(usagefault);
DEFINE_CM_HANDLER(svc);
DEFINE_CM_HANDLER(debug);
DEFINE_CM_HANDLER(pendsv);
DEFINE_CM_HANDLER(systick);

const irq_handler_t __SECTION(".text.vector_table") vector_table[] = {
    cm_stack + sizeof(cm_stack), // ARM stack grows downward
    _start,
    CM_HANDLER(nmi),
    CM_HANDLER(hardfault),
    CM_HANDLER(memmanage),
    CM_HANDLER(busfault),
    CM_HANDLER(usagefault),
    NULL, // Reserved
    NULL, // Reserved
    NULL, // Reserved
    NULL, // Reserved
    CM_HANDLER(svc),
    CM_HANDLER(debug),
    NULL, // Reserved
    CM_HANDLER(pendsv),
    CM_HANDLER(systick),
};
