/*
for i from 0 to n-1
  find smallest number between numbers[i] and numbers[n-1]
    swap smallest number with numbers[i]
*/

// Time Complexity: (n-1) + (n-2) + (n-3) + ... + 1 = n(n-1)/2=(n^2-n)/2=n^2/2-n/2=Θ(n^2)
// SC: O(1)

#include <stdio.h>

int main(void)
{
  int nums[] = {5, 2, 3, 2};
  int length = sizeof(nums) / sizeof(nums[0]);
  // sizeof(nums) - total size of the array in bytes
  // sizeof(nums[0]) - the size of the first element

  for (int i = 0; i < length - 1; i++)
  {
    int minIndex = i;

    // Find the index of the minimum element
    for (int j = i + 1; j < length; j++)
    {
      if (nums[minIndex] > nums[j])
      {
        minIndex = j;
      }
    }

    int tmp = nums[minIndex];
    nums[minIndex] = nums[i];
    nums[i] = tmp;
  }

  for (int i = 0; i < length; i++)
  {
    printf("%d ", nums[i]);
  }
  printf("\n");
}