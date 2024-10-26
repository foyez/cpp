#include <stdio.h>
#include <string.h>

int main(void)
{
  char s[20];
  printf("s: ");
  fgets(s, sizeof(s), stdin);

  char t[20];
  printf("t: ");
  fgets(t, sizeof(t), stdin);

  if (strcmp(s, t) == 0)
  {
    printf("Same\n");
  }
  else
  {
    printf("Different\n");
  }
}