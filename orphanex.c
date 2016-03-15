#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	int pid = fork();
	if (pid < 0) {
		printf("Error");
	}
	else if (pid == 0) {
		printf("Child process, PID : %d", getppid());
		sleep(2);
		// Parent killed by now, ppid points to init-user
		printf("Child process, PID : %d", getppid());
		//exit(0);
	} else {
		printf("Parent process, PID : %d", getpid());
		
		//sleep(1);
		exit(0);
	}
system("ps -axj");
return 1;
	
}
		
