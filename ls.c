#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dirp;
    if (argc != 2) {
        printf("Usage: ls directory_name");
        exit(0);
    }

    if ((dp = opendir(argv[1])) == NULL) {
        printf("Cannot open directory");
        exit(0);
    }

    while ((dirp = readdir(dp)) != NULL) {
        printf("%s\n", dirp->d_name);
    }
    closedir(dp);

}
