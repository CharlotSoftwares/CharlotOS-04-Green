// vfs.c — RAM-based toy FS for CharlotOS

#include <string.h>
#include <drivers/screen.h>

typedef struct {
    const char* name;
    const char* data;
} File;

File files[] = {
    { "readme.txt", "This is CharlotOS 04 'Green'\n" },
    { "hello.txt",  "yo user :)\n" },
};

#define FILE_COUNT (sizeof(files)/sizeof(File)) 
// shitty
const char* vfs_read_file(const char* name) {
    for (int i = 0; i < FILE_COUNT; i++) {
        if (strcmp(files[i].name, name) == 0) {
            return files[i].data;
        }
    }
    return NULL;
}
