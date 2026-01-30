/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:43:21 by vjamet-s          #+#    #+#             */
/*   Updated: 2026/01/30 13:44:19 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ds;
	const unsigned char	*sr;

	if (!dest && !src)
		return (NULL);
	ds = (unsigned char *)dest;
	sr = (const unsigned char *)src;
	if (sr < ds)
	{
		while (n-- > 0)
			ds[n] = sr[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			ds[i] = sr[i];
			i++;
		}
	}
	return (dest);
}
