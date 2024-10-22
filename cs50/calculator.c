#include <stdio.h>

long get_long(const char *msg);

int main(void)
{
  long x = get_long("x: ");
  long y = get_long("y: ");

  float z = (float)x / (float)y;
  printf("%.2f\n", z);
}

int get_int(const char *msg)
{
  int n;
  printf("%s", msg);
  scanf("%d", &n);
  return n;
}

long get_long(const char *msg)
{
  long n;
  printf("%s", msg);
  scanf("%li", &n);
  return n;
}