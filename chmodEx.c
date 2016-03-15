#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    struct stat buf;

    if (stat("foo", &buf) < 0) {
        printf("stat error");
        exit(0);
    }
    if (chmod("foo", (buf.st_mode & ~S_IXGRP) | S_ISGID) < 0) {
        printf("chmod error");
        exit(0);
    }
    if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0) {
        printf("chmod error for bar");
        exit(0);
    }
}
