#include "libft.h"

static size_t count_words(char const *s, char c)
{
  size_t count;
  size_t i;

  i = 0;
  count = 0;
  while (s[i])
  {
    if (s[i] != c && (i == 0 || s[i - 1]))
  }
}
char **ft_split(char const *s, char c)
{
  size_t count;
  size_t i;

  if (!s)
    return (NULL);
  count = 0;
  }
