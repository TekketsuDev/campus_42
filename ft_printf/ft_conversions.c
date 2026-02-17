/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjamet-s <vjamet-s@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 20:16:42 by vjamet-s          #+#    #+#             */
/*   Updated: 2026/02/16 20:22:46 by vjamet-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_put_s(char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	len = 0;
	while (s[len])
		len++;
	return (write(1, s, len));
}

int	ft_put_int(int n)
{
	long	nb;
	int		count;

	nb = (long)n;
	count = 0;
	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = -nb;
	}
	if (nb == 0)
		return (count + write(1, "0", 1));
	return (count + put_base_rec((unsigned long)nb, "0123456789"));
}

int	ft_put_u(unsigned int n)
{
	if (n == 0)
		return (write(1, "0", 1));
	return (put_base_rec((unsigned long)n, "0123456789"));
}

int	ft_put_p(void *p)
{
	unsigned long	addr;
	int				count;

	if (!p)
		return (write(1, "(nil)", 5));
	addr = (unsigned long)p;
	count = write(1, "0x", 2);
	return (count + put_base_rec(addr, "0123456789abcdef"));
}

int	ft_put_hex(unsigned int n, int upper)
{
	if (upper)
		return (put_base_rec((unsigned long)n, "0123456789ABCDEF"));
	return (put_base_rec((unsigned long)n, "0123456789abcdef"));
}
