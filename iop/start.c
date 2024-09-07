extern unsigned int size_payload_data;
extern unsigned char payload_data[];

#define PATCH_START_ADDR 0xA14000

volatile char *PPC_UART_TX = (volatile char *) 0x1F80380C;

void
tty_puts(const char *str)
{
    const char *p = str;
    while(p && *p) *PPC_UART_TX = *(p++);
}

int
_start() {
	volatile unsigned char* dst;
	unsigned int rv;

	tty_puts("IOP Loader up: loading payload\n");

	dst = (void *)PATCH_START_ADDR;
	for (int i = 0; i < size_payload_data; i++) {
		dst[i] = payload_data[i];
	}

	tty_puts("starting payload\n");

	*(volatile unsigned int*)(0xabfbd8) = PATCH_START_ADDR;
	rv = *(volatile unsigned int*)(0x1f8fff60);

	return 0;
}
