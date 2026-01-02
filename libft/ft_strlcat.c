  

size_t ft_strnlen (const char *s,size_t size)
{
  int i;

  i = 0;
  if (!s)
    return (0);
  while (s[i] != '\0')
  {
    i++;
  }
  return (i);
}

size_t *strlcat(char *dst, const char *src, size_t size)
{
  size_t i;
  i = 0;
  if (size != 0 && (size - ft_strnlen(dst,size) -1)) {
    while (i + 1 < size && src[i] != '\0')
    {
      dst[i] = src[i];
      i++;
    }
    dst[i] = '\0';
  }

  return strnlen(dst,size);
}
