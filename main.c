#ifdef __linux

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc,char **argv){
    if(argc < 2){
        printf("Error Argument\n");
        return 1;
    }
    int fd = open(argv[1],O_RDONLY);
    if(fd < 0){
        perror("Error opening File\n");
        close(fd);
        return 1;
    }
    size_t len = lseek(fd,0,SEEK_END);
    lseek(fd,0,SEEK_SET);
    char *buffer = malloc(len);
    read(fd,buffer,len);
    write(STDOUT_FILENO,buffer,len);
    close(fd);
    free(buffer);
    return 0;
}

#endif