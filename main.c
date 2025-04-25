#ifdef __linux

#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

void handler(int signal){ // Just handler if the length is over
    printf("Signal %d recieved\n",signal);
    fflush(stdout);
    exit(0);
}

int main(int argc,char **argv){
    struct sigaction sig;
    sig.sa_flags = SA_RESTART;
    sig.sa_handler = handler;
    sigemptyset(&sig.sa_mask);
    sigaction(SIGINT,&sig,NULL);
    sigaction(SIGSEGV,&sig,NULL);

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