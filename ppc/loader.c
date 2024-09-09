#include "uart.h"
#include "printf.h"

__attribute__((section(".text_entry"))) 
int
_start() {
    printf("PPC Loader running\n");

    while (1) {
        char r = serial_getc();
        serial_putc(r);
    }

    return 0;
}