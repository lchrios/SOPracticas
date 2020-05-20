#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(int argn, char **argv){
    char *searchWord = argv[1];
    char *replaceWord = argv[2];
    char *filename = argv[3];
    char word[100];
    char character;
    char espacio = 0;
    int i = 0;
    int fd = open(filename, O_RDONLY);
    if (fd < 0){
        printf("No se pudo abrir \n");
        exit(1);
    }
    //unsigned int numChar = 0, numNewL = 0, numWord = 0;
    while(read(fd, &character, 1)) {
        /*numChar++;
        if (character == 10) numNewL++;*/
        if ((character == ' ' || character == '\n') && espacio == 0) {
            espacio = 1;
            word[i] = '\0';
            i = 0;
            if (strcmp(word, searchWord) == 0){
                printf("%s \n", replaceWord);
            } else {
                printf("%s \n", word);
            }
        } else if (character != ' ' && character != '\n') {
            espacio = 0;
            word[i++] = character;
        }
    }
    /*printf("chars | lines | words | file\n");
    printf("%5d   %5d   %5d  %s\n", numChar, numNewL, numWord, filename);*/
    close(fd);
    exit(0);

}