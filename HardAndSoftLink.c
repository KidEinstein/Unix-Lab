#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char* argv[]) {
	if (argc < 3) {
		printf("Missing arguments");
		return 0;
	}
	if (strcmp(argv[1], "-s") == 0 && argc == 4) {
		int res = symlink(argv[2], argv[3]);
		if (res == -1) {
			printf("Error creating symlink");
            exit(0);
		}
        exit(0);
	}
	int res = link(argv[1], argv[2]);
	if (res == -1) {
		printf("Error creating link");
		return 0;
	}
}
