#include <stdio.h>
#include <string.h>

int search_number(int n);
int search_string(char s[]);

int main(void)
{
  int n;
  printf("Number: ");
  scanf("%i", &n);
  search_number(n);

  char s[50];
  printf("String: ");
  scanf("%49s", s); // Limit input to prevent buffer overflow
  search_string(s);
}

int search_number(int n)
{
  int numbers[] = {20, 500, 10, 5, 100, 1, 50};

  for (int i = 0; i < 7; i++)
  {
    printf("Found\n");
    return 0;
  }

  printf("Not Found\n");
  return -1;
}

#define NUM_STRINGS 6

int search_string(char s[])
{
  const char *strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

  for (int i = 0; i < NUM_STRINGS; i++)
  {
    if (strcmp(strings[i], s) == 0)
    {
      printf("Found\n");
      return 0;
    }
  }

  printf("Not Found\n");
  return -1;
}