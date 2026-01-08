//#include "libft.a"
#include <string.h>
#include <stdio.h>
#include <stddef.h>

char  *ft_strnstr(const char *s,const char *sb, size_t n)
{
  size_t i;
  size_t j;

  i = 0;
  if (!*s)
    return (NULL);
  
  if (!(*sb) )
    return (char *)s;
  
  while (i < n && s[i]) {
    if (s[i] == sb[0])
    {
      j = 0;
      while((i + j) < n && s[j] && s[i + j] == sb[j])
      {
        j++;
        if (sb[j] == '\0')
          return (char *)s(i + j);
      }
    }
    i++;
  }
  return (NULL);
}

void test(const char *s, const char *sb, size_t n)
{
    char *res = ft_strnstr(s, sb, n);
    printf("s=\"%s\", sb=\"%s\", n=%zu → %s\n",
           s, sb, n, res ? res : "NULL");
}
int main(void)
{
ft_strnstr("hello world", "hello", 11);   // → "hello world"
ft_strnstr("hello world", "world", 11);   // → "world"
ft_strnstr("hello world", "o w", 11);     // → "o world"
ft_strnstr("hello world", "world", 5);    // → NULL
ft_strnstr("abcdef", "def", 5);           // → NULL
ft_strnstr("", "a", 1);                   // → NULL
ft_strnstr("", "", 1);                    // → ""
ft_strnstr("abcd", "cd", 4);              // → "cd"
ft_strnstr("abcd", "cd", 3);              // → NULL
ft_strnstr("aaaaa", "aaa", 5);            // → "aaaaa"
ft_strnstr("aaaaa", "aaa", 3);            // → "aaaaa"
ft_strnstr("aaaaa", "aaa", 2);            // → NULL
ft_strnstr("Hello", "hello", 5);           // → NULL
ft_strnstr("Hello", "Hell", 5);            // → "Hello"
ft_strnstr("hello", "h", 0);               // → NULL
ft_strnstr("hello", "", 0);                // → "hello"
ft_strnstr("hi", "hello", 5);              // → NULL


// a y b deben ser iguales
test("hello world", "world", 11);
test("hello world", "world", 5);
test("aaaaa", "aaa", 2);
test("", "", 0);


  

    return 0;
}
