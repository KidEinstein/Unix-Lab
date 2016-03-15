#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	int pid = fork();
	if (pid < 0) {
		printf("Error");
	}
	else if (pid == 0) {
		printf("Child process, PPID : %d", getppid());
		exit(0);
	} else {
		printf("Parent process, PID : %d", getpid());
		sleep(3);
		// Child killed by now, ps should display defunct for the child process
	}
system("ps -axj");
return 1;
	
}
		
