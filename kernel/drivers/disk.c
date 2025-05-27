// disk.c — ATA PIO read (28-bit LBA)

#include "ports.h"
#include <stdint.h>
#include <drivers/screen.h>
#include <drivers/disk.h>

#define ATA_PRIMARY_IO  0x1F0
#define ATA_CMD_PORT    0x1F7
#define ATA_CMD_READ    0x20

void disk_read_sector(uint32_t lba, uint8_t* buffer) {
    outb(ATA_PRIMARY_IO + 2, 1);                      // sector count
    outb(ATA_PRIMARY_IO + 3, (uint8_t)lba);            // LBA low
    outb(ATA_PRIMARY_IO + 4, (uint8_t)(lba >> 8));     // LBA mid
    outb(ATA_PRIMARY_IO + 5, (uint8_t)(lba >> 16));    // LBA high
    outb(ATA_PRIMARY_IO + 6, 0xE0 | ((lba >> 24) & 0x0F));  // drive/head
    outb(ATA_CMD_PORT, ATA_CMD_READ);

    // wait for BSY to clear
    while (inb(ATA_CMD_PORT) & 0x80);

    for (int i = 0; i < 256; i++) {
        uint16_t data = inw(ATA_PRIMARY_IO);
        buffer[i*2] = data & 0xFF;
        buffer[i*2+1] = (data >> 8) & 0xFF;
    }
}
// idk what i am doing david just told me to write that
