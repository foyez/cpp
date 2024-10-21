#include <stdio.h>

int main(void)
{
  char name[50]; // Define a character array to store the name
  printf("What's your name? ");
  fgets(name, sizeof(name), stdin);
  printf("hello, %s\n", name);
}