/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:15:31 by vjamet-s          #+#    #+#             */
/*   Updated: 2026/01/30 13:17:20 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	byte;
	size_t			i;

	i = 0;
	byte = (unsigned char)c;
	p = (unsigned char *)s;
	while (i < n)
	{
		if (p[i] == byte)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}
