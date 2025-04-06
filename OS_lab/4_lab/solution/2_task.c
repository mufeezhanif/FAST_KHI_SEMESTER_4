#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    int P_id = getpid(); 
    pid_t pid = fork();
    int status;
    if (pid < 0)
    {
        printf("Unable to create child process");
        return 1;
    }
    else if (pid == 0)
    {
        printf("This is a child process\n");
        printf("Parent pid: %d\n", P_id);

    }
    else
    {
        printf("This is parent process\n");
        printf("Child pid: %d\n", pid);

    }
    return 0;
}