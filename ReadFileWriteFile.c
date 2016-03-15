#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFSIZE 256

// Press control + d to stop taking input

int main() {
    int n;
    char buf[BUFFSIZE];
    int readfd, writefd;
    readfd = open("input.txt", O_RDONLY);
    writefd = open("output.txt", O_CREAT | O_WRONLY, 0777);
    while ((n = read(readfd, buf, BUFFSIZE)) > 0) {
        if (write(writefd, buf, n) != n) {
            printf("Write error");
            exit(0);
        }
    }
    close(writefd);
}
