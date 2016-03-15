// $ ./a.out /etc/passwd /etc /dev/log /dev/tty \ > /var/lib/oprofile/opd_pipe /dev/sr0 /dev/cdrom /etc/passwd: regular
// /etc: directory
// /dev/log: socket
// /dev/tty: character special /var/lib/oprofile/opd_pipe: fifo
// /dev/sr0: block special
// /dev/cdrom: symbolic link

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    struct stat buf;
    char* ptr;
    if (lstat(argv[1], &buf) < 0) {
        printf("lstat error");
        exit(0);
    }

    if (S_ISREG(buf.st_mode)) {
        ptr = "regular";
    } else if(S_ISDIR(buf.st_mode)) {
        ptr = "directory";
    } else if(S_ISCHR(buf.st_mode)) {
        ptr = "character special";
    } else if(S_ISBLK(buf.st_mode)) {
        ptr = "block special";
    } else if(S_ISFIFO(buf.st_mode)) {
        ptr = "fifo";
    } else if(S_ISLNK(buf.st_mode)) {
        ptr = "symbolic link";
    } else if(S_ISSOCK(buf.st_mode)) {
        ptr = "socket";
    } else {
        ptr = "unknown mode";
    }
    printf("%s", ptr);
}
