//#include "libft.a"
#include <string.h>
#include <stddef.h>

char  *ft_strrchr(const char *s, int c)
{
  unsigned char byte;
  const char *last = NULL;

  byte = (unsigned char)c;

  if (!s)
    return (NULL);
  while (*s)
  {
    if ((unsigned char)*s == byte)
      last = s;
    s++;
  }
  if (byte == '\0')
    return (char *)s;
  return (char *)last;
}
