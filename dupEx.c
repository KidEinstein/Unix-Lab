#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFFSIZE 256
int main () {
    char buf[BUFFSIZE];
    int fd1 = open("input.txt", O_RDONLY);
    int fd2 = dup(fd1);

    printf("FD1: %d, FD2: %d", fd1, fd2);

    printf("Reading from fd1");
    if (read(fd1, buf, 5) != 5) {
        printf("Read error");
        exit(0);
    }
    printf("%s", buf);

    printf("Reading from fd2");
    if (read(fd2, buf, 5) != 5) {
        printf("Read error");
        exit(0);
    }
    printf("%s", buf);
}
