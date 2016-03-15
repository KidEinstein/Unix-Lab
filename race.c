#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	int pid;
	char ch;
	srand(getpid());
	pid = fork();
	if (pid < 0) {
		perror("fork");
		exit(1);
	}
	else if (pid) {
		for (ch = 'A'; ch <= 'Z'; ++ch) {
			write(1, &ch, 1);
			sleep(rand() %2);
		}
	}
	else {
		for (ch = 'a'; ch <= 'z'; ++ch) {
			write(1, &ch, 1);
			sleep(rand() % 2);
		}
	}
}
