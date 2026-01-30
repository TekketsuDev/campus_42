/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:41:19 by vjamet-s          #+#    #+#             */
/*   Updated: 2026/01/30 13:41:45 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	byte;
	const char		*last;

	byte = (unsigned char)c;
	last = NULL;
	while (*s)
	{
		if ((unsigned char)*s == byte)
			last = s;
		s++;
	}
	if (byte == '\0')
		return ((char *)s);
	return ((char *)last);
}
