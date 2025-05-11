#include <ctype.h>
#include <stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include <stdlib.h>
#include <unistd.h>
pthread_mutex_t mutex;

void * updateVar(void * var){
  int *i = (int *) var;
  while(1){
    pthread_mutex_lock(&mutex);
    printf("Person %d is accessing the atm\n", *i );
    for(int i=0;i<10000;++i);
    printf("Person %d is leaving the atm\n", *i );
    pthread_mutex_unlock(&mutex);
  }
}
int main(int argc, char *argv[])
{
  if(pthread_mutex_init(&mutex,NULL)!=0){
    printf("Error, leaving");
    return 0;
  }
  pthread_t t1, t2, t3,t4;
  int arr[] = {1,2,3,4};
  pthread_create(&t1,NULL,updateVar, &arr[0]);
  pthread_create(&t2,NULL,updateVar, &arr[1]);
  pthread_create(&t3,NULL,updateVar, &arr[2]);
  pthread_create(&t4,NULL,updateVar, &arr[3]);
  
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);
  pthread_join(t4, NULL);
  pthread_mutex_destroy(&mutex);
  return 0;
}