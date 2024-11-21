// #include <stdlib.h>

// int is_whitespace(char c)
// {
//   return (c == '\t' || c == '\n' || c == 32);
// }

// int count_words(char *str)
// {
//   int count;

//   count = 0;
//   while (*str)
//   {
//     while (*str && is_whitespace(*str))
//     {
//       str++;
//     }
//     if (*str && !is_whitespace(*str))
//     {
//       count++;
//       // move to the next whitespace
//       while (*str && !is_whitespace(*str))
//       {
//         str++;
//       }
//     }
//   }
//   return count;
// }

// int ft_wordlen(char *str)
// {
//   int i;

//   i = 0;
//   while (str[i] && !is_whitespace(str[i]))
//     i++;
//   return i;
// }

// char *allocate_word(char *str)
// {
//   char *word;
//   int word_len;
//   int i;

//   i = 0;
//   while (str[i] && !is_whitespace(str[i]))
//     i++;
//   word_len = ft_wordlen(str);
//   word = (char *)malloc(sizeof(char) * (word_len + 1));
//   i = 0;
//   while (str[i] && !is_whitespace(str[i]))
//   {
//     word[i] = str[i];
//     i++;
//   }
//   word[i] = '\0';
//   return (word);
// }

// void **ft_split(char *str)
// {
//   int i;
//   char **arr;

//   arr = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
//   i = 0;
//   while (*str)
//   {
//     // move to the begining
//     while (*str && is_whitespace(str[i]))
//       str++;
//     if (*str && !is_whitespace(*str))
//     {
//       arr[i] = allocate_word(str);
//       i++;
//     }
//     // move to the next whitespace
//     while (*str && !is_whitespace(*str))
//       str++;
//   }
//   arr[i] = NULL;
//   return (arr);
// }

// #include <stdio.h>

// int main(void)
// {
//   char **arr;
//   char *str = "   Hello,    World\t 42! ";
//   arr = ft_split(str);
//   int i = 0;
//   while (str[i])
//   {
//     printf("%s\n", arr[i]);
//     i++;
//   }
//   return (0);
// }

#include <stdlib.h>

int ft_is_whitespace(char c)
{
  return (c == ' ' || c == '\t' || c == '\n');
}

char *ft_skip_whitespace(char *str)
{
  while (*str && ft_is_whitespace(*str))
    str++;
  return str;
}

char *ft_skip_non_whitespace(char *str)
{
  while (*str && !ft_is_whitespace(*str))
    str++;
  return str;
}

int ft_wordlen(char *str)
{
  int i = 0;
  while (str[i] && !ft_is_whitespace(str[i]))
    i++;
  return i;
}

int ft_count_words(char *str)
{
  int count;

  count = 0;
  while (*str)
  {
    str = ft_skip_whitespace(str);
    if (*str && !ft_is_whitespace(*str))
    {
      count++;
      str = ft_skip_non_whitespace(str);
    }
  }

  return count;
}

char *ft_allocate_word(char *str)
{
  char *word;
  int i;

  int word_len = ft_wordlen(str);
  word = (char *)malloc(sizeof(char) * (word_len + 1));
  i = 0;
  while (i < word_len)
  {
    word[i] = str[i];
    i++;
  }
  word[word_len] = '\0';
  return (word);
}

char **ft_split(char *str)
{
  char **arr;
  int i;

  i = 0;
  arr = (char **)malloc(sizeof(char *) * (ft_count_words(str) + 1));
  while (*str)
  {
    str = ft_skip_whitespace(str);
    if (*str && !ft_is_whitespace(*str))
    {
      arr[i] = ft_allocate_word(str);
      i++;
      str = ft_skip_non_whitespace(str);
    }
  }
  arr[i] = NULL;
  return (arr);
}

#include <stdio.h>

int main(void)
{
  char **arr;
  char *str = "   Hello,   Flavio\t Wuensche!  ";
  arr = ft_split(str);

  int i = 0;
  while (arr[i])
  {
    printf("%s\n", arr[i]);
    i++;
  }
}