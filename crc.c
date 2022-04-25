#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// fontes: https://wiki.osdev.org/CRC32
unsigned int CRC32(char *nome)
{
    unsigned int crc32 = 0xFFFFFFFFu;

    static unsigned int table[256] = {0};
    static char ini = 0;

    int size_str = strlen(nome);

    if (!ini) { // inicializar a tabela apenas uma vez
        unsigned char index = 0;
        do {
            table[index] = index;
            for (char i = 0; i < 8; i++) {
                table[index] = (table[index] & 1) ? (table[index] >> 1) ^0xEDB88320 : table[index] >> 1;
            }
        } while(++index);
        ini = 1;
    }

    for (unsigned int i = 0; i < size_str; i++) {
        unsigned int lookup = (crc32 ^ nome[i]) & 0xff;
        crc32 = (crc32 >> 8) ^ table[lookup];
    }
    return ~crc32;
} 

int main(int argc, char* argv[])
{
    for (int i = 1; argv[i]; i++) {
        printf("CRC32 %s: 0x%08X\n", argv[i], CRC32(argv[i]));
    }
    return 0;
}