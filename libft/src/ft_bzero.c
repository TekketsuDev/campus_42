void ft_bzero(void *s, size_t n)
{
  size_t i;

  i = 0;
  unsigned char *z;

  z = s;

  while (i < n) {
    z[i] = '\0';
    i++;
  }
}
