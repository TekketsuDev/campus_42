#include "libft.h"
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
      while((i + j) < n && sb[j] && s[i + j] == sb[j])
      {
        j++;
        if (sb[j] == '\0')
          return (char *)(s + i);
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
test("hello world", "hello", 11);   // → "hello world"
test("hello world", "world", 11);   // → "world"
test("hello world", "o w", 11);     // → "o world"
test("hello world", "world", 5);    // → NULL
test("abcdef", "def", 5);           // → NULL
test("", "a", 1);                   // → NULL
test("", "", 1);                    // → ""
test("abcd", "cd", 4);              // → "cd"
test("abcd", "cd", 3);              // → NULL
test("aaaaaa", "aaa", 5);            // → "aaaaa"
test("aaaaa", "aaa", 3);            // → "aaaaa"
test("aaaaa", "aaa", 2);            // → NULL
test("Hello", "hello", 5);           // → NULL
test("Hello", "Hell", 5);            // → "Hello"
test("hello", "h", 0);               // → NULL
test("hello", "", 0);                // → "hello"
test("hi", "hello", 5);              // → NULL


// a y b deben ser iguales
test("hello world", "world", 11);
test("hello world", "world", 5);
test("aaaaa", "aaa", 2);
test("", "", 0);


  

    return 0;
}
