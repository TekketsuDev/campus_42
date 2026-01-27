#include <stddef.h>
#include <string.h>

void *ft_memmove(void *dest, const void *src, size_t n) {
  size_t i;
  unsigned char *ds;
  const unsigned char *sr;

  ds = (unsigned char *)dest;
  sr = (const unsigned char *)src;
  i = 0;

  if (sr < ds) {
    while (n-- > 0) {
      ds[n] = sr[n];
    }
  } else {
    while (i < n) {
      ds[i] = sr[i];
      i++;
    }
  }
  return (dest);
}
