#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    int id;
    char name[50];
} Student;
    

void searchStudent(Student * stud, int * size);
void displayStudents(Student * stud, int * size);
void addStudent(Student * stud, int * size);

#endif
