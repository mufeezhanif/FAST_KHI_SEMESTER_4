#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t f;
    
    f = fork();
    
    if (f < 0)
        printf("error");
    else if (f == 0) { // Child process
        execlp("ls", "ls", NULL);
        printf("Child having PID %d \n", getpid()); // Will NOT execute if execlp() works
        printf("Parent having PID %d \n", getppid());
    } 
    else { // Parent process
        wait(NULL);
        printf("Parent having PID %d \n", getpid());
        printf("My child having PID %d \n", f);
    }
}
