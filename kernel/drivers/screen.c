// screen.c — text-mode VGA output
// aka the thing that lets us scream in pixels

#include <stdint.h>
#include <stddef.h>
#include <drivers/screen.h>

#define VIDEO_ADDRESS 0xB8000
#define MAX_ROWS 25
#define MAX_COLS 80

int cursor_offset = 0;

void clear_screen() {
    char* video = (char*) VIDEO_ADDRESS;
    for (int i = 0; i < MAX_ROWS * MAX_COLS * 2; i += 2) {
        video[i] = ' ';
        video[i+1] = 0x07; // white on black
    }
    cursor_offset = 0;
}

void print(const char* str) {
    char* video = (char*) VIDEO_ADDRESS;
    for (int i = 0; str[i] != '\0'; i++) {
        video[cursor_offset++] = str[i];
        video[cursor_offset++] = 0x07; // attr byte
    }
}
