#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFSIZE 256
int main(int argc, char* argv[]) {
	char buf[BUFFSIZE];
    int n;
    if ((n = readlink(argv[1], buf, BUFFSIZE)) < 0) {
        printf("read link error");
        exit(0);
    }
    printf("%s", buf);
}
