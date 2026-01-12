/*
//#include "libft.a"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>
*/
int ft_atoi (const char *nptr)
{
  int i;
  int conv;

  i = 0;
  conv = 0;

  while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
  {
    conv = conv * 10 + (nptr[i] - '0');
    i++;
  }
  return conv;
}
/*
int main(void)
{
  const char *nptr = "aa443222aa";
  const char *naptr = "\0443222aa";
  const char *naaptr = "22aa";
  //assert(strtol(nptr, NULL, 10));
  printf("NPTR (ft_ATOI):%d \n", ft_atoi(nptr));
  printf("NAAPTR (ATOI):%d\n", atoi(naaptr));
 int a = atoi(naptr);
printf("a_ATOI_NAPTR:%d\n", a);
a = atoi(nptr);
printf("a2_ATOI_NPTR:%d\n", a);

  return (0);
}
*/
