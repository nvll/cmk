/* Board specific cpu config and memory / flash layout */
INCLUDE "board.ld"

SECTIONS {
    .text : {
        . = ALIGN(4);
        /* NVIC for Cortex-M */
        KEEP (*(.text.nvic))
        KEEP (*(.text.nvic_platform))
        /* Code */
        *(.text)
        *(.text.*)
    } >FLASH

    /* Various strings and other symbols */
    .rodata : {
        . = ALIGN(4);
        *(.rodata)
        *(.rodata.*)
        . = ALIGN(4);
        __text_end__ = . ;
    } >FLASH

    /* This represents initialized memory values
     * place data at __text_end__ but link so that references are in ram */
    .data : AT(__text_end__) {
        . = ALIGN(4);
        __data_start__ = . ;
        *(.data)
        *(.data.*)
        . = ALIGN(4);
        __data_end__ = . ;
    } >RAM

    /* data to clear on boot (ex: the stack) */
    .bss : {
        . = ALIGN(4);
        __bss_start__ = . ;
        *(.bss)
        *(.bss.*)
        . = ALIGN(4);
        __bss_end__ = . ;
    } >RAM
}
