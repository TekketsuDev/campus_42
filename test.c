#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- COLORS ---------- */
#define C_RESET "\033[0m"
#define C_OK    "\033[32m"
#define C_KO    "\033[31m"
#define C_INFO  "\033[36m"

/* ---------- GLOBALS ---------- */
static int g_tests = 0;
static int g_passed = 0;

/* ---------- 8BIT UI --------- */
static void banner(const char *name)
{
    printf(C_INFO "\n==[ %s ]========================\n" C_RESET, name);
}

static void print_ok(void)
{
    printf(C_OK "  [OK]\n" C_RESET);
}

static void print_ko(long exp, long got)
{
    printf(C_KO "  [!!] expected %ld got %ld\n" C_RESET, exp, got);
}

/* ---------- ASSERT ---------- */
#define ASSERT_EQ(exp, got)                 \
    do {                                    \
        g_tests++;                          \
        if ((exp) == (got)) {               \
            g_passed++;                     \
            print_ok();                     \
        } else {                            \
            print_ko((long)(exp), (long)(got)); \
        }                                   \
    } while (0)

/* ---------- PROTOTYPES ---------- */
size_t      ft_strlen(const char *s);
int         ft_isalpha(int c);
char*       ft_strdup(const char *s);
void*       ft_memset(void *s, int c, size_t n);
#ifdef  TEST_STRLCAT
static      void fill(char *b, size_t n, char c);
static      int  streq(const char *a, const char *b);   
#endif

size_t      ft_strlcat(char *dst, const char *src, size_t size);
char        *ft_strrchr(const char *s, int c);
int         ft_strncmp(const char *s1, char *s2, size_t n);
void        *ft_memchr(const void *s, int c, size_t n);
int         ft_memcmp(const void *s1, const void *s2, size_t n);
/* ---------- TESTS ---------- */

#ifdef TEST_MEMCMP
static void test_ft_memcmp(void)
{
  banner("ft_memchr");
  {
        const char a[] = "abcdef";
        const char b[] = "abcdef";
        ASSERT_EQ(
            memcmp(a, b, sizeof(a)),
            ft_memcmp(a, b, sizeof(a))
        );
    }
    {
        const char a[] = "abcXef";
        const char b[] = "abcYef";
        ASSERT_EQ(
            memcmp(a, b, sizeof(a)),
            ft_memcmp(a, b, sizeof(a))
        );
    }
    {
        const char a[] = "xbcdef";
        const char b[] = "abcdef";
        ASSERT_EQ(
            memcmp(a, b, sizeof(a)),
            ft_memcmp(a, b, sizeof(a))
        );
    }
    {
        const char a[] = "abcdeX";
        const char b[] = "abcdeY";
        ASSERT_EQ(
            memcmp(a, b, sizeof(a)),
            ft_memcmp(a, b, sizeof(a))
        );
    }
    {
        const char a[] = "abc";
        const char b[] = "xyz";
        ASSERT_EQ(
            memcmp(a, b, 0),
            ft_memcmp(a, b, 0)
        );
    }
    {
        const char a[] = "abcX";
        const char b[] = "abcY";
        ASSERT_EQ(
            memcmp(a, b, 3),
            ft_memcmp(a, b, 3)
        );
    }
    {
        unsigned char a[] = { 'a', 0, 'b', 'c' };
        unsigned char b[] = { 'a', 0, 'x', 'c' };
        ASSERT_EQ(
            memcmp(a, b, sizeof(a)),
            ft_memcmp(a, b, sizeof(a))
        );
    }
    {
        unsigned char a[] = { 0x10, 0x20, 0x30 };
        unsigned char b[] = { 0x10, 0x20, 0x40 };
        ASSERT_EQ(
            memcmp(a, b, sizeof(a)),
            ft_memcmp(a, b, sizeof(a))
        );
    }
    {
        unsigned char a[] = { 0xFF, 0x00 };
        unsigned char b[] = { 0x01, 0x00 };
        ASSERT_EQ(
            memcmp(a, b, sizeof(a)),
            ft_memcmp(a, b, sizeof(a))
        );
    }
    {
        unsigned char a[] = { 1, 2, 3, 2, 1 };
        unsigned char b[] = { 1, 2, 4, 2, 1 };
        ASSERT_EQ(
            memcmp(a, b, sizeof(a)),
            ft_memcmp(a, b, sizeof(a))
        );
    }
}
#endif

