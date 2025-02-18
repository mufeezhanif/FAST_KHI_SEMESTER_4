#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>

int main(){
	pid_t pid1 =fork();
	
	if(pid1<0){
		printf("Child 1 creation failed\n");
		return 1;
	}
	else if(pid1==0){
		
		
	pid_t pid2 =fork();
	
	if(pid2<0){
		printf("Child 2 creation failed\n");
		return 1;
	}
	else if(pid2==0){
		   printf("\nThis is child process 2 with id: %d\n", getpid());
         	   printf("child 2 process ended\n");
	}
	else{
		printf("\nThis is child process 1 with id: %d\n", getpid());
            	wait(NULL);
		printf("Child 1 process ended\n");
	}
	}
	else{
		printf("This is the parent process with pid: %d\n", getpid());
        	wait(NULL);
		printf("Parent process ended\n");
	}
	
	
	return 0;

}


/*
This is the parent process with pid: 8958

This is child process 1 with id: 8959

This is child process 2 with id: 8960
child 2 process ended
Child 1 process ended
Parent process ended

*/
