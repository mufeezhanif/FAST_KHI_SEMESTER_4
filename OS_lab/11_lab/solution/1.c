#include <ctype.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct
{
  int i;
  int j;
  int *arr;
} indices;

void printArray(int *arr, int n)
{
  for (int i = 0; i < n; ++i)
  {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}
void *sortArr(void *arg)
{
  indices *args = (indices *)arg;
  int i = args->i;
  int n = args->j;
  int *arr = args->arr;
  
  // Correct bubble sort implementation
  for (int k = i; k < n - 1; ++k)
  {
    for (int j = i; j < n - 1; ++j)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  return NULL;
}

void merge(int *arr, int n)
{
  int mid = n / 2;
  int *temp = (int *)malloc(n * sizeof(int));
  int i = 0, j = mid, k = 0;
  
  while (i < mid && j < n)
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
    }
  }
  
  while (i < mid)
  {
    temp[k++] = arr[i++];
  }
  
  while (j < n)
  {
    temp[k++] = arr[j++];
  }
  
  for (i = 0; i < n; i++)
  {
    arr[i] = temp[i];
  }
  
  free(temp);
}

int main()
{
  int size = 14;
  int arr[] = {45, 595, 321, 0, 15, 6, 12, 48, 9, 563, 1, 23, 6, 7, 956};
  printArray(arr, size);

  pthread_t t1, t2;
  indices arg1 = {0, size / 2, arr};
  indices arg2 = {size / 2, size, arr};
  
  pthread_create(&t1, NULL, sortArr, &arg1);
  pthread_create(&t2, NULL, sortArr, &arg2);
  
  // Wait for both threads to complete
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  
  printArray(arr, size);
  merge(arr, size);
  printf("\nFinal sorted array:\n");
  printArray(arr, size);
  return 0;
}