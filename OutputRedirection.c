#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int writefd = open("output.txt",O_WRONLY | O_CREAT, 0777);
	dup2(writefd,1);
	printf("STDOUT redirected to file");
}
