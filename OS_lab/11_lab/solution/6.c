#include <ctype.h>
#include <stdio.h>
#include<signal.h>
#include <stdlib.h>
#include <unistd.h>

int flag = 1;
void handle_sigusr1(){
  flag = (flag==1) ? 0:1;
}
int main(int argc, char *argv[])
{
  signal(SIGUSR1, handle_sigusr1); 
  printf("PRocess iD: %d\n", getpid());
  while(1){
    if(flag ==1)
    printf("Working...\n");
    else 
    printf("Paused by SIGUSR1\n");
    sleep(3);
  }
  return 0;
}