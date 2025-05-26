// main.c — CharlotOS 04 "Green"
// kernel main entry point, booted by GRUB
// don't touch unless you're into pain

#include <kernel.h>  // defs for kernel stuff
#include <drivers/screen.h>  // lol text output hacks

void kernel_main() {
    clear_screen();  // wipe that ugly boot screen
    print("CharlotOS 04 \"Green\" booting...\n");
    print("boot ok, not dead yet lol\n");

    // init stuff — basic, no fancy pants here
    init_system();

    // ye, launch shell or smth
    print("launching shell... type 'help' if ur dumb\n");
    shell_main();  // hand off to shell
}
