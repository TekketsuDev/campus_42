#include "libft.h"
#include <stddef.h>

void  *ft_memchr(const void *s, int c, size_t n)
{
  unsigned char *p;
  unsigned char byte;
  size_t i;

  i = 0;
  byte = (unsigned char)c;
  p = (unsigned char *)s;
  while (i < n)
  {
    if (p[i] == byte)
      return ((void *)(p + i));
    i++;
  }
  return (NULL);
  }