#ifdef TEST_MEMCHR
static void test_ft_memchr(void)
{
  banner("ft_memchr");
    {
        const char s[] = "hello world";
        ASSERT_EQ(
            (long)memchr(s, 'o', sizeof(s)),
            (long)ft_memchr(s, 'o', sizeof(s))
        );
    }
    {
        const char s[] = "hello";
        ASSERT_EQ(
            (long)memchr(s, 'z', sizeof(s)),
            (long)ft_memchr(s, 'z', sizeof(s))
        );
    }
    {
        const char s[] = "abc";
        ASSERT_EQ(
            (long)memchr(s, 'a', 0),
            (long)ft_memchr(s, 'a', 0)
        );
    }
    {
        const char s[] = "abc";
        ASSERT_EQ(
            (long)memchr(s, '\0', sizeof(s)),
            (long)ft_memchr(s, '\0', sizeof(s))
        );
    }
    {
        unsigned char b[] = { 0x10, 0x00, 0x20, 0x00, 0x30 };
        ASSERT_EQ(
            (long)memchr(b, 0x00, sizeof(b)),
            (long)ft_memchr(b, 0x00, sizeof(b))
        );
    }
    {
        unsigned char b[] = { 0x01, 0xFF, 0x02 };
        ASSERT_EQ(
            (long)memchr(b, 0xFF, sizeof(b)),
            (long)ft_memchr(b, 0xFF, sizeof(b))
        );
    }
    {
        const char s[] = "abcd";
        ASSERT_EQ(
            (long)memchr(s, 'd', 3),
            (long)ft_memchr(s, 'd', 3)
        );
    }
    {
        const char s[] = "xyz";
        ASSERT_EQ(
            (long)memchr(s, 'x', sizeof(s)),
            (long)ft_memchr(s, 'x', sizeof(s))
        );
    }
}
#endif

#ifdef TEST_STRNCMP
static void test_ft_strncmp(void)
{
  banner("ft_strncmp");
   ASSERT_EQ(
        strncmp("abc", "abc", 3),
        ft_strncmp("abc", "abc", 3)
    );

    ASSERT_EQ(
        strncmp("abcd", "abce", 4),
        ft_strncmp("abcd", "abce", 4)
    );

    ASSERT_EQ(
        strncmp("abcd", "abc", 4),
        ft_strncmp("abcd", "abc", 4)
    );

    ASSERT_EQ(
        strncmp("abc", "abcd", 4),
        ft_strncmp("abc", "abcd", 4)
    );

    ASSERT_EQ(
        strncmp("abc", "xyz", 0),
        ft_strncmp("abc", "xyz", 0)
    );

    ASSERT_EQ(
        strncmp("", "abc", 3),
        ft_strncmp("", "abc", 3)
    );

    ASSERT_EQ(
        strncmp("", "", 5),
        ft_strncmp("", "", 5)
    );

    ASSERT_EQ(
        strncmp("abcX", "abcY", 3),
        ft_strncmp("abcX", "abcY", 3)
    );

    ASSERT_EQ(
        strncmp("abc", "abc", 100),
        ft_strncmp("abc", "abc", 100)
    );

    {
        char a[] = { (char)0xFF, 0 };
        char b[] = { (char)0x01, 0 };
        ASSERT_EQ(
            strncmp(a, b, 1),
            ft_strncmp(a, b, 1)
        );
    }
}
#endif

#ifdef TEST_STRRCHR

static void test_ft_strrchr(void)
{
  banner("ft_strrchr");
    {
        const char *s = "hello world";
        ASSERT_EQ((long)strrchr(s, 'l'), (long)ft_strrchr(s, 'l'));
    }
    {
        const char *s = "abcdef";
        ASSERT_EQ((long)NULL, (long)ft_strrchr(s, 'x'));
    }
    {
        const char *s = "abc";
        ASSERT_EQ((long)&s[0], (long)ft_strrchr(s, 'a'));
    }
    {
        const char *s = "abc";
        ASSERT_EQ((long)&s[2], (long)ft_strrchr(s, 'c'));
    }
    {
        const char *s = "";
        ASSERT_EQ((long)NULL, (long)ft_strrchr(s, 'a'));
    }
    {
        const char *s = "abc";
        ASSERT_EQ((long)(s + 3), (long)ft_strrchr(s, '\0'));
    }
    {
        const char *s = "a";
        ASSERT_EQ((long)&s[0], (long)ft_strrchr(s, 'a'));
    }
    {
        const char *s = "a";
        ASSERT_EQ((long)NULL, (long)ft_strrchr(s, 'b'));
    }
    {
        const char *s = "abc";
        ASSERT_EQ((long)&s[1], (long)ft_strrchr(s, 256 + 'b'));
    }
    {
        char s[] = { (char)0xFF, 'a', (char)0xFF, '\0' };
        ASSERT_EQ((long)&s[2], (long)ft_strrchr(s, 0xFF));
    }
    {
        ASSERT_EQ((long)NULL, (long)ft_strrchr(NULL, 'a'));
    }
}
#endif

