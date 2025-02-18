#include <stdio.h>
#include "student.h"

void searchStudent(Student * stud, int * size) {
    printf("\nEnter Student ID: ");
    int id, i;
    scanf("%d", &id);

    for (i = 0; i < *size; ++i) {
        if (stud[i].id == id) {            
            printf("ID: %d\tName: %s\n", stud[i].id, stud[i].name);
            return;
        }
    }
    printf("Student not found.\n");
}
