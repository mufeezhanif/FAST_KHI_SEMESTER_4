#include <ctype.h>
#include <stdio.h>
#include<signal.h>
#include <stdlib.h>
#include <unistd.h>


int flag= 1;
void handle_sigint(){
  printf("Timer Paused...\n");
  flag = 0;
}
void handle_sigtstp(){
  printf("Timer Resumed...\n");
  flag = 1;
}
int main(int argc, char *argv[])
{
  signal(SIGINT, handle_sigint); 
  signal(SIGTSTP, handle_sigtstp); 
  int i = 11;
  while(i>0){
    while(flag !=1);
    printf("Time Remaining: %d\n", --i);
    sleep(1);
  }
  return 0;
}