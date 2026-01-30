/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:17:33 by vjamet-s          #+#    #+#             */
/*   Updated: 2026/01/30 13:18:21 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p;
	const unsigned char	*ps;
	size_t				i;

	i = 0;
	p = (const unsigned char *)s1;
	ps = (const unsigned char *)s2;
	while (i < n)
	{
		if (p[i] != ps[i])
			return ((int)p[i] - (int)ps[i]);
		i++;
	}
	return (0);
}
