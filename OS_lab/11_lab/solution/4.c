#include <ctype.h>
#include <stdio.h>
#include<signal.h>
#include <stdlib.h>
#include <unistd.h>


void handle_sigint(){
  printf("Terminating Safely...");
  exit(0);
}
int main(int argc, char *argv[])
{
  signal(SIGINT, handle_sigint); 
  while(1){
    printf("Running...\n");
    sleep(2);
  }
  return 0;
}