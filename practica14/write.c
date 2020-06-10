#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s{
    unsigned char id;
    unsigned char semester;
    char firstName[20];
    char lastName[20];
} Student;

int main(){
    int destination = creat("class.bin", 0666);

    for(int i = 0; i < 10; i++){
        Student *student;
        student = (Student *)malloc(sizeof(Student));
        student->id = 20;
        student->semester = 2;
        sprintf(student->firstName, "%s", "GenericName");
        sprintf(student->lastName, "%s>%d\n", "GenericLastname", i+1);
        write(destination,student,sizeof(Student));
        free(student);
    }
    close(destination);
    return 0;
}