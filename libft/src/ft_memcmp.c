#include "libft.h"
#include <stddef.h>

 int ft_memcmp(const void *s1, const void *s2, size_t n)
{
  const unsigned char *p;
  const unsigned char *ps;
  size_t i;

  i = 0;
  p = (const unsigned char *)s1;
  ps = (const unsigned char *)s2;
  while (i < n)
  {
      if (p[i] != ps[i])
        return ((int)p[i] - (int)ps[i]);
      i++;
  }
   return (0);
}
