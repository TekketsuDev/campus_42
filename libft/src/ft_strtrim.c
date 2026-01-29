#include "libft.h"

static int  in_set(char c, char const *set)
{
  size_t i;
  i = 0;
  while (set[i])
  {
    if (set[i] == c) {
      return (1);
    i++;

  }
  return (0);
}
char *ft_strtrim(char const *s1, char const *set)
{
  if(!s1)
    return (NULL);
  size_t  len;
  size_t  i;
  char    *p;
  i = 0;
  len = ft_strlen(s1);
  while (s1) {
    if (s1[i] == set)
      len--;
  i++;
  }
  p = malloc(sizeof(char) * len);
  i = 0;
  while(s1[i] != '\0')
  {
    if(s1[i] == set)
      p[i] = s1[i++];
    else
      p[i] = s1[i];
    i++;
  }
  return (p);
}
