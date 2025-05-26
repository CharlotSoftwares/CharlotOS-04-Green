// syscall.c — syscalls, the fake gods of userland
// right now just a useless table

#include <kernel.h>
#include <drivers/screen.h>

void syscall_handler(int syscall_id) {
    print("lol syscall called, id = ");
    print_num(syscall_id);  // custom print_num() maybe
    print("\n");

    switch(syscall_id) {
        case 0:
            print("sys_hello: what's up userland\n");
            break;
        default:
            print("idk what syscall that was 💀\n");
    }
}
