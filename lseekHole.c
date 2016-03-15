#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
    int fd;
    char* buf1 = "ABC";
    char* buf2 = "abc";
    if ((fd = creat("filewithhole.txt", 0777)) < 0) {
        printf("Creat error");
        exit(0);
    }
    if (write(fd, buf1, 3) != 3) {
        printf("buf1 write error");
        exit(0);
    }

    if (lseek(fd, 15000, SEEK_SET) == -1) {
        printf("Seek error");
        exit(0);
    }

    if (write(fd, buf2, 3) != 3) {
        printf("buf2 write error");
        exit(0);
    }

}
