// keyboard.c — keyboard i/o
// this is just PS/2 magic n stuff

#include <drivers/keyboard.h>
#include <drivers/screen.h>

#define KEYBOARD_DATA_PORT 0x60

char get_keypress() {
    char c;
    __asm__ __volatile__("inb %1, %0" : "=a"(c) : "Nd"(KEYBOARD_DATA_PORT));
    return c;
}
