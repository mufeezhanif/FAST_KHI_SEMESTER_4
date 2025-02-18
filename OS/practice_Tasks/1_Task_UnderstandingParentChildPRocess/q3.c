#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
pid_t pid;
pid = fork();
if (pid < 0) { 
fprintf(stderr, "Fork Failed\n");
return 1;
}
else if (pid == 0) {
for(int i=0;i<=50;++i){
	if(i%2==1)	printf("%d ", i);
}

}
else { /* parent process */

for(int i=0;i<=50;++i){
	if(i%2==0)	printf("%d ", i);
}

}
}

/*
got this output everytime. Means parent executed first
0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40 42 44 46 48 50 1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 41 43 45 47 49
*/
