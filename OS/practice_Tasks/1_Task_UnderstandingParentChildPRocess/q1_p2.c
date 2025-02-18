#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    pid = fork();

    if (pid < 0) { // Error occurred
        fprintf(stderr, "Fork Failed\n");
        return 1;
    }
    else if (pid == 0) { // Child process
        printf("Child Process: Compiling j.c...\n");

        // Step 1: Compile j.c using gcc
        if (execlp("gcc", "gcc", "./j.c", "-o", "./j.out", NULL) == -1) {
            perror("Compilation failed");
            return 1;
        }

        // Step 2: Execute compiled file (this part won't execute if execlp succeeds above)
        printf("Compilation done. Running j.out...\n");
        execlp("./j.out", "j.out", NULL);
        perror("Execution failed");  // Only prints if execlp fails
    }
    else { // Parent process
        wait(NULL); // Parent waits for the child to complete
        printf("Child Complete\n");
    }

    return 0;
}
