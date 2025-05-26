// syscall.c — working syscall handler

#include <kernel.h>
#include <drivers/screen.h>
#include <string.h>

void sys_hello() {
    print("sys_hello(): ayy, it works\n");
}

void sys_print(const char* msg) {
    print(msg);
}

void syscall_handler(int syscall_id, void* arg) {
    switch (syscall_id) {
        case 0:
            sys_hello();
            break;
        case 1:
            sys_print((const char*)arg);
            break;
        default:
            print("unknown syscall, get good\n");
    }
}
