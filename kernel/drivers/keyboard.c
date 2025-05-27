// keyboard.c — PS/2 scan code based input

#include "ports.h"
#include <stdint.h>
#include <drivers/keyboard.h>

#define KEYBOARD_DATA_PORT 0x60

static const char scancode_to_ascii[] = {
    0,  27, '1','2','3','4','5','6','7','8','9','0','-','=','\b',
    '\t','q','w','e','r','t','y','u','i','o','p','[',']','\n', 0,
    'a','s','d','f','g','h','j','k','l',';','\'','`',  0, '\\',
    'z','x','c','v','b','n','m',',','.','/', 0, '*', 0, ' ', 0
};

char get_keypress() {
    uint8_t scancode;
    do {
        __asm__ __volatile__("inb %1, %0" : "=a"(scancode) : "Nd"(KEYBOARD_DATA_PORT));
    } while (scancode & 0x80);  // skip key releases
    return scancode_to_ascii[scancode];
}
