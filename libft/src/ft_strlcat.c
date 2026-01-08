//include "libft.a"
#include <stddef.h>

static size_t ft_strnlen(const char *s, size_t maxlen)
{
    size_t i;

    if (!s)
        return 0;

    i = 0;
    while (i < maxlen && s[i] != '\0')
        i++;

    return i;
}

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t dst_len;
    size_t src_len;
    size_t i;

    src_len = ft_strnlen(src, (size_t)-1);

    if (size == 0)
        return src_len;

    dst_len = ft_strnlen(dst, size);

    if (dst_len == size)
        return size + src_len;

    i = 0;
    while (src[i] && (dst_len + i) < (size - 1))
    {
        dst[dst_len + i] = src[i];
        i++;
    }
    dst[dst_len + i] = '\0';

    return dst_len + src_len;
}

