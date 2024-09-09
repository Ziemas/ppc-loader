int ymodem_init(void (*putc)(char), void (*getc)(char));

int ymodem_recv(void* dst);