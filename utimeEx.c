#include <fcntl.h>
#include <utime.h>
#include <stdlib.h>
#include <sys/timeb.h>
#include <sys/types.h>
#include <time.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	int fd;
	struct stat statbuf;
    struct stat statbuf2;
	struct utimbuf timebuf;

	if(stat(argv[1], &statbuf) < 0) {
		printf("%s: stat error", argv[1]);
	}

    if(stat(argv[2], &statbuf2) < 0) {
        printf("%s: stat error", argv[2]);
    }

    printf("Old access time: %s", ctime(&statbuf.st_atime));
    printf("Old modification time: %s", ctime(&statbuf.st_mtime));
	timebuf.actime = statbuf2.st_atime;
	timebuf.modtime = statbuf2.st_mtime;
	if (utime(argv[1],&timebuf) < 0) {
		printf("%s: utime error", argv[1]);
	} else {
		printf("Time modified");
	}
    if(stat(argv[1], &statbuf) < 0) {
        printf("%s: stat error", argv[2]);
    }

    printf("New access time: %s", ctime(&statbuf.st_atime));
    printf("New modification time: %s", ctime(&statbuf.st_mtime));
	exit(0);
}