#ifdef TEST_STRLEN
static void test_ft_strlen(void)
{
    banner("ft_strlen");

    ASSERT_EQ(0, ft_strlen(""));
    ASSERT_EQ(5, ft_strlen("hello"));
    ASSERT_EQ(0, ft_strlen(NULL));
}
#endif

#ifdef TEST_ISALPHA
static void test_ft_isalpha(void)
{
    banner("ft_isalpha");

    ASSERT_EQ(1, ft_isalpha('a'));
    ASSERT_EQ(0, ft_isalpha('1'));
}
#endif

#ifdef TEST_STRDUP
static void test_ft_strdup(void)
{
    banner("ft_strdup");

    char *d = ft_strdup("test");
    ASSERT_EQ(4, strlen(d));
    free(d);
}
#endif

#ifdef TEST_MEMSET
static void test_ft_memset(void)
{
    banner("ft_memset");

    char buffer[10];

    ft_memset(buffer, 'A', 5);

    ASSERT_EQ('A', buffer[0]);
    ASSERT_EQ('A', buffer[4]);
    ASSERT_EQ(0, buffer[5] == 'A');
}
#endif

#ifdef TEST_STRLCAT
  static void test_ft_strlcat(void)
{
  banner("ft_strlcat (expected)");

  /* Case 1: normal append, enough space */
  {
    char dst[16];
    fill(dst, sizeof(dst), 'X');
    strcpy(dst, "Hello");
    size_t r = ft_strlcat(dst, "42", sizeof(dst));
    ASSERT_EQ((long)7, (long)r);              /* "Hello" (5) + "42" (2) */
    ASSERT_EQ(1, streq(dst, "Hello42"));
  }

  /* Case 2: truncation happens */
  {
    char dst[10];
    fill(dst, sizeof(dst), 'X');
    strcpy(dst, "Hello");                      /* len=5 */
    size_t r = ft_strlcat(dst, "World", sizeof(dst)); /* size=10, space for 4 chars + '\0' */
    ASSERT_EQ((long)10, (long)r);              /* 5 + 5 = 10 always returned */
    ASSERT_EQ(1, streq(dst, "HelloWorl"));     /* "Hello" + 4 chars */
  }

  /* Case 3: size == 0 (cannot write) */
  {
    char dst[6] = "Hello";
    size_t r = ft_strlcat(dst, "X", 0);
    ASSERT_EQ((long)1, (long)r);               /* size(0) + src_len(1) */
    ASSERT_EQ(1, streq(dst, "Hello"));         /* unchanged */
  }

  /* Case 4: size <= dst_len (cannot append, return size + src_len) */
  {
    char dst[6] = "Hello";                     /* dst_len=5 */
    size_t r = ft_strlcat(dst, "ZZ", 3);        /* size=3 <= 5 */
    ASSERT_EQ((long)5, (long)r);               /* size(3) + src_len(2) = 5 */
    ASSERT_EQ(1, streq(dst, "Hello"));         /* unchanged/truncated rules: still same because no room */
  }

  /* Case 5: empty src */
  {
    char dst[8] = "Hi";
    size_t r = ft_strlcat(dst, "", sizeof(dst));
    ASSERT_EQ((long)2, (long)r);
    ASSERT_EQ(1, streq(dst, "Hi"));
  }

  /* Case 6: empty dst */
  {
    char dst[8] = "";
    size_t r = ft_strlcat(dst, "abc", sizeof(dst));
    ASSERT_EQ((long)3, (long)r);
    ASSERT_EQ(1, streq(dst, "abc"));
  }
}

#endif
  /* ---------- HELPERS ---------- */
#ifdef TEST_STRLCAT

static void fill(char *b, size_t n, char c)
{
    size_t i = 0;
    while (i < n)
        b[i++] = c;
}

static int streq(const char *a, const char *b)
{
    if (!a || !b)
        return 0;
    return strcmp(a, b) == 0;
}

#endif


int main(void)
{
  banner("42 TEST RUNNER");

#ifdef TEST_STRRCHR
    test_ft_strrchr();
#endif

#ifdef TEST_STRLEN
    test_ft_strlen();
#endif

#ifdef TEST_ISALPHA
    test_ft_isalpha();
#endif

#ifdef TEST_STRDUP
    test_ft_strdup();
#endif

#ifdef TEST_MEMSET
    test_ft_memset();
#endif

#ifdef TEST_STRLCAT
    test_ft_strlcat();
#endif
  
#ifdef TEST_STRNCMP
    test_ft_strncmp();
#endif

#ifdef TEST_MEMCHR
    test_ft_memchr();
#endif

#ifdef TEST_MEMCMP
    test_ft_memcmp();
#endif



    banner("RESULT");

    printf("Passed: %d / %d\n", g_passed, g_tests);

    return (g_passed == g_tests) ? 0 : 1;
}

