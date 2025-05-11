#include <ctype.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int *m1, *m2, *resultant;

void *calculateMultiple(void *arg)
{
  int *r = (int *)arg;
  for (int i = 0; i < 3; i++)
  {
    resultant[*r * 3 + i] = m1[*r * 3 + 0] * m2[0 * 3 + i] +
                            m1[*r * 3 + 1] * m2[1 * 3 + i] +
                            m1[*r * 3 + 2] * m2[2 * 3 + i];

    printf("resultant[%d] = %d * %d + %d * %d + %d * %d\n",
           *r * 3 + i,
           m1[*r * 3 + 0], m2[0 * 3 + i],
           m1[*r * 3 + 1], m2[1 * 3 + i],
           m1[*r * 3 + 2], m2[2 * 3 + i]);
  }
}
int main()
{

  m1 = (int *)malloc(3 * 3 * sizeof(int));
  m2 = (int *)malloc(3 * 3 * sizeof(int));
  resultant = (int *)malloc(3 * 3 * sizeof(int));
  printf("Enter the first matrix (Row-wise): ");
  for (int i = 0; i < 9; i++)
  {
    scanf("%d", &m1[i]);
  }
  printf("Enter the second matrix (Row-wise): ");
  for (int i = 0; i < 9; i++)
  {
    scanf("%d", &m2[i]);
  }
  pthread_t t1, t2, t3;
  int a = 0, b = 1, c = 2;
  pthread_create(&t1, NULL, calculateMultiple, &a);
  pthread_create(&t2, NULL, calculateMultiple, &b);
  pthread_create(&t3, NULL, calculateMultiple, &c);

  // Wait for both threads to complete
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);
  printf("Resultant matrix: \n");
  for (int i = 0; i < 9; i++)
  {
    printf("%d ", resultant[i]);
    if ((i + 1) % 3 == 0)
    {
      printf("\n");
    }
  }
  return 0;
}