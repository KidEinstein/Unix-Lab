#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./a.out source destination");
    }

    if (link(argv[1], argv[2]) < 0) {
        printf("Link error");
        exit(0);
    }

    if (unlink(argv[1]) < 0) {
        printf("Unlink error");
        exit(0);
    }

    printf("File moved");
}
