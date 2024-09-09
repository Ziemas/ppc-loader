/* Generic YMODEM receiver */

enum {
    SOH = 0x01,
    STX = 0x02,
    ACK = 0x06,
    NAK = 0x15,
    CAN = 0x17,
    EOT = 0x04,
};

void (*yputc)(char) = 0;
void (*ygetc)(char) = 0;

static unsigned short crc16(const unsigned char *data, unsigned short size)
{
    unsigned short crc, s;

    for (crc = 0; size > 0; size--) {
        s = *data++ ^ (crc >> 8);
        s ^= (s >> 4);
        crc = (crc << 8) ^ s ^ (s << 5) ^ (s << 12);
    }
    return crc;
}

int ymodem_recv(void* dst) {
    return 0;
}

int ymodem_init(void (*putc)(char), void (*getc)(char)) {
    if (!putc || !getc) {
        return -1;
    }

    yputc = putc;
    ygetc = getc;

    return 0;
}

