size_t *strlcpy(char *dst, const char *src, size_t size)
{
  size_t i;

  i = 0;
  if (size != 0) {
    while (i + 1 < size && src[i] != '\0')
    {
      dst[i] = src[i];
      i++;
    }
    dst[i] = '\0';
  }

  while (src[i] != '\0') {
    i++;
  }

  return i;
}
