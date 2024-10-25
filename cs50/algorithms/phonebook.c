#include <stdio.h>
#include <string.h>

typedef struct
{
  char name[20];
  char number[20];
} person;

int main(void)
{
  // char *names[] = {"Carter", "David"};
  // char *numbers[] = {"+1-617-495-1000", "+1-949-468-2750"};

  // person people[2];

  // strcpy(people[0].name, "Carter");
  // strcpy(people[0].number, "+1-617-495-1000");

  // strcpy(people[1].name, "David");
  // strcpy(people[1].number, "+1-949-468-2750");

  person people[] = {
      {"Carter", "+1-617-495-1000"},
      {"David", "+1-949-468-2750"}};
  int num_people = sizeof(people) / sizeof(person);

  char name[20];
  printf("Name: ");
  scanf("%19s", name);

  for (int i = 0; i < num_people; i++)
  {
    if (strcmp(people[i].name, name) == 0)
    {
      printf("Found %s\n", people[i].number);
      return 0;
    }
  }

  printf("Not found\n");
  return -1;
}