
// $ ./a.out 0 < /dev/tty read only
// $ ./a.out 1 > temp.foo $ cat temp.foo
// write only
// $ ./a.out 2 2>>temp.foo write only, append
// $ ./a.out 5 5<>temp.foo read write

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int val;
    if (argc != 2) {
        printf("Usage a.out <descriptor#>");
        exit(0);
    }
    int fd = atoi(argv[1]);
    if ((val = fcntl(fd, F_GETFL, 0)) < 0) {
        printf("fcntl error");
    }

    switch (val & O_ACCMODE) {
        case O_RDONLY:
        printf("read only");
        break;

        case O_WRONLY:
        printf("write only");
        break;

        case O_RDWR:
        printf("read write");
        break;

        default:
        printf("Unknown access mode");
    }

    if (val & O_APPEND)
	   printf(", append");
	if (val & O_NONBLOCK)
	   printf(", nonblocking");
	if (val & O_SYNC)
	   printf(", synchronous writes");

}
