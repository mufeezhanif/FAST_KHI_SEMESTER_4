#include <stdio.h>
#include "student.h"

void displayStudents(Student * stud, int * size) {
    if (*size == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nStudent List:\n");
    for (int i = 0; i < *size; ++i) {
        printf("ID: %d\tName: %s\n", stud[i].id, stud[i].name);
    }
}
