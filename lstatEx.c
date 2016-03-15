#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
int main(int argc, char *argv[]) {
    struct stat buf;
    if (lstat(argv[1], &buf) < 0) {
        printf("lstat error");
    }
    printf("\nmode: %d", buf.st_mode);
    printf("\ninode number: %llu", buf.st_ino);
    printf("\nNumber of hardlinks: %d", buf.st_nlink);
    printf("\nUser id of owner: %d", buf.st_uid);
    printf("\nGroup id of owner: %d", buf.st_gid);
    printf("\nLast access time: %s", ctime(&buf.st_atime));
    printf("\nLast modification time: %s", ctime(&buf.st_mtime));

}
