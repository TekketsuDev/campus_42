#include "libft.h"
char  *ft_substr(char const *s, unsigned int start, size_t len)
{
  size_t i;
  size_t slen;
  char  *sub;

  i = 0;
  if (!s)
    return (NULL);
  slen = ft_strlen(s);
  if (start >= slen)
    len = 0;
  else if (len > slen - start)
    len = slen - start;
  sub = malloc(len + 1);
  if (!sub)
    return (NULL);
  while (i < len)
  {
    sub[i] = s[start + i];
    i++;
  }
  sub[i] = '\0';
  return (sub);
}
