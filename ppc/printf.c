#include "printf.h"
#include "uart.h"
#include <stdarg.h>

#define NANOPRINTF_USE_FIELD_WIDTH_FORMAT_SPECIFIERS 1
#define NANOPRINTF_USE_PRECISION_FORMAT_SPECIFIERS 1
#define NANOPRINTF_USE_LARGE_FORMAT_SPECIFIERS 1
#define NANOPRINTF_USE_FLOAT_FORMAT_SPECIFIERS 0
#define NANOPRINTF_USE_BINARY_FORMAT_SPECIFIERS 1
#define NANOPRINTF_USE_WRITEBACK_FORMAT_SPECIFIERS 0

#define NANOPRINTF_IMPLEMENTATION
#include "nanoprintf.h"

static void __putc(int c, void* ctx) {
    serial_putc(c);
}

int printf(const char* fmt, ...) {
    int rv;
    va_list va;

    va_start(va, fmt);
    rv = npf_vpprintf(__putc , NULL, fmt, va);
    va_end(va);

    return rv;
}
