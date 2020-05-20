#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argn, char **argv){
    char *filename = argv[1];
    char character;
    int fd = open(filename, O_RDONLY);
    if (fd < 0){
        printf("No se pudo abrir \n");
        exit(1);
    }
    int palabras;
    while(read(fd, &character, 1)) {
        printf("%d ",character);
    }
    close(fd);
    exit(0);

}