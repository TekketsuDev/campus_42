#include "libft.h"

char  *ft_strjoin(char const *s1, char const *s2)
{
  char  *p;
  size_t   i;
  size_t   j;
  if (!s1 || !s2)
    return (NULL);
  p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
  if(!p)
    return (NULL);
  i = 0;
  while (s1[i])
  {
    p[i] = s1[i];
    i++;
  }
  j = 0;
  while (s2[j])
  {
    p[i+j] = s2[j];
    j++;
  }
  p[i+j] = '\0';
  return (p);
}
