
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*z;

	i = 0;
	z = (unsigned char *)s;
	while (i < n)
	{
		z[i] = 0;
		i++;
	}
}
