#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    int pid = fork();
    if(pid == 0) execlp("ls","ls","-a","/");
    else printf("soy el padre\n");
    printf("adios\n");
    
}