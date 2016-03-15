// To create empty file,
// $ > filename

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#define BUFFSIZE 256
int main(int argc, char* argv[]) {
    DIR *pdir;
    struct dirent *pdirent;
    struct stat s;
    if ((pdir = opendir(".")) == NULL) {
    	perror("opendir");
    	exit(1);
    }
    while ((pdirent = readdir(pdir)) != NULL) {
    	if (pdirent == NULL) {
    		perror("readdir");
    		continue;
    	}
    	if (stat(pdirent -> d_name, &s) < 0) {
    		perror("stat");
    		continue;
    	}
    	if (s.st_size == 0 ) {
    		if (unlink(pdirent -> d_name) < 0) {
    			perror("unlink");
    			continue;
    		}
    	}
    }
    if (closedir(pdir) < 0) {
        perror("closedir");
        exit(2);
    }
}
