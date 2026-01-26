#include "libft.h"
#include <stddef.h>
#include <stdio.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
  size_t i;
  
  i = 0;
  if (n == 0)
    return (0);
  while (i < n && s1[i] && s2[i])
  {
    if(s1[i] != s2[i])
      return ((unsigned char)s1[i] - (unsigned char)s2[i]);
    i++;
  }
  if (i < n)
      return ((unsigned char)s1[i] - (unsigned char)s2[i]);
  return (0);
}
/* 
int main (void)
{
  printf("%d\n", ft_strncmp("dassda","das", 8));

  printf("%d\n", ft_strncmp("das","das", 8));
  printf("%d\n", ft_strncmp("","das", 1));
  printf("%d\n", ft_strncmp("","das", 8));
  printf("%d\n", ft_strncmp("dassda","das", 5));
  return 0;
}
 * */
