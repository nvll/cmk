#include <driverlib/sysctl.h>
#include <driverlib/uart.h>
#include <driverlib/pin_map.h>
#include <driverlib/gpio.h>
#include <hw_memmap.h>
#include <c/stdio.h>
#include <c/stdint.h>

int putchar(int c)
{
    if (c == '\n')
        UARTCharPut(UART0_BASE, '\r');

    UARTCharPut(UART0_BASE, c);
    return c;
}

int main (void)
{
    // 16 Mhz, no PLL
    SysCtlClockSet(SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ | SYSCTL_SYSDIV_4);
    SysCtlGPIOAHBEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_AHB_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200, UART_CONFIG_WLEN_8 |
                        UART_CONFIG_PAR_NONE | UART_CONFIG_STOP_ONE);
    UARTEnable(UART0_BASE);

    uint32_t clock = SysCtlClockGet();
    printf("Booted. SysClk is at %d\n", clock);
    return 0;
}

