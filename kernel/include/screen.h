// screen.h — ya basic screen ops
// bro don't touch this unless ur fixing VGA shit
// print() dumps to screen via vid mem, ez peasy

#ifndef SCREEN_H
#define SCREEN_H

void clear_screen();
void print(const char* str);
void print_char(char c);
void set_cursor(int row, int col);
void update_cursor();

#endif
