#include <string.h>

// The  memcpy() function copies n bytes from memory area src to memory area dest.  The memory areas must not 
// overlap.

void  *ft_memcpy(void *dest, const void *src, size_t n);
  size_t i;

  i = 0;

  while (i < n)
  {
    ((unsigned char *)dest)[i] = ((unsigned const char *)src)[i];
  }
  return (dest);
}

