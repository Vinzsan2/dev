#define CLASS_SYSTEM

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

void *new_(int size){
    if(size <= 0){
        printf("Error Unsigned");
        return NULL;
    }
    void *buffer = malloc(size * sizeof(buffer));
    if(buffer == NULL){
        perror("Erorr Memory Aloccated");
        return NULL;
    }
    printf("Memory Allocated : %p\n",buffer);
    return buffer;
}

void delete(void *buffer){
    if(buffer == NULL){
        printf("Error");
        return 1;
    }
    printf("Delete Memory : %p",buffer);
    free(buffer);
}

typedef struct {
    void *(*New)(int);
    void (*Delete)(void *);
} Std;

static Std System = { new_ ,delete};

int main(){
    char *buffer = System.New(1024);
    System.Delete(buffer);
    return 0;
}