// The  bzero()  function  erases  the  data in the n bytes of  the  memory  starting  at  the  location 
// pointed  to by s, by writing zeros (bytes containing '\0') to that area.

#include <strings.h>

void bzero(void *s, size_t n)
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
