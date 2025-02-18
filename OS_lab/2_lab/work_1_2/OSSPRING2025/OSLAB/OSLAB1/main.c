#include <stdio.h>
#include "student.h"

int main() {
    int a = 0;
    Student stud[100];
    int size =0; 
    while (a != 4) {
        printf("\nEnter your choice:\n");
        printf("1 - Display students\n");
        printf("2 - Add new student\n");
        printf("3 - Search student by ID\n");
        printf("4 - Exit\n");
        printf("Choice: ");
        scanf("%d", &a);

        switch (a) {
            case 1:
                displayStudents(stud, &size );
                break;
            case 2:
                addStudent(stud, &size);
                break;
            case 3:
                searchStudent(stud, &size);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
