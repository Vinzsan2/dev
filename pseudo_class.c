#define PENGAPLIKASIAN_CLASS_LIKE_DI_C

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void Print(const char *msg){
    write(1,msg,strlen(msg));
}

typedef struct {
    void (*outPrint)(const char *);
} standard;

static standard std = { Print}; // Class di muat

int main(){
    std.outPrint("Hello world");
    return 0;
}