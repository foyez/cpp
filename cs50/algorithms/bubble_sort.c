/*
repeat n-1 times
  for i from 0 to n-2
    if numbers[i] and numbers[i+1] out of order
      swap them
*/
/*
TC: O(n^2), Ω(n)
SC: O(1)
*/

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
  int nums[] = {5, 2, 3, 1};
  int n = sizeof(nums) / sizeof(nums[0]);

  for (int i = n - 1; i >= 0; i--)
  {
    bool didSwap = false;

    for (int j = 0; j < i; j++)
    {
      if (nums[j] > nums[j + 1])
      {
        int tmp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = tmp;

        didSwap = true;
      }
    }

    if (!didSwap)
    {
      break;
    }
  }

  for (int i = 0; i < n; i++)
  {
    printf("%d ", nums[i]);
  }
  printf("\n");
}