#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int val;
  struct node *next;
} node;

int main(int argc, char *argv[])
{
  node *list = NULL;

  for (int i = 1; i < argc; i++)
  {
    int number = atoi(argv[i]);

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
      return 1;
    }
    n->val = number;
    // n->next = NULL;

    n->next = list;
    list = n;
  }

  // for (node *cur = list; cur != NULL; cur = cur->next)
  node *cur = list;
  while (cur != NULL)
  {
    printf("%i\n", cur->val);
    cur = cur->next;
  }

  cur = list;
  while (cur != NULL)
  {
    node *next = cur->next;
    free(cur);
    cur = next;
  }

  return 0;
}