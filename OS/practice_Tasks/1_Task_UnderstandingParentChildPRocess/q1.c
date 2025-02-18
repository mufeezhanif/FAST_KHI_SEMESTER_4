#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
pid_t pid;
pid = fork();
if (pid < 0) { /* error occurred */
fprintf(stderr, "Fork Failed\n");
return 1;
}
else if (pid == 0) { /* child process */
printf("This is a child process\n");
for(int i=0;i<20;++i){
	printf("%d ", i);
}
//execlp("/bin/ls","ls",NULL);

}
else { /* parent process */
/* parent will wait for the child to complete */
printf("Parent waiting for child to be completed\n");
wait(NULL);
printf("Child Complete\n");

}
}
/*
observations
If i remove wait(), Child Complete prints before This is a Child process

output

Parent waiting for child to be completed
This is a child process
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 Child Complete
*/


/*
understood this code as well

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
        if (execlp("gcc", "gcc", "/home/your_username/Documents/j.c", "-o", "/home/your_username/Documents/j.out", NULL) == -1) {
            perror("Compilation failed");
            return 1;
        }

        // Step 2: Execute compiled file (this part won't execute if execlp succeeds above)
        printf("Compilation done. Running j.out...\n");
        execlp("/home/your_username/Documents/j.out", "j.out", NULL);
        perror("Execution failed");  // Only prints if execlp fails
    }
    else { // Parent process
        wait(NULL); // Parent waits for the child to complete
        printf("Child Complete\n");
    }

    return 0;
}

*/
