#include <stdio.h>
#include <string.h>
#include "student.h"

void addStudent(Student * stud, int * size) {
    if (*size >= 100) {
        printf("Storage full, cannot add more students.\n");
        return;
    }

    printf("Enter student ID: ");
    scanf("%d", &stud[*size].id);

    printf("Enter student name: ");
    scanf("%s", stud[*size].name);

    *size +=1;
    printf("Student added successfully.\n");
}
