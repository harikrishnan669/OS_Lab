#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main() {
    DIR *dp;
    struct dirent *dirp;
    struct stat file_stat;
    char *filename;
    char *pathname;
    if ((dp = opendir(".")) == NULL) 
    {
        perror("opendir error");
        exit(1);
    }
    while ((dirp = readdir(dp)) != NULL) 
    {
        filename = dirp->d_name;
        pathname = malloc(strlen(filename) + 3);
        strcpy(pathname, "./");
        strcat(pathname, filename);
        if (stat(pathname, &file_stat) == -1) 
        {
            perror("stat error");
            continue;
        }
        printf("File: %s\n", filename);
        printf("Size: %ld bytes\n", file_stat.st_size);
        printf("Owner: %d\n", file_stat.st_uid);
        printf("Group: %d\n", file_stat.st_gid);
        printf("Permissions: %o\n", file_stat.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));
        printf("Last access time: %s", ctime(&file_stat.st_atime));
        printf("Last modification time: %s", ctime(&file_stat.st_mtime));
        printf("\n");

        free(pathname);
    }
    closedir(dp);
    return 0;
}