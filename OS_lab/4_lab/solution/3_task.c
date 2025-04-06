#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include<fcntl.h>
int main(int argc, char *argv[])
{
    if(argc <3){
        printf("Please share the file name as command line arguments\n");
        return 1;
    }
    int f1 = open(argv[1], O_RDONLY);
    int f2 = open(argv[2], O_WRONLY);
    char buffer[1000];
    if (f1 == -1 || f2 == -1)
    {
        printf("Error opening source or destination file");
    }

    while(read(f1, buffer, 1000)){
        write(f2, buffer, 1000);
    }
    printf("Success\n");
    close(f1);
    close(f2);
    return 0;
}