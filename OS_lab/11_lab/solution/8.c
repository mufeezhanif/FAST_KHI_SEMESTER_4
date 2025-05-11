#include <ctype.h>
#include <stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include <stdlib.h>
#include <unistd.h>
sem_t mutex[5]; //5 chopsticks

void * PhilospherFunc(void * var){
  int n = *(int *) var;
  printf("Philosopher %d about to pick left chopstick\n",n+1);
  sem_wait(&mutex[n]);
  printf("Philosopher %d has picked left chopstick\n",n+1);
  printf("Philosopher %d about to pick right chopstick\n",n+1);
  sem_wait(&mutex[(n+1)%5]);
  printf("Philosopher %d has picked right chopstick\n",n+1);
  printf("Philosopher %d has started eating\n",n+1);
  sleep(2);
  printf("Philosopher %d finished eating\n",n+1);
  printf("Philosopher %d about to drop left chopstick\n",n+1);
  sem_post(&mutex[n]); 
  printf("Philosopher %d has dropped left chopstick\n",n+1);
  printf("Philosopher %d about to drop right chopstick\n",n+1);
  sem_post(&mutex[(n+1)%5]); 
  printf("Philosopher %d has dropped right chopstick\n",n+1);


  return NULL;
}


int main(int argc, char *argv[])
{

  pthread_t philosophers[5];
  for(int i=0;i<5;++i){
    sem_init(&mutex[i],0,1);
  }
  for(int i=0;i<5;++i){

    pthread_create(&philosophers[i],NULL,PhilospherFunc, &i);
  }
  for(int i=0;i<5;++i){
    pthread_join(philosophers[i],NULL);
  }

  
  for(int i=0;i<5;++i){
   sem_destroy(&mutex[i]);
  }
  return 0;
}