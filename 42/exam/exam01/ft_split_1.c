#include <stdlib.h>

int ft_isspace(char c)
{
  return (c == ' ' || c == '\n' || c == '\t');
}

int count_words(char *str)
{
  int count;

  count = 0;
  while (*str)
  {
    // move to the begining of a new word
    while (*str && ft_isspace(*str))
      str++;
    if (*str && !ft_isspace(*str))
    {
      count++;
    }
    // move to the next whitespace
    while (*str && !ft_isspace(*str))
      str++;
  }
  return (count);
}

char *malloc_word(char *str)
{
  char *word;
  int i;

  i = 0;
  while (str[i] && !ft_isspace(str[i]))
    i++;
  word = (char *)malloc(sizeof(char) * (i + 1));
  i = 0;
  while (str[i] && !ft_isspace(str[i]))
  {
    word[i] = str[i];
    i++;
  }
  word[i] = '\0';
  return (word);
}

char **ft_split(char *str)
{
  char **arr;

  arr = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
  int i = 0;
  while (*str)
  {
    // move to the begining of a new word
    while (*str && ft_isspace(*str))
      str++;
    if (*str && !ft_isspace(*str))
    {
      // save word to array
      arr[i] = malloc_word(str);
      i++;
    }
    // move to the next whitespace
    while (*str && !ft_isspace(*str))
      str++;
  }
  arr[i] = NULL;
  return (arr);
}

#include <stdio.h>

int main(int ac, char **av)
{
  char **arr;

  char *phrase = "   Hello,   Flavio\t Wuensche!  ";
  // char *phrase = "   Hello,    World\t 42! ";
  arr = ft_split(phrase);

  int i = 0;
  while (arr[i])
  {
    printf("%s\n", arr[i]);
    i++;
  }
}