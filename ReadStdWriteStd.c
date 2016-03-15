#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFFSIZE 256
int main() {
    int n;
    char buf[BUFFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            printf("Write error");
            exit(0);
        }
    }
}
