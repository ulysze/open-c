#include "dump_mem.h"

// C compiler (abstractions offered by the C compiler for software running on the ISA and on some computer). Restricted sequential execution logic on computer.

void example(void) {
        int v = 80;
        int v1 = -80;
        double v2 = 109019091.01923;
        double v3 = 0.1;

        printf('\n')
            dump_mem(convert(&v), sizeof(int));
        printf("\n");
        dump_mem(convert(&v1), sizeof(int));
        printf("\n");
        dump_mem(convert(&v2), sizeof(double));
        printf("\n");
        dump_mem(convert(&v3), sizeof(double));
        printf("\n");
}

byte *convert(void *ptr) {
        return (byte *)ptr;
}

void binary_print(byte b) {

        printf(" ");
        byte i = 0;
        while (i < 8)
        {
                printf("%u", (b >> i) & 1);
                ++i;
        }
        printf("\n");
}

void display(size_t size, byte b) {
        printf("size: %02zu\n", size);
        printf("binary form: ");
        binary_print(b);
        printf("positive integer form: %3u\n", b);

        if (b >= 32 && b <= 126)
        {
                printf("character form: '%c'\n", b);
        }
}

void dump_mem(byte *bptr, size_t N) {
        printf("Starting from %p: \n", bptr);
        for (size_t i = 0; i < N; ++i)
        {
                printf("byte %02zu: ", i);
                binary_print(*(bptr + i));
        }
}