/*
if only one number
  quit
else
  sort left half of numbers
  sort right half of numbers
  merge sorted halves
*/
// TC: Θ(n log n)
// SC: O(n), Ω(1)

#include <stdio.h>

void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void printArray(int arr[], int size);

int main(void)
{
  int arr[] = {12, 11, 13, 5, 6, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, n - 1);
  printArray(arr, n);
}

void mergeSort(int arr[], int left, int right)
{
  if (left == right)
  {
    return;
  }

  int mid = left + (right - left) / 2;
  mergeSort(arr, left, mid);
  mergeSort(arr, mid + 1, right);

  merge(arr, left, mid, right);
}

void merge(int arr[], int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int leftHalf[n1], rightHalf[n2];

  for (int i = 0; i < n1; i++)
  {
    leftHalf[i] = arr[left + i];
  }
  for (int i = 0; i < n2; i++)
  {
    rightHalf[i] = arr[mid + 1 + i];
  }

  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2)
  {
    if (leftHalf[i] <= rightHalf[j])
    {
      arr[k] = leftHalf[i];
      i++;
    }
    else
    {
      arr[k] = rightHalf[j];
      j++;
    }

    k++;
  }

  // copy remaining elements of leftHalf[], if any
  while (i < n1)
  {
    arr[k] = leftHalf[i];
    i++;
    k++;
  }

  // copy remaining elements of rightHalf[], if any
  while (j < n2)
  {
    arr[k] = rightHalf[j];
    j++;
    k++;
  }
}

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}