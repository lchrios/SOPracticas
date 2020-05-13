#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 512

int main(int argc, char **argv) {

    int from, to, nr, nw, n;
    char buf[BUFSIZE];
    if ((from = open(argv[1], O_RDONLY)) < 0) {
        perror("Error de lectura de archivo");
        exit(1);
    }  
    if ((to = creat(argv[2], 0666)) < 0) {
        perror("Error de creación de archivo");
        exit(2);
    }

    while((nr = read(from, buf, sizeof(buf) ) ) != 0) {
        if (nr < 0) {
            perror("Error leyendo el archivo original");
            exit(3);
        }
        nw = 0;
        do {
            if ((n = write(to, &buf[nw], nr-nw)) < 0) {
                perror("Error escribiendo en el archivo destino");
                exit(4);
            }
            nw += n;
        } while (nw < nr);
    }
    close (from); 
    close(to);
}