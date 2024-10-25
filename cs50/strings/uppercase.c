#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool is_lower(char ch);
char to_upper(char ch);

int main(void)
{
  char s[] = "hi";

  for (int i = 0, n = strlen(s); i < n; i++)
  {
    if (islower(s[i]))
    {
      printf("%c", toupper(s[i]));
    }
  }
}

bool is_lower(char ch)
{
  return (ch >= 'a' && ch <= 'z');
}

char to_upper(char ch)
{
  return ch - 32;
}