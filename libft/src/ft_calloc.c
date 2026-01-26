#include "libft.h"

void  *ft_calloc(size_t nmemb, size_t size)
{
  void *ptr;

  if (size != 0 && nmemb > size / SIZE_MAX)
    return NULL;
  ptr = malloc(nmemb * size));
  if (!ptr)
    return  (NULL);
  ft_bzero(ptr, nmemb * size);
  return (ptr);
}
