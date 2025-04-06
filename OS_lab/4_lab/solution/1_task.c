#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();
    int status;
    if (pid < 0)
    {
        printf("Unable to create child process");
        return 1;
    }
    else if (pid == 0)
    {
        execlp("ls", "ls", NULL);

    }
    else
    {
        wait(&status); 
        if (WIFEXITED(status)) { 
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Child did not terminate normally\n");
        }
    }
    return 0;
}