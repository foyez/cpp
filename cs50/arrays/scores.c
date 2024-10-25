#include <stdio.h>

/*
int main(void)
{
  int score1 = 72;
  int score2 = 73;
  int score3 = 33;

  // printf("Average: %f\n", (score1 + score2 + score3) / 3.0);
  printf("Average: %f\n", (score1 + score2 + score3) / (float)3);
}
*/

const int N = 3;

float average(int array[], int length);

int main(void)
{
  int scores[N];
  // scores[0] = 72;
  // scores[1] = 73;
  // scores[2] = 33;
  // int scores[N] = {72, 73, 33};

  for (int i = 0; i < N; i++)
  {
    printf("Score: ");
    scanf("%i", &scores[i]);
  }

  printf("Average: %f\n", average(scores, N));
}

float average(int array[], int length)
{
  int sum = 0;

  for (int i = 0; i < length; i++)
  {
    sum += array[i];
  }

  return sum / (float)length;
}