//#include "libft.a"
#include <string.h>

char  *ft_strchr(const char *s, int c)
{
  unsigned char byte;
  size_t i;

  byte = (unsigned char)c;
  i = 0;

  while (s[i] != '\0')
  {
    if ((unsigned char)s[i] == byte)
      return ((char *)&s[i]);
    i++;
  }
  if (byte == '\0')
    return ((char *)&s[i]);
  return (NULL);
}
