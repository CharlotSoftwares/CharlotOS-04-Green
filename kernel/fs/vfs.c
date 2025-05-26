// vfs.c — Virtual File System layer
// this whole thing is a fkn placeholder rn

#include <kernel.h>
#include <drivers/screen.h>

void vfs_init() {
    print("[vfs] init: not a damn thing implemented yet lol\n");
}

int vfs_open(const char* path) {
    print("[vfs] open: bruh no files exist\n");
    return -1;
}

int vfs_read(int fd, char* buf, int len) {
    print("[vfs] read: not even reading air rn\n");
    return 0;
}
