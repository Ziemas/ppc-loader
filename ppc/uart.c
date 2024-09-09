#include "uart.h"
#include "utils.h"

#define UART_THR 0x01000200
#define UART_LSR 0x01000205
#define UART_DR 0x01
#define UART_THR_EMPTY 0x20

void
serial_putc(char c)
{
    if (c == '\n') {
        serial_putc('\r');
    }

	while ((read8(UART_LSR) & UART_THR_EMPTY) == 0)
        ;

	write8(UART_THR, c);
}

char
serial_getc()
{
	while ((read8(UART_LSR) & UART_DR) == 0)
        ;

    return read8(UART_THR);
}

void
serial_puts(char *s)
{
	while (s && *s != '\0') {
		serial_putc(*s++);
	}
}

