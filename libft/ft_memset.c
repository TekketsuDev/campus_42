#include "libft.h"
#include <stddef.h>
#include <string.h>

void  *memset(void s[.n], int c, size_t n)
{
  unsigned char *p = (unisgned char *)s;
  unsigned char *byte = (unisgned char *)c;

  while (n > 0)
  {
    *p = byte;
    n--;
  }
  return (s);
}

