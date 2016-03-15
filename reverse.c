//Program to find reverse of a string and write to file
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#define SIZE 4096
int main()
{
    int fd1, fd2, n;
    char buf[SIZE];
    fd1 = open("input.txt", O_RDONLY);
    fd2 = open("output.txt", O_WRONLY | O_CREAT);
    n = lseek(fd1, 0, SEEK_END);
    printf("%d\n", n);
	while((n = lseek(fd1, -1, SEEK_CUR)) != -1) { //Shift pointer to previous character
	    read(fd1,buf,1);
	    write(fd2,buf,1);
        lseek(fd1, -1, SEEK_CUR); //Revert the forward seek of read
	}
    return 0;
}
