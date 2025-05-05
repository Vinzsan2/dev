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

typedef struct {
    void *(*new)(int);
} Std;

static Std System = { new_ };

int main(){
    // Here your Test
    return 0;
}