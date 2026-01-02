#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define C_RESET "\033[0m"
#define C_OK    "\033[32m"
#define C_KO    "\033[31m"
#define C_INFO  "\033[36m"

static int g_tests = 0;
static int g_passed = 0;

/* ───── 8bit UI ───── */

static void banner(const char *name)
{
    printf(C_INFO "\n==[ %s ]========================\n" C_RESET, name);
}

static void ok(void)
{
    printf(C_OK "  [OK]\n" C_RESET);
}

static void ko(long exp, long got)
{
    printf(C_KO "  [!!] expected %ld got %ld\n" C_RESET, exp, got);
}

/* ───── Assertions ───── */

#define ASSERT_EQ(exp, got)                 \
    do {                                    \
        g_tests++;                          \
        if ((exp) == (got)) {               \
            g_passed++;                     \
            ok();                           \
        } else {                            \
            ko((long)(exp), (long)(got));   \
        }                                   \
    } while (0)

/* ───── libft prototypes ───── */
size_t ft_strlen(const char *s);

/* ───── Tests ───── */

static void test_ft_strlen(void)
{
    banner("ft_strlen");

    ASSERT_EQ(0, ft_strlen(""));
    ASSERT_EQ(5, ft_strlen("hello"));
    ASSERT_EQ(2, ft_strlen("42"));
    ASSERT_EQ(0, ft_strlen(NULL));
}

int main(void)
{
    printf(C_INFO "==[ 8BIT TEST RUNNER ]===========\n" C_RESET);

    test_ft_strlen();

    printf(C_INFO "\n==[ RESULT ]====================\n" C_RESET);
    printf("Passed: %d / %d\n", g_passed, g_tests);

    if (g_passed != g_tests)
        return 1;
    return 0;
}

