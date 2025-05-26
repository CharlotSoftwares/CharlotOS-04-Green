// kinit.c — system init routines
// boots up the basic crap like memory, fs, etc

#include <kernel.h>
#include <drivers/screen.h>

void init_system() {
    print("[+] init_system(): init kernel subsystems...\n");

    // stub memory mgr
    init_memory();

    // fs and userland crap later
    // init_fs();

    print("[+] done with init, now yeet into shell\n");
}
