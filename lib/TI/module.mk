# vim: set noexpandtab ts=4 sw=4 sts=4
PWD := $(GET_PARENT)

INCLUDES += \
	-I $(PWD) \
	-I $(PWD)/inc \
	-I $(PWD)/driverlib

DEFINES += -D PART_LM4F120H5QR

SOURCES  += \
	$(PWD)/driverlib/adc.c \
	$(PWD)/driverlib/can.c	\
	$(PWD)/driverlib/comp.c	\
	$(PWD)/driverlib/cpu.c \
	$(PWD)/driverlib/eeprom.c \
	$(PWD)/driverlib/epi.c \
	$(PWD)/driverlib/ethernet.c	\
	$(PWD)/driverlib/fan.c \
	$(PWD)/driverlib/flash.c \
	$(PWD)/driverlib/fpu.c \
	$(PWD)/driverlib/gpio.c \
	$(PWD)/driverlib/hibernate.c \
	$(PWD)/driverlib/i2c.c \
	$(PWD)/driverlib/i2s.c \
	$(PWD)/driverlib/interrupt.c \
	$(PWD)/driverlib/lpc.c \
	$(PWD)/driverlib/mpu.c \
	$(PWD)/driverlib/peci.c \
	$(PWD)/driverlib/pwm.c \
	$(PWD)/driverlib/qei.c \
	$(PWD)/driverlib/ssi.c \
	$(PWD)/driverlib/sysctl.c \
	$(PWD)/driverlib/sysexc.c \
	$(PWD)/driverlib/systick.c \
	$(PWD)/driverlib/timer.c \
	$(PWD)/driverlib/uart.c	\
	$(PWD)/driverlib/udma.c	\
	$(PWD)/driverlib/usb.c \
	$(PWD)/driverlib/watchdog.c	\
