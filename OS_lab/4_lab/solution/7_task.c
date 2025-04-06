#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include<fcntl.h>
#include<string.h>
int main(int argc, char *argv[])
{
    int status;
    if(argc <2){
        printf("Please share the file name as command line arguments\n");
        return 1;
    }
    int f1 = open(argv[1], O_RDONLY);
    char buffer[50];
    if (f1 == -1)
    {
        printf("Error in file opening");
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Unable to create child process");
        return 1;
    }
    else if (pid == 0)
    {
        while(read(f1, buffer, 3)){
            write(1, buffer, 3);
        }
    }
    else
    {
        wait(&status); 
        if (WIFEXITED(status)) { 
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Child did not terminate normally\n");
        }
        printf("Success\n");
    }
    close(f1);
    return 0;
}